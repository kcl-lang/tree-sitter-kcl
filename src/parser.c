#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 33
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 33
#define ALIAS_COUNT 0
#define TOKEN_COUNT 19
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_import = 1,
  sym_identifier = 2,
  anon_sym_DOT = 3,
  anon_sym_as = 4,
  sym_test = 5,
  anon_sym_EQ = 6,
  anon_sym_PLUS_EQ = 7,
  anon_sym_DASH_EQ = 8,
  anon_sym_STAR_EQ = 9,
  anon_sym_STAR_STAR_EQ = 10,
  anon_sym_SLASH_EQ = 11,
  anon_sym_SLASH_SLASH_EQ = 12,
  anon_sym_PERCENT_EQ = 13,
  anon_sym_AMP_EQ = 14,
  anon_sym_PIPE_EQ = 15,
  anon_sym_CARET_EQ = 16,
  anon_sym_LT_LT_EQ = 17,
  anon_sym_GT_GT_EQ = 18,
  sym_source_file = 19,
  sym__definition = 20,
  sym_simple_definition = 21,
  sym_import_definition = 22,
  sym_leading_dot = 23,
  sym_pkg_name = 24,
  sym_as_name = 25,
  sym_assign_definition = 26,
  sym_assign = 27,
  sym_augassign = 28,
  sym_augmented_assign = 29,
  aux_sym_source_file_repeat1 = 30,
  aux_sym_leading_dot_repeat1 = 31,
  aux_sym_pkg_name_repeat1 = 32,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_import] = "import",
  [sym_identifier] = "identifier",
  [anon_sym_DOT] = ".",
  [anon_sym_as] = "as",
  [sym_test] = "test",
  [anon_sym_EQ] = "=",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_DASH_EQ] = "-=",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_STAR_STAR_EQ] = "**=",
  [anon_sym_SLASH_EQ] = "/=",
  [anon_sym_SLASH_SLASH_EQ] = "//=",
  [anon_sym_PERCENT_EQ] = "%=",
  [anon_sym_AMP_EQ] = "&=",
  [anon_sym_PIPE_EQ] = "|=",
  [anon_sym_CARET_EQ] = "^=",
  [anon_sym_LT_LT_EQ] = "<<=",
  [anon_sym_GT_GT_EQ] = ">>=",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_simple_definition] = "simple_definition",
  [sym_import_definition] = "import_definition",
  [sym_leading_dot] = "leading_dot",
  [sym_pkg_name] = "pkg_name",
  [sym_as_name] = "as_name",
  [sym_assign_definition] = "assign_definition",
  [sym_assign] = "assign",
  [sym_augassign] = "augassign",
  [sym_augmented_assign] = "augmented_assign",
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
  [sym_test] = sym_test,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_PLUS_EQ] = anon_sym_PLUS_EQ,
  [anon_sym_DASH_EQ] = anon_sym_DASH_EQ,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_STAR_STAR_EQ] = anon_sym_STAR_STAR_EQ,
  [anon_sym_SLASH_EQ] = anon_sym_SLASH_EQ,
  [anon_sym_SLASH_SLASH_EQ] = anon_sym_SLASH_SLASH_EQ,
  [anon_sym_PERCENT_EQ] = anon_sym_PERCENT_EQ,
  [anon_sym_AMP_EQ] = anon_sym_AMP_EQ,
  [anon_sym_PIPE_EQ] = anon_sym_PIPE_EQ,
  [anon_sym_CARET_EQ] = anon_sym_CARET_EQ,
  [anon_sym_LT_LT_EQ] = anon_sym_LT_LT_EQ,
  [anon_sym_GT_GT_EQ] = anon_sym_GT_GT_EQ,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_simple_definition] = sym_simple_definition,
  [sym_import_definition] = sym_import_definition,
  [sym_leading_dot] = sym_leading_dot,
  [sym_pkg_name] = sym_pkg_name,
  [sym_as_name] = sym_as_name,
  [sym_assign_definition] = sym_assign_definition,
  [sym_assign] = sym_assign,
  [sym_augassign] = sym_augassign,
  [sym_augmented_assign] = sym_augmented_assign,
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
  [sym_test] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_SLASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT_EQ] = {
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
  [sym_assign_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_assign] = {
    .visible = true,
    .named = true,
  },
  [sym_augassign] = {
    .visible = true,
    .named = true,
  },
  [sym_augmented_assign] = {
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
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(18);
      if (lookahead == '%') ADVANCE(5);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '*') ADVANCE(1);
      if (lookahead == '+') ADVANCE(7);
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '<') ADVANCE(4);
      if (lookahead == '=') ADVANCE(30);
      if (lookahead == '>') ADVANCE(15);
      if (lookahead == '^') ADVANCE(9);
      if (lookahead == 'a') ADVANCE(24);
      if (lookahead == 'i') ADVANCE(20);
      if (lookahead == '|') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '=') ADVANCE(33);
      END_STATE();
    case 2:
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 3:
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == '=') ADVANCE(35);
      END_STATE();
    case 4:
      if (lookahead == '<') ADVANCE(13);
      END_STATE();
    case 5:
      if (lookahead == '=') ADVANCE(37);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(38);
      END_STATE();
    case 7:
      if (lookahead == '=') ADVANCE(31);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(32);
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(40);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(39);
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(34);
      END_STATE();
    case 12:
      if (lookahead == '=') ADVANCE(36);
      END_STATE();
    case 13:
      if (lookahead == '=') ADVANCE(41);
      END_STATE();
    case 14:
      if (lookahead == '=') ADVANCE(42);
      END_STATE();
    case 15:
      if (lookahead == '>') ADVANCE(14);
      END_STATE();
    case 16:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (lookahead == '"' ||
          lookahead == '\'' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 17:
      if (eof) ADVANCE(18);
      if (lookahead == 'i') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_import);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_as);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_test);
      if (lookahead == '"' ||
          lookahead == '\'' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_EQ);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH_EQ);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_AMP_EQ);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_PIPE_EQ);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_CARET_EQ);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_LT_LT_EQ);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_GT_GT_EQ);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 17},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 17},
  [7] = {.lex_state = 17},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 17},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 17},
  [17] = {.lex_state = 17},
  [18] = {.lex_state = 17},
  [19] = {.lex_state = 17},
  [20] = {.lex_state = 17},
  [21] = {.lex_state = 17},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 17},
  [24] = {.lex_state = 16},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 16},
  [27] = {.lex_state = 16},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 16},
  [32] = {.lex_state = 16},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_as] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_PLUS_EQ] = ACTIONS(1),
    [anon_sym_DASH_EQ] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_STAR_STAR_EQ] = ACTIONS(1),
    [anon_sym_SLASH_EQ] = ACTIONS(1),
    [anon_sym_SLASH_SLASH_EQ] = ACTIONS(1),
    [anon_sym_PERCENT_EQ] = ACTIONS(1),
    [anon_sym_AMP_EQ] = ACTIONS(1),
    [anon_sym_PIPE_EQ] = ACTIONS(1),
    [anon_sym_CARET_EQ] = ACTIONS(1),
    [anon_sym_LT_LT_EQ] = ACTIONS(1),
    [anon_sym_GT_GT_EQ] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(28),
    [sym__definition] = STATE(7),
    [sym_simple_definition] = STATE(7),
    [sym_import_definition] = STATE(23),
    [sym_assign_definition] = STATE(23),
    [sym_assign] = STATE(19),
    [sym_augmented_assign] = STATE(19),
    [aux_sym_source_file_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_import] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
  },
  [2] = {
    [aux_sym_pkg_name_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(9),
    [anon_sym_import] = ACTIONS(11),
    [sym_identifier] = ACTIONS(11),
    [anon_sym_DOT] = ACTIONS(13),
    [anon_sym_as] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(9),
    [anon_sym_PLUS_EQ] = ACTIONS(9),
    [anon_sym_DASH_EQ] = ACTIONS(9),
    [anon_sym_STAR_EQ] = ACTIONS(9),
    [anon_sym_STAR_STAR_EQ] = ACTIONS(9),
    [anon_sym_SLASH_EQ] = ACTIONS(9),
    [anon_sym_SLASH_SLASH_EQ] = ACTIONS(9),
    [anon_sym_PERCENT_EQ] = ACTIONS(9),
    [anon_sym_AMP_EQ] = ACTIONS(9),
    [anon_sym_PIPE_EQ] = ACTIONS(9),
    [anon_sym_CARET_EQ] = ACTIONS(9),
    [anon_sym_LT_LT_EQ] = ACTIONS(9),
    [anon_sym_GT_GT_EQ] = ACTIONS(9),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(9),
    [anon_sym_import] = ACTIONS(11),
    [sym_identifier] = ACTIONS(11),
    [anon_sym_DOT] = ACTIONS(9),
    [anon_sym_as] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(9),
    [anon_sym_PLUS_EQ] = ACTIONS(9),
    [anon_sym_DASH_EQ] = ACTIONS(9),
    [anon_sym_STAR_EQ] = ACTIONS(9),
    [anon_sym_STAR_STAR_EQ] = ACTIONS(9),
    [anon_sym_SLASH_EQ] = ACTIONS(9),
    [anon_sym_SLASH_SLASH_EQ] = ACTIONS(9),
    [anon_sym_PERCENT_EQ] = ACTIONS(9),
    [anon_sym_AMP_EQ] = ACTIONS(9),
    [anon_sym_PIPE_EQ] = ACTIONS(9),
    [anon_sym_CARET_EQ] = ACTIONS(9),
    [anon_sym_LT_LT_EQ] = ACTIONS(9),
    [anon_sym_GT_GT_EQ] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(16), 1,
      anon_sym_DOT,
    ACTIONS(18), 1,
      anon_sym_EQ,
    STATE(5), 1,
      aux_sym_pkg_name_repeat1,
    STATE(24), 1,
      sym_augassign,
    ACTIONS(20), 12,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_STAR_EQ,
      anon_sym_STAR_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_SLASH_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_AMP_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_LT_LT_EQ,
      anon_sym_GT_GT_EQ,
  [27] = 5,
    ACTIONS(16), 1,
      anon_sym_DOT,
    ACTIONS(22), 1,
      anon_sym_EQ,
    STATE(2), 1,
      aux_sym_pkg_name_repeat1,
    STATE(27), 1,
      sym_augassign,
    ACTIONS(20), 12,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_STAR_EQ,
      anon_sym_STAR_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_SLASH_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_AMP_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_LT_LT_EQ,
      anon_sym_GT_GT_EQ,
  [54] = 6,
    ACTIONS(24), 1,
      ts_builtin_sym_end,
    ACTIONS(26), 1,
      anon_sym_import,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(19), 2,
      sym_assign,
      sym_augmented_assign,
    STATE(23), 2,
      sym_import_definition,
      sym_assign_definition,
    STATE(6), 3,
      sym__definition,
      sym_simple_definition,
      aux_sym_source_file_repeat1,
  [77] = 6,
    ACTIONS(5), 1,
      anon_sym_import,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
    STATE(19), 2,
      sym_assign,
      sym_augmented_assign,
    STATE(23), 2,
      sym_import_definition,
      sym_assign_definition,
    STATE(6), 3,
      sym__definition,
      sym_simple_definition,
      aux_sym_source_file_repeat1,
  [100] = 4,
    ACTIONS(16), 1,
      anon_sym_DOT,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
    STATE(10), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(36), 3,
      anon_sym_import,
      sym_identifier,
      anon_sym_as,
  [115] = 4,
    ACTIONS(16), 1,
      anon_sym_DOT,
    ACTIONS(38), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(40), 3,
      anon_sym_import,
      sym_identifier,
      anon_sym_as,
  [130] = 4,
    ACTIONS(16), 1,
      anon_sym_DOT,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(44), 3,
      anon_sym_import,
      sym_identifier,
      anon_sym_as,
  [145] = 4,
    ACTIONS(16), 1,
      anon_sym_DOT,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
    STATE(9), 1,
      aux_sym_pkg_name_repeat1,
    ACTIONS(44), 3,
      anon_sym_import,
      sym_identifier,
      anon_sym_as,
  [160] = 4,
    ACTIONS(46), 1,
      ts_builtin_sym_end,
    ACTIONS(50), 1,
      anon_sym_as,
    STATE(21), 1,
      sym_as_name,
    ACTIONS(48), 2,
      anon_sym_import,
      sym_identifier,
  [174] = 5,
    ACTIONS(52), 1,
      sym_identifier,
    ACTIONS(54), 1,
      anon_sym_DOT,
    STATE(12), 1,
      sym_pkg_name,
    STATE(15), 1,
      aux_sym_leading_dot_repeat1,
    STATE(30), 1,
      sym_leading_dot,
  [190] = 2,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    ACTIONS(58), 2,
      anon_sym_import,
      sym_identifier,
  [198] = 3,
    ACTIONS(60), 1,
      sym_identifier,
    ACTIONS(62), 1,
      anon_sym_DOT,
    STATE(22), 1,
      aux_sym_leading_dot_repeat1,
  [208] = 2,
    ACTIONS(64), 1,
      ts_builtin_sym_end,
    ACTIONS(66), 2,
      anon_sym_import,
      sym_identifier,
  [216] = 2,
    ACTIONS(68), 1,
      ts_builtin_sym_end,
    ACTIONS(70), 2,
      anon_sym_import,
      sym_identifier,
  [224] = 2,
    ACTIONS(72), 1,
      ts_builtin_sym_end,
    ACTIONS(74), 2,
      anon_sym_import,
      sym_identifier,
  [232] = 2,
    ACTIONS(76), 1,
      ts_builtin_sym_end,
    ACTIONS(78), 2,
      anon_sym_import,
      sym_identifier,
  [240] = 2,
    ACTIONS(80), 1,
      ts_builtin_sym_end,
    ACTIONS(82), 2,
      anon_sym_import,
      sym_identifier,
  [248] = 2,
    ACTIONS(84), 1,
      ts_builtin_sym_end,
    ACTIONS(86), 2,
      anon_sym_import,
      sym_identifier,
  [256] = 3,
    ACTIONS(88), 1,
      sym_identifier,
    ACTIONS(90), 1,
      anon_sym_DOT,
    STATE(22), 1,
      aux_sym_leading_dot_repeat1,
  [266] = 2,
    ACTIONS(93), 1,
      ts_builtin_sym_end,
    ACTIONS(95), 2,
      anon_sym_import,
      sym_identifier,
  [274] = 1,
    ACTIONS(97), 1,
      sym_test,
  [278] = 1,
    ACTIONS(99), 1,
      sym_identifier,
  [282] = 1,
    ACTIONS(101), 1,
      sym_test,
  [286] = 1,
    ACTIONS(103), 1,
      sym_test,
  [290] = 1,
    ACTIONS(105), 1,
      ts_builtin_sym_end,
  [294] = 1,
    ACTIONS(107), 1,
      sym_identifier,
  [298] = 1,
    ACTIONS(109), 1,
      sym_identifier,
  [302] = 1,
    ACTIONS(111), 1,
      sym_test,
  [306] = 1,
    ACTIONS(113), 1,
      sym_test,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 27,
  [SMALL_STATE(6)] = 54,
  [SMALL_STATE(7)] = 77,
  [SMALL_STATE(8)] = 100,
  [SMALL_STATE(9)] = 115,
  [SMALL_STATE(10)] = 130,
  [SMALL_STATE(11)] = 145,
  [SMALL_STATE(12)] = 160,
  [SMALL_STATE(13)] = 174,
  [SMALL_STATE(14)] = 190,
  [SMALL_STATE(15)] = 198,
  [SMALL_STATE(16)] = 208,
  [SMALL_STATE(17)] = 216,
  [SMALL_STATE(18)] = 224,
  [SMALL_STATE(19)] = 232,
  [SMALL_STATE(20)] = 240,
  [SMALL_STATE(21)] = 248,
  [SMALL_STATE(22)] = 256,
  [SMALL_STATE(23)] = 266,
  [SMALL_STATE(24)] = 274,
  [SMALL_STATE(25)] = 278,
  [SMALL_STATE(26)] = 282,
  [SMALL_STATE(27)] = 286,
  [SMALL_STATE(28)] = 290,
  [SMALL_STATE(29)] = 294,
  [SMALL_STATE(30)] = 298,
  [SMALL_STATE(31)] = 302,
  [SMALL_STATE(32)] = 306,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pkg_name_repeat1, 2),
  [11] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pkg_name_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pkg_name_repeat1, 2), SHIFT_REPEAT(25),
  [16] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(13),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pkg_name, 1),
  [36] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pkg_name, 1),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pkg_name, 3),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pkg_name, 3),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pkg_name, 2),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pkg_name, 2),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_definition, 2),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_definition, 2),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign, 3),
  [58] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assign, 3),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_leading_dot, 1),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_augmented_assign, 4),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_augmented_assign, 4),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign, 4),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assign, 4),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_as_name, 2),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_as_name, 2),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_definition, 1),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assign_definition, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_augmented_assign, 3),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_augmented_assign, 3),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_definition, 3),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_definition, 3),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_leading_dot_repeat1, 2),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_leading_dot_repeat1, 2), SHIFT_REPEAT(22),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_definition, 1),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_simple_definition, 1),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [105] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_augassign, 1),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
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
