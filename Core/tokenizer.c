/**
 * @file
 * @brief Tokenizes the input flow and generates tokens.
 */

/** Every token supported. */
typedef struct Token {
	enum {
		T_KEYWORD, ///< A reserved keyword.
		T_NAME, ///< A name, for a variable, function, module or anything.
		T_SYMBOL, ///< A symbol with a special meaning.
		T_NUMBER, ///< A number (integer or float).
	} type; ///< The type of token.
	union {
		enum {
			T_KW_CONST,
			T_KW_MUT,
			T_KW_DROP,
			T_KW_GLOBAL,
			T_KW_FREEZE,
			T_KW_MODULE,
			T_KW_METHOD,
			T_KW_SELF,
			T_KW_EXTENDS,
			T_KW_NIL,
			T_KW_FUN,
			T_KW_ENDFUN,
			T_KW_IF,
			T_KW_ELSE,
			T_KW_ENDIF,
			T_KW_WHILE,
			T_KW_ENDWHILE,
			T_KW_FOR,
			T_KW_IN,
			T_KW_ENDFOR,
			T_KW_THEN,
			T_KW_RETURN,
			T_KW_LOAD,
		} keyword; ///< All the keywords it can be.
		enum {
			T_SYM_DOL, ///< $
			T_SYM_UNDER, ///< _
			T_SYM_QUOTE, ///< "
			T_SYM_APOS, ///< '
			T_SYM_AT, ///< @
			T_SYM_ASSIGN, ///< :=
			T_SYM_SEMI, ///< ;
			T_SYM_PLUS, ///< +
			T_SYM_MUL, ///< *
			T_SYM_SUB, ///< -
			T_SYM_DIV, ///< /
			T_SYM_MOD, ///< %
			T_SYM_POW, ///< **
			T_SYM_NEG, ///< ~
			T_SYM_OR, ///< |
			T_SYM_AND, ///< &
			T_SYM_DOR, ///< ||
			T_SYM_DAND, ///< &&
			T_SYM_LT, ///< <
			T_SYM_GT, ///< >
			T_SYM_LEQ, ///< <=
			T_SYM_GEQ, ///< >=
			T_SYM_DLT, ///< <<
			T_SYM_DGT, ///< >>
			T_SYM_NOT, ///< !
			T_SYM_NEQU, ///< !=
			T_SYM_EQUAL, ///< =
			T_SYM_PLEQU, ///< +=
			T_SYM_SUBEQU, ///< -=
			T_SYM_MULEQU, ///< *=
			T_SYM_DIVEQU, ///< /=
			T_SYM_MODEQU, ///< %=
			T_SYM_POWEQU, ///< **=
			T_SYM_NEGEQU, ///< ~=
			T_SYM_OREQU, ///< |=
			T_SYM_ANDEQU,///< &=
			T_SYM_DOREQU, ///< ||=
			T_SYM_DANDEQU, ///< &&=
			T_SYM_LSHIFEQU, ///< <<=
			T_SYM_RSHIFEQU, ///< >>=
			T_SYM_PROP, ///< ::
			T_SYM_COLON, ///< :
			T_SYM_COMMA, ///< ,
			T_SYM_DOT, ///< .
			T_SYM_LPAR, ///< (
			T_SYM_RPAR, ///< )
			T_SYM_LBRK, ///< [
			T_SYM_RBRK, ///< ]
			T_SYM_LBRC, ///< {
			T_SYM_RBRC, ///< }
			T_SYM_RET, ///< ->
			T_SYM_RANG, ///< ..
		} symbol; ///< All the symbols it can be.
		char* name; ///< In case of a name or a number.
	} data; ///< More information based on `type`.
} token;
