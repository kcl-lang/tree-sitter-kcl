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
      $.import_definition
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
    )

  }
});
