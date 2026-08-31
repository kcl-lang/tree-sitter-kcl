// Normal Tokens
const NORMAL_TOKENS = {
  ASSIGN: "=",
  COLON: ":",
  SEMI_COLON: ";",
  COMMA: ",",
  QUESTION: "?",
  ELLIPSIS: "...",
  RIGHT_ARROW: "->",
  LEFT_PARENTHESES: "(",
  RIGHT_PARENTHESES: ")",
  LEFT_BRACKETS: "[",
  RIGHT_BRACKETS: "]",
  LEFT_BRACE: "{",
  RIGHT_BRACE: "}",
  PLUS: "+",
  MINUS: "-",
  MULTIPLY: "*",
  DIVIDE: "/",
  MOD: "%",
  DOT: ".",
  AND: "&",
  OR: "|",
  XOR: "^",
  NOT: "~",
  LESS_THAN: "<",
  GREATER_THAN: ">",
  EQUAL_TO: "==",
  NOT_EQUAL_TO: "!=",
  GREATER_THAN_OR_EQUAL_TO: ">=",
  LESS_THAN_OR_EQUAL_TO: "<=",
  DOUBLE_STAR: "**",
  DOUBLE_DIVIDE: "//",
  SHIFT_LEFT: "<<",
  SHIFT_RIGHT: ">>",
  AT: "@",

  COMP_PLUS: "+=",
  COMP_MINUS: "-=",
  COMP_MULTIPLY: "*=",
  COMP_DIVIDE: "/=",
  COMP_MOD: "%=",
  COMP_AND: "&=",
  COMP_OR: "|=",
  COMP_XOR: "^=",
  COMP_DOUBLE_STAR: "**=",
  COMP_DOUBLE_DIVIDE: "//=",
  COMP_SHIFT_LEFT: "<<=",
  COMP_SHIFT_RIGHT: ">>=",
}

// Keywords
const KEYWORDS = {
  IMPORT: "import",
  AS: "as",
  RULE: "rule",
  SCHEMA: "schema",
  MIXIN: "mixin",
  PROTOCOL: "protocol",
  CHECK: "check",
  FOR: "for",
  ASSERT: "assert",
  IF: "if",
  ELIF: "elif",
  ELSE: "else",
  L_OR: "or",
  L_AND: "and",
  L_NOT: "not",
  IN: "in",
  IS: "is",
  LAMBDA: "lambda",
  ALL: "all",
  ANY: "any",
  FILTER: "filter",
  MAP: "map",
  TYPE: "type",
}

const RESERVED_KEYWORDS = {
  PASS: "pass",
  RETURN: "return",
  VALIDATE: "validate",
  RULE: "rule",
  DEF: "def",
  FLOW: "flow",
  DEL: "del",
  RAISE: "raise",
  FROM: "from",
  GLOBAL: "global",
  NONLOCAL: "nonlocal",
  EXCEPT: "except",
  FINALLY: "finally",
  WITH: "with",
  TRY: "try",
  WHILE: "while",
  YEILD: "yield",
  STRUCT: "struct",
  CLASS: "class",
  FINAL: "final",
}

const TYPES = {
  ANY: "any",
  STRING: "str",
  INT: "int",
  FLOAT: "float",
  BOOL: "bool",
}

// Number suffix
const NUMBER_SUFFIX = {
  n: "n",
  u: "u",
  m: "m",
  k: "k",
  K: "K",
  M: "M",
  G: "G",
  T: "T",
  P: "P",
  Ki: "Ki",
  Mi: "Mi",
  Gi: "Gi",
  Ti: "Ti",
  Pi: "Pi",
}
const NAME_CONSTANTS = {
  TRUE: "True",
  FALSE: "False",
  NONE: "None",
  UNDEFINED: "Undefined",
}
const PREC = {
  typed_parameter: -3,
  call: -2,        // suffix: (), [], .
  conditional: -1,  // test1 if cond else test2
  or: 8,   // or
  and: 9,  // and
  equals: 10,   // ==, !=
  in_or_not_in: 11,  // in, not int
  is_or_is_not: 12,  // is, is not
  less_greater: 13,  // >, <, >=, <=
  bit_or: 14,  // |
  bit_xor: 15, // ^
  bit_and: 16, // &
  shift: 17,       // << >>
  plus: 18,        // +, -
  times: 19,       // *, /, %, //
  power: 20,       // **
  prefix: 21,       // prefix: -, +, ~, not
  as: 23,
};

const SEMICOLON = ';';
const DOT = '.';
const IMPORT = 'import';

module.exports = grammar({
  name: 'kcl',

  extras: $ => [
    $.comment,
    /[\s\f\uFEFF\u2060\u200B]|\r?\n/,
    $.line_continuation,
  ],

  supertypes: $ => [
    $._simple_stmt,
    $._compound_stmt,
    $._expr,
    $.primary_expr,
    $.parameter,
  ],

  externals: $ => [
    $._newline,
    $._indent,
    $._dedent,
    $.string_start,
    $._string_content,
    '${',
    $.string_end,

    // Mark comments as external tokens so that the external scanner is always
    // invoked, even if no external token is expected. This allows for better
    // error recovery, because the external scanner can maintain the overall
    // structure by returning dedent tokens whenever a dedent occurs, even
    // if no dedent is expected.
    $.comment,

    // Allow the external scanner to check for the validity of closing brackets
    // so that it can avoid returning dedent tokens between brackets.
    ']',
    ')',
    '}',
  ],

  inline: $ => [
    $._simple_stmt,
    $._compound_stmt,
    $._suite,
  ],

  word: $ => $.identifier,

  rules: {
    module: $ => repeat($._stmt),

    _stmt: $ => choice(
      $._simple_stmts,
      $._compound_stmt,
    ),

    // Simple statements

    _simple_stmts: $ => prec(24, seq(
      $._simple_stmt,
      $._newline,
    )),

    _simple_stmt: $ => choice(
      $._expr,
      $.assign_stmt,
      $.aug_assign_stmt,
      $.unification_stmt,
      $.assert_stmt,
      $.import_stmt,      // Only valid on the top level block
      $.type_alias_stmt,  // Only valid on the top level block
    ),

    import_stmt: $ => seq(
      'import',
      $._import_list,
    ),

    import_prefix: _ => repeat1('.'),

    _import_list: $ => seq(
      optional($.import_prefix),
      field('name', choice(
        $.dotted_name,
        $._aliased_import,
      )),
    ),

    _aliased_import: $ => seq(
      field('name', $.dotted_name),
      'as',
      field('alias', $.identifier),
    ),

    assert_stmt: $ => prec(3, seq(
      'assert',
      $._simple_expr,
      optional(seq('if', $._simple_expr)),
      optional(seq(',', $._expr))
    )),

    // Compound statements

    _compound_stmt: $ => choice(
      $.if_stmt,
      $.schema_stmt,
      $.rule_stmt,
      $.mixin_stmt,
      $.protocol_stmt,
      $.decorators,
      $.schema_index_signature,  // Only valid in the schema_stmt
      $.check_stmt,  // Only valid in the schema_stmt
    ),

    if_stmt: $ => choice(
      seq(
        'if',
        field('condition', $._expr),
        ':',
        field('consequence', $._suite),
        repeat(field('alternative', $.elif_clause)),
        optional(field('alternative', $.else_clause)),
      ),
      seq(
        field('condition', $._expr),
        ',',
        field('error_message', $.string),
      ),
      $.if_expr,
      seq(
        field('expr1', $._expr),
        'if',
        field('condition', $._expr),
      )
    ),

    rule_stmt: $ => prec.left(seq(
      'rule',
      field('name', $.parameter),
      optional(seq(
        '(',
        commaSep1(field('base', $.identifier)),
        optional(','),
        ')'
      )),
      optional(seq(
        'for',
        field('protocol', $.identifier),
      )),
      ':',
      field('body', $._suite),
    )),

    parameter_list: $ => seq(
      $.identifier,
      repeat(seq(
        ',',
        $.identifier
      ))
    ),

    elif_clause: $ => seq(
      'elif',
      field('condition', $._expr),
      ':',
      field('consequence', $._suite),
    ),

    else_clause: $ => seq(
      'else',
      ':',
      field('body', $._suite),
    ),

    schema_expr: $ => seq(
      field('operand_name', $.identifier),
      optional(seq(
        '(',
        optional($.argument_list),
        ')'
      )),
      $.config_expr,
    ),

    schema_instantiation: $ => seq(
      field('constructor', $.call_expr),
      field('initialization', $.config_expr)
    ),

    schema_index_signature: $ => seq(
      '[',
      optional(seq(
        field('attr_alias', $.identifier),
        ':'
      )),
      optional('...'),
      field('key_type', $.basic_type),
      ']',
      ':',
      field('value_type', $.type),
      optional(seq(
        '=',
        field('default', $._expr)
      )),
      $._newline
    ),

    _multiline_lambda_signature: $ => seq(
      '{',
      optional($._newline),
      $._multiline_parameters,
      '}',
      '->',
      field('return_type', $.type),
    ),

    _lambda_signature: $ => choice(
      seq(
        field('parameters', $._parameters),
        optional(
          seq(
            '->',
            field('return_type', $.type),
          ),
        )
      ),
      $._multiline_lambda_signature
    ),

    lambda_expr: $ => prec(PREC.call, seq(
      'lambda',
      $._lambda_signature,
      '{',
      field('body', $._suite),
      '}',
    )),

    quant_expr: $ => prec.left(seq(
      field('quant_op', $.quant_op),
      optional(seq(
        field('identifier', $.identifier),
        ','
      )),
      field('identifier', $.identifier),
      'in',
      field('quant_target', $.quant_target),
      '{',
      $._simple_expr,
      optional(seq(
        'if',
        field('expr2', $._expr)
      )),
      '}'
    )),

    quant_target: $ => prec(1, choice(
      $.subscript_expr,
      $.call_expr,
      field('config_or_list', $.identifier),
      $.string,
      $.list_expr,
      $.list_comprehension,
      $.config_expr,
      $.config_comprehension,
      seq(
        '[',
        field('integer', $.integer),
        repeat(seq(
          ',',
          field('integer', $.integer)
        )),
        ']'
      )
    )),

    quant_op: $ => choice(
      'all',
      'any',
      'filter',
      'map'
    ),

    parameters: $ => seq(
      '(',
      optional($._parameters),
      ')',
    ),

    list_splat: $ => seq(
      '*',
      $._expr,
    ),

    config_splat: $ => seq(
      '**',
      $._expr,
    ),

    type_alias_stmt: $ => prec.dynamic(1, seq(
      'type',
      $.type,
      '=',
      $.type,
    )),

    schema_stmt: $ => prec.left(seq(
      'schema',
      field('name', $.parameter),
      optional(seq(
        '(',
        field('base', $.identifier),
        ')'
      )),
      optional(seq(
        'for',
        field('protocol', $.identifier),
      )),
      ':',
      field('body', $._suite),
    )),

    mixin_stmt: $ => seq(
      'mixin',
      field('name', $.primary_expr),
      optional(seq('for',
        field('protocol', $.identifier),
        ':',
        field('body', $._suite),
      ))),

    protocol_stmt: $ => seq(
      'protocol',
      field('name', $.identifier),
      ':',
      field('body', $._suite),
    ),

    check_stmt: $ => prec.left(seq(
      'check',
      ':',
      repeat1(seq(
        field('expr1', $._expr),
        optional(seq(
          ',',
          field('error_message', $.string),
        )),
      ),)
    )),

    // Arguments

    argument_list: $ => seq(
      '(',
      optional(commaSep1(
        choice(
          $._expr,
          $.keyword_argument,
        ),
      )),
      optional(','),
      ')',
    ),

    keyword_argument: $ => seq(
      field('name', $.identifier),
      '=',
      field('value', $._expr),
    ),

    decorators: $ => seq(
      repeat1($.decorator),
      field('definition', choice(
        $.schema_stmt,
        $.mixin_stmt,
        $.rule_stmt,
        $.protocol_stmt,
      )),
    ),

    decorator: $ => seq(
      '@',
      $.identifier,
      optional($.argument_list),
      $._newline,
    ),

    _suite: $ => choice(
      alias($._simple_stmts, $.block),
      seq($._indent, $.block),
      seq($.assign_stmt, $._newline),
      seq($.comparison_expr, $._newline),
      alias($._newline, $.block),
    ),

    block: $ => seq(
      repeat($._stmt),
      $._dedent,
    ),

    dotted_name: $ => prec.left(1, sep1($.identifier, choice('?.', '.',))),

    // Patterns

    _multiline_parameters: $ => seq(
      sep1($.parameter, seq(',', optional($._newline))),
      optional(','),
    ),

    _parameters: $ => seq(
      commaSep1($.parameter),
      optional(','),
    ),

    parameter: $ => choice(
      $.identifier,
      $.typed_parameter,
      $.default_parameter,
      $.typed_default_parameter,
    ),

    default_parameter: $ => seq(
      field('name', $.identifier),
      '=',
      field('value', $._expr),
    ),

    typed_default_parameter: $ => prec(PREC.typed_parameter, seq(
      field('name', $.identifier),
      ':',
      field('type', $.type),
      '=',
      field('value', $._expr),
    )),

    // Expressions

    _expr: $ => prec(1, choice(
      $.if_expr,
      $._simple_expr,
    )),

    _simple_expr: $ => prec(1, choice(
      $.binary_expr,
      $.comparison_expr,
      $.logic_expr,
      $.primary_expr,
      $.as_expr,
    )),

    as_expr: $ => prec.left(PREC.as, seq(
      $._simple_expr,
      'as',
      field('alias', $._simple_expr),
    )),

    selector_expr: $ => prec.left(PREC.call, seq(
      $.primary_expr,
      $.select_suffix,
    )),

    primary_expr: $ => prec.left(2, choice(
      $.identifier,
      $.string,
      $.integer,
      $.float,
      $.true,
      $.false,
      $.none,
      $.undefined,
      $.unary_expr,
      $.list_expr,
      $.list_comprehension,
      $.config_expr,
      $.config_comprehension,
      $.lambda_expr,
      $.quant_expr,
      $.schema_expr,
      $.schema_instantiation,
      $.paren_expr,
      $.optional_attribute_declaration, // Only valid in the schema stmt
      $.string_literal_expr,
      $.selector_expr,
      $.subscript_expr,
      $.call_expr,
    )),

    paren_expr: $ => seq(
      '(', $._expr, ')'
    ),

    logic_expr: $ => choice(
      prec.left(PREC.and, seq(
        field('left', $._expr),
        field('operator', 'and'),
        field('right', $._expr),
      )),
      prec.left(PREC.or, seq(
        field('left', $._expr),
        field('operator', 'or'),
        field('right', $._expr),
      )),
    ),

    string_literal_expr: $ => seq(
      '"',
      /[^"]*/,
      '"'
    ),

    config_expr: $ => seq(
      '{',
      optional(choice(
        $.config_entries,
        seq(
          '\n',
          optional($.config_entries)
        )
      )),
      '}'
    ),

    config_entries: $ => seq(
      $.config_entry,
      repeat(seq(
        choice(
          ',',
          seq(
            optional(','),
            '\n'
          )
        ),
        $.config_entry
      )),
      optional(','),
      optional('\n')
    ),

    config_entry: $ => choice(
      seq(
        $._expr,
        field('operator', choice(':', '=', '+=')),
        $._expr
      ),
      $.config_splat,
      $.if_entry,
      $.config_shorthand
    ),

    // ES6-style shorthand: a bare identifier entry stands for `key = key`
    // (https://github.com/kcl-lang/kcl/issues/1275). Only single-segment
    // identifiers are allowed; dotted keys like `{a.b}` remain a parse
    // error so key-flattening keeps its current semantics.
    config_shorthand: $ => field('name', $.identifier),

    dotted_identifier: $ => prec(4, seq(
      $.identifier,
      repeat(seq('.', $.identifier))
    )),

    double_star_expr: $ => seq(
      '**',
      $._expr
    ),

    if_entry: $ => seq(
      'if',
      field('condition', $._expr),
      ':',
      '\n',
      $._indent,
      $.config_entries,
      $._dedent,
      optional(seq('elif', $._expr, ':', '\n', $._indent, $.config_entries, $._dedent)),
      optional(seq('else', ':', '\n', $._indent, $.config_entries, $._dedent)),
    ),

    binary_expr: $ => {
      const table = [
        [prec.left, '+', PREC.plus],
        [prec.left, '-', PREC.plus],
        [prec.left, '*', PREC.times],
        [prec.left, '/', PREC.times],
        [prec.left, '%', PREC.times],
        [prec.left, '//', PREC.times],
        [prec.right, '**', PREC.power],
        [prec.left, '|', PREC.bit_or],
        [prec.left, '&', PREC.bit_and],
        [prec.left, '^', PREC.bit_xor],
        [prec.left, '<<', PREC.shift],
        [prec.left, '>>', PREC.shift],
      ];

      // @ts-ignore
      return prec(13, choice(...table.map(([fn, operator, precedence]) => fn(precedence, seq(
        field('left', $._simple_expr),
        // @ts-ignore
        field('operator', operator),
        field('right', $._simple_expr),
      )))));
    },

    unary_expr: $ => prec(PREC.prefix, seq(
      field('operator', choice('+', '-', '~', 'not')),
      field('argument', $._simple_expr),
    )),

    comparison_expr: $ => prec.left(2, seq(
      choice($._simple_expr),
      repeat1(seq(
        field('operators',
          choice(
            '<',
            '<=',
            '==',
            '!=',
            '>=',
            '>',
            'in',
            alias(seq('not', 'in'), 'not in'),
            'is',
            alias(seq('is', 'not'), 'is not'),
            'and',
            'or',
          )),
        $.primary_expr,
      )),
    )),

    assign_stmt: $ => seq(
      field('left', $.dotted_name),
      choice(
        seq('=', field('right', $._expr)),
        seq(':', field('type', $.type), '=', field('right', $._expr)),
        alias(seq(':', field('type', $.type)), 'null_assignment'),
      ),
    ),

    aug_assign_stmt: $ => seq(
      field('left', $.dotted_name),
      field('operator', choice(
        '+=', '-=', '*=', '/=', '//=', '%=', '**=',
        '>>=', '<<=', '&=', '^=', '|=',
      )),
      field('right', $._expr),
    ),

    unification_stmt: $ => seq(
      field('left', $.dotted_name),
      ':',
      field('right', $.schema_expr),
    ),

    select_suffix: $ => prec(44, choice(
      seq('.', $.identifier),
      seq('?.', $.identifier)
    )),

    optional_attribute_declaration: $ => prec.right(12, seq(
      field('attribute', $.identifier),
      '?:',
      field('type', $.type),
      optional(seq(
        '=',
        field('default', $._expr)
      ))
    )),

    subscript_expr: $ => prec(PREC.call, seq(
      field('value', $.primary_expr),
      optional('?'),
      '[',
      commaSep1(field('subscript', choice($._expr, $.slice))),
      optional(','),
      ']',
    )),

    slice: $ => seq(
      optional($._expr),
      ':',
      optional($._expr),
      optional(seq(':', optional($._expr))),
    ),

    ellipsis: _ => '...',

    call_expr: $ => prec(PREC.call, seq(
      field('function', $.primary_expr),
      field('arguments', $.argument_list),
    )),

    typed_parameter: $ => prec(PREC.typed_parameter, choice(seq(
      $.identifier,
      ':',
      field('type', $.type),
    ),
      // for schema argument type annotation
      prec.left(seq(
        $.identifier,
        '[',
        $.identifier,
        ':',
        field('type', $.type),
        ']',
      )))),

    // Types

    type: $ => choice(
      $.schema_type,
      $.union_type,
      $.function_type,
      $.basic_type,
      $.list_type,
      $.dict_type,
      $.literal_type,
    ),
    schema_type: $ => $.dotted_name,
    union_type: $ => prec.left(seq($.type, repeat1(prec.left(seq('|', $.type))))),
    function_type: $ => prec.left(seq(
      '(', optional(commaSep1($.type)), ')', optional(seq('->', $.type))
    )),
    basic_type: _ => choice('str', 'int', 'float', 'bool', 'any'),
    list_type: $ => prec.left(seq('[', optional($.type), ']')),
    dict_type: $ => prec.left(seq('{', optional($.type), ':', optional($.type), '}')),
    literal_type: $ => choice($.string, $.float, $.integer, $.true, $.false),

    // Literals

    list_expr: $ => seq(
      '[',
      optional($._collection_elements),
      ']',
    ),

    _pair: $ => seq(
      field('key', $._expr),
      choice(':', '=', '+='),
      field('value', $._expr),
    ),

    list_comprehension: $ => seq(
      '[',
      field('body', $._expr),
      $._comprehension_clauses,
      ']',
    ),

    config_comprehension: $ => seq(
      '{',
      field('body', $._pair),
      $._comprehension_clauses,
      '}',
    ),

    _comprehension_clauses: $ => seq(
      $.for_in_clause,
      repeat(choice(
        $.for_in_clause,
        $.if_clause,
      )),
    ),

    _collection_elements: $ => prec(1, commaSep1(choice(
      $._expr, $.list_splat,
    ))),

    for_in_clause: $ => prec.left(seq(
      'for',
      field('left', $.identifier),
      'in',
      field('right', $._expr),
      optional(','),
    )),

    if_clause: $ => seq(
      'if',
      $._simple_expr,
    ),

    if_expr: $ => prec.left(PREC.conditional + 25, seq(
      $._simple_expr,
      'if',
      $._simple_expr,
      optional('else'),
      optional($._expr),
    )),

    raw_string: $ => prec(64, seq(
      $.raw_string_start,
      repeat($.string_content),
      $.string_end,
    )),

    raw_string_content: $ => prec.right(repeat1(
      choice(
        $._not_escape_sequence,
        $._raw_string_content,
      ))),

    raw_string_start: $ => token(seq(
      choice('r', 'R'),
      '"'
    )),

    _raw_string_content: $ => /[^"]/, // matches any character except "

    string: $ => seq(
      $.string_start,
     repeat(choice($.interpolation, $.string_content)),
      $.string_end,
    ),

    string_content: $ => prec.right(repeat1(
      choice(
        $.escape_sequence,
        $._not_escape_sequence,
        $._string_content,
      ))),

    interpolation: $ => seq(
      '${',
      field('expression', $._simple_expr),
      optional(field("format_spec", $.format_spec)),
      '}',
    ),

    format_spec: $ => seq(
      ':',
      token(prec(1, /[^}\n]+/)),
    ),

    escape_sequence: _ => token.immediate(prec(1, seq(
      '\\',
      choice(
        /u[a-fA-F\d]{4}/,
        /U[a-fA-F\d]{8}/,
        /x[a-fA-F\d]{2}/,
        /\d{3}/,
        /\r?\n/,
        /['"abfrntv\\]/,
        /N\{[^}]+}/,
        /\$/,
      ),
    ))),

    _not_escape_sequence: _ => token.immediate('\\'),

    integer: $ => token(choice(
      seq(
        choice('0x', '0X'),
        repeat1(/_?[A-Fa-f0-9]+/),
      ),
      seq(
        choice('0o', '0O'),
        repeat1(/_?[0-7]+/),
      ),
      seq(
        choice('0b', '0B'),
        repeat1(/_?[0-1]+/),
      ),
      seq(
        repeat1(/[0-9]+_?/),
        field('multiplier', optional(choice(NUMBER_SUFFIX.n, NUMBER_SUFFIX.u, NUMBER_SUFFIX.m, NUMBER_SUFFIX.k, NUMBER_SUFFIX.K, NUMBER_SUFFIX.M, NUMBER_SUFFIX.G, NUMBER_SUFFIX.T, NUMBER_SUFFIX.P, NUMBER_SUFFIX.Ki, NUMBER_SUFFIX.Mi, NUMBER_SUFFIX.Gi, NUMBER_SUFFIX.Ti, NUMBER_SUFFIX.Pi))),
      ),
    )),

    float: _ => {
      const digits = repeat1(/[0-9]+_?/);
      const exponent = seq(/[eE][\+-]?/, digits);

      return token(seq(
        choice(
          seq(digits, '.', optional(digits), optional(exponent)),
          seq(optional(digits), '.', digits, optional(exponent)),
          seq(digits, exponent),
        ),
      ));
    },

    identifier: _ => /[_$a-zA-Z][_$\p{XID_Continue}]*/,

    true: _ => NAME_CONSTANTS.TRUE,
    false: _ => NAME_CONSTANTS.FALSE,
    none: _ => NAME_CONSTANTS.NONE,
    undefined: _ => NAME_CONSTANTS.UNDEFINED,
    multiplier: _ => choice(NUMBER_SUFFIX.n, NUMBER_SUFFIX.u, NUMBER_SUFFIX.m, NUMBER_SUFFIX.k, NUMBER_SUFFIX.K, NUMBER_SUFFIX.M, NUMBER_SUFFIX.G, NUMBER_SUFFIX.T, NUMBER_SUFFIX.P, NUMBER_SUFFIX.Ki, NUMBER_SUFFIX.Mi, NUMBER_SUFFIX.Gi, NUMBER_SUFFIX.Ti, NUMBER_SUFFIX.Pi),

    comment: _ => token(seq('#', /.*/)),

    line_continuation: _ => token(seq('\\', choice(seq(optional('\r'), '\n'), '\0'))),
  },
});

module.exports.PREC = PREC;

/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {RuleOrLiteral} rule
 *
 * @return {SeqRule}
 *
 */
function commaSep1(rule) {
  return sep1(rule, ',');
}

/**
 * Creates a rule to match one or more occurrences of `rule` separated by `sep`
 *
 * @param {RuleOrLiteral} rule
 *
 * @param {RuleOrLiteral} separator
 *
 * @return {SeqRule}
 *
 */
function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}
