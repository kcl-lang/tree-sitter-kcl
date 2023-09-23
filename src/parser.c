#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 21
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 15
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_import = 1,
  sym_identifier = 2,
  anon_sym_DOT = 3,
  anon_sym_as = 4,
  sym_source_file = 5,
  sym__definition = 6,
  sym_simple_definition = 7,
  sym_import_definition = 8,
  sym_leading_dot = 9,
  sym_pkg_name = 10,
  sym_as_name = 11,
  aux_sym_source_file_repeat1 = 12,
  aux_sym_leading_dot_repeat1 = 13,
  aux_sym_pkg_name_repeat1 = 14,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_import] = "import",
  [sym_identifier] = "identifier",
  [anon_sym_DOT] = ".",
  [anon_sym_as] = "as",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_simple_definition] = "simple_definition",
  [sym_import_definition] = "import_definition",
  [sym_leading_dot] = "leading_dot",
  [sym_pkg_name] = "pkg_name",
  [sym_as_name] = "as_name",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_leading_dot_repeat1] = "leading_dot_repeat1",
  [aux_sym_pkg_name_repeat1] = "pkg_name_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_import] = anon_sym_import,
  [sym_identifier] = sym_identifier,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_as] = anon_sym_as,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_simple_definition] = sym_simple_definition,
  [sym_import_definition] = sym_import_definition,
  [sym_leading_dot] = sym_leading_dot,
  [sym_pkg_name] = sym_pkg_name,
  [sym_as_name] = sym_as_name,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_leading_dot_repeat1] = aux_sym_leading_dot_repeat1,
  [aux_sym_pkg_name_repeat1] = aux_sym_pkg_name_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_as] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_simple_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_import_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_leading_dot] = {
    .visible = true,
    .named = true,
  },
  [sym_pkg_name] = {
    .visible = true,
    .named = true,
  },
  [sym_as_name] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_leading_dot_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pkg_name_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(8);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'a') ADVANCE(6);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == 'm') ADVANCE(4);
      END_STATE();
    case 3:
      if (lookahead == 'o') ADVANCE(5);
      END_STATE();
    case 4:
      if (lookahead == 'p') ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == 'r') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 's') ADVANCE(12);
      END_STATE();
    case 7:
      if (lookahead == 't') ADVANCE(9);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_as);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_as] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(17),
    [sym__definition] = STATE(3),
    [sym_simple_definition] = STATE(3),
    [sym_import_definition] = STATE(14),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_import] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(7), 1,
      ts_builtin_sym_end,
    ACTIONS(9), 1,
      anon_sym_import,
    STATE(14), 1,
      sym_import_definition,
    STATE(2), 3,
      sym__definition,
      sym_simple_definition,
      aux_sym_source_file_repeat1,
  [15] = 4,
    ACTIONS(5), 1,
      anon_sym_import,
    ACTIONS(12), 1,
      ts_builtin_sym_end,
    STATE(14), 1,
      sym_import_definition,
    STATE(2), 3,
      sym__definition,
      sym_simple_definition,
      aux_sym_source_file_repeat1,
  [30] = 3,
    ACTIONS(16), 1,
      anon_sym_DOT,
    STATE(6), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(14), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_as,
  [42] = 5,
    ACTIONS(18), 1,
      sym_identifier,
    ACTIONS(20), 1,
      anon_sym_DOT,
    STATE(10), 1,
      sym_pkg_name,
    STATE(12), 1,
      aux_sym_leading_dot_repeat1,
    STATE(18), 1,
      sym_leading_dot,
  [58] = 3,
    ACTIONS(16), 1,
      anon_sym_DOT,
    STATE(8), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(22), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_as,
  [70] = 3,
    ACTIONS(16), 1,
      anon_sym_DOT,
    STATE(9), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(22), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_as,
  [82] = 3,
    ACTIONS(26), 1,
      anon_sym_DOT,
    STATE(8), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(24), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_as,
  [94] = 3,
    ACTIONS(16), 1,
      anon_sym_DOT,
    STATE(8), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(29), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_as,
  [106] = 3,
    ACTIONS(33), 1,
      anon_sym_as,
    STATE(15), 1,
      sym_as_name,
    ACTIONS(31), 2,
      ts_builtin_sym_end,
      anon_sym_import,
  [117] = 1,
    ACTIONS(24), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_DOT,
      anon_sym_as,
  [124] = 3,
    ACTIONS(35), 1,
      sym_identifier,
    ACTIONS(37), 1,
      anon_sym_DOT,
    STATE(13), 1,
      aux_sym_leading_dot_repeat1,
  [134] = 3,
    ACTIONS(39), 1,
      sym_identifier,
    ACTIONS(41), 1,
      anon_sym_DOT,
    STATE(13), 1,
      aux_sym_leading_dot_repeat1,
  [144] = 1,
    ACTIONS(44), 2,
      ts_builtin_sym_end,
      anon_sym_import,
  [149] = 1,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_import,
  [154] = 1,
    ACTIONS(48), 2,
      ts_builtin_sym_end,
      anon_sym_import,
  [159] = 1,
    ACTIONS(50), 1,
      ts_builtin_sym_end,
  [163] = 1,
    ACTIONS(52), 1,
      sym_identifier,
  [167] = 1,
    ACTIONS(54), 1,
      sym_identifier,
  [171] = 1,
    ACTIONS(56), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 15,
  [SMALL_STATE(4)] = 30,
  [SMALL_STATE(5)] = 42,
  [SMALL_STATE(6)] = 58,
  [SMALL_STATE(7)] = 70,
  [SMALL_STATE(8)] = 82,
  [SMALL_STATE(9)] = 94,
  [SMALL_STATE(10)] = 106,
  [SMALL_STATE(11)] = 117,
  [SMALL_STATE(12)] = 124,
  [SMALL_STATE(13)] = 134,
  [SMALL_STATE(14)] = 144,
  [SMALL_STATE(15)] = 149,
  [SMALL_STATE(16)] = 154,
  [SMALL_STATE(17)] = 159,
  [SMALL_STATE(18)] = 163,
  [SMALL_STATE(19)] = 167,
  [SMALL_STATE(20)] = 171,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [9] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [12] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [14] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pkg_name, 1),
  [16] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pkg_name, 2),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pkg_name_repeat1, 2),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pkg_name_repeat1, 2), SHIFT_REPEAT(19),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pkg_name, 3),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_definition, 2),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_leading_dot, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_leading_dot_repeat1, 2),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_leading_dot_repeat1, 2), SHIFT_REPEAT(13),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_definition, 1),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_definition, 3),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_as_name, 2),
  [50] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_kcl(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
