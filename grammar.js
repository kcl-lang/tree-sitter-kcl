const DOT = '.';
const IMPORT = 'import';

module.exports = grammar({
  name: 'kcl',

  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.simple_definition
      // $.compound_definition
    ),

    simple_definition: $ => choice(
      $.import_definition,
      $.assign_definition
    ),

    import_definition: $ => seq(
      IMPORT,
      $.pkg_name,
      optional($.as_name),
    ),

    identifier: _ => /[a-zA-Z][a-zA-Z0-9]*/,
    leading_dot: $ => repeat1(DOT),

    pkg_name: $ => seq(
      optional($.leading_dot),
      $.identifier,
      repeat(seq(DOT, $.identifier))
    ),

    as_name: $ => seq(
      'as',
      $.identifier
    ),

    assign_definition: $ => choice(
      $.assign,
      $.augmented_assign,
    ),

    // TODO(wei): should be typed
    test: _ => /[a-zA-Z0-9."']+/,

    assign: $ => seq(
      choice(
        $.identifier,
        seq(
          $.identifier,
          repeat(seq(DOT, $.identifier)),
        ),
      ),
      '=',
      $.test,
    ),

    augassign: _ => choice("+=",
      "-=",
      "*=",
      "**=",
      "/=",
      "//=",
      "%=",
      "&=",
      "|=",
      "^=",
      "<<=",
      ">>=",
    ),

    augmented_assign: $ => seq(
      choice(
        $.identifier,
        seq(
          $.identifier,
          repeat(seq(DOT, $.identifier)),
        ),
      ),
      $.augassign,
      $.test,
    ),

  }
});
