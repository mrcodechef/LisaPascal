// This file was automatically generated by EbnfStudio; don't modify it!
#include "LisaTokenType.h"

namespace Lisa {
	const char* tokenTypeString( int r ) {
		switch(r) {
			case Tok_Invalid: return "<invalid>";
			case Tok_Lpar: return "(";
			case Tok_Latt: return "(*";
			case Tok_Rpar: return ")";
			case Tok_Star: return "*";
			case Tok_Ratt: return "*)";
			case Tok_Plus: return "+";
			case Tok_Comma: return ",";
			case Tok_Minus: return "-";
			case Tok_Dot: return ".";
			case Tok_2Dot: return "..";
			case Tok_Slash: return "/";
			case Tok_Colon: return ":";
			case Tok_ColonEq: return ":=";
			case Tok_Semi: return ";";
			case Tok_Lt: return "<";
			case Tok_Leq: return "<=";
			case Tok_LtGt: return "<>";
			case Tok_Eq: return "=";
			case Tok_Gt: return ">";
			case Tok_Geq: return ">=";
			case Tok_At: return "@";
			case Tok_Lbrack: return "[";
			case Tok_Rbrack: return "]";
			case Tok_Hat: return "^";
			case Tok_Lbrace: return "{";
			case Tok_Rbrace: return "}";
			case Tok_and: return "and";
			case Tok_array: return "array";
			case Tok_begin: return "begin";
			case Tok_case: return "case";
			case Tok_const: return "const";
			case Tok_div: return "div";
			case Tok_do: return "do";
			case Tok_downto: return "downto";
			case Tok_else: return "else";
			case Tok_end: return "end";
			case Tok_external: return "external";
			case Tok_file: return "file";
			case Tok_for: return "for";
			case Tok_forward: return "forward";
			case Tok_function: return "function";
			case Tok_goto: return "goto";
			case Tok_if: return "if";
			case Tok_implementation: return "implementation";
			case Tok_in: return "in";
			case Tok_inline: return "inline";
			case Tok_interface: return "interface";
			case Tok_label: return "label";
			case Tok_mod: return "mod";
			case Tok_nil: return "nil";
			case Tok_not: return "not";
			case Tok_of: return "of";
			case Tok_or: return "or";
			case Tok_otherwise: return "otherwise";
			case Tok_packed: return "packed";
			case Tok_procedure: return "procedure";
			case Tok_program: return "program";
			case Tok_record: return "record";
			case Tok_repeat: return "repeat";
			case Tok_set: return "set";
			case Tok_string: return "string";
			case Tok_then: return "then";
			case Tok_to: return "to";
			case Tok_type: return "type";
			case Tok_unit: return "unit";
			case Tok_until: return "until";
			case Tok_uses: return "uses";
			case Tok_var: return "var";
			case Tok_while: return "while";
			case Tok_with: return "with";
			case Tok_identifier: return "identifier";
			case Tok_unsigned_real: return "unsigned_real";
			case Tok_digit_sequence: return "digit_sequence";
			case Tok_hex_digit_sequence: return "hex_digit_sequence";
			case Tok_string_literal: return "string_literal";
			case Tok_Comment: return "Comment";
			case Tok_Directive: return "Directive";
			case Tok_Eof: return "<eof>";
			default: return "";
		}
	}
	const char* tokenTypeName( int r ) {
		switch(r) {
			case Tok_Invalid: return "Tok_Invalid";
			case Tok_Lpar: return "Tok_Lpar";
			case Tok_Latt: return "Tok_Latt";
			case Tok_Rpar: return "Tok_Rpar";
			case Tok_Star: return "Tok_Star";
			case Tok_Ratt: return "Tok_Ratt";
			case Tok_Plus: return "Tok_Plus";
			case Tok_Comma: return "Tok_Comma";
			case Tok_Minus: return "Tok_Minus";
			case Tok_Dot: return "Tok_Dot";
			case Tok_2Dot: return "Tok_2Dot";
			case Tok_Slash: return "Tok_Slash";
			case Tok_Colon: return "Tok_Colon";
			case Tok_ColonEq: return "Tok_ColonEq";
			case Tok_Semi: return "Tok_Semi";
			case Tok_Lt: return "Tok_Lt";
			case Tok_Leq: return "Tok_Leq";
			case Tok_LtGt: return "Tok_LtGt";
			case Tok_Eq: return "Tok_Eq";
			case Tok_Gt: return "Tok_Gt";
			case Tok_Geq: return "Tok_Geq";
			case Tok_At: return "Tok_At";
			case Tok_Lbrack: return "Tok_Lbrack";
			case Tok_Rbrack: return "Tok_Rbrack";
			case Tok_Hat: return "Tok_Hat";
			case Tok_Lbrace: return "Tok_Lbrace";
			case Tok_Rbrace: return "Tok_Rbrace";
			case Tok_and: return "Tok_and";
			case Tok_array: return "Tok_array";
			case Tok_begin: return "Tok_begin";
			case Tok_case: return "Tok_case";
			case Tok_const: return "Tok_const";
			case Tok_div: return "Tok_div";
			case Tok_do: return "Tok_do";
			case Tok_downto: return "Tok_downto";
			case Tok_else: return "Tok_else";
			case Tok_end: return "Tok_end";
			case Tok_external: return "Tok_external";
			case Tok_file: return "Tok_file";
			case Tok_for: return "Tok_for";
			case Tok_forward: return "Tok_forward";
			case Tok_function: return "Tok_function";
			case Tok_goto: return "Tok_goto";
			case Tok_if: return "Tok_if";
			case Tok_implementation: return "Tok_implementation";
			case Tok_in: return "Tok_in";
			case Tok_inline: return "Tok_inline";
			case Tok_interface: return "Tok_interface";
			case Tok_label: return "Tok_label";
			case Tok_mod: return "Tok_mod";
			case Tok_nil: return "Tok_nil";
			case Tok_not: return "Tok_not";
			case Tok_of: return "Tok_of";
			case Tok_or: return "Tok_or";
			case Tok_otherwise: return "Tok_otherwise";
			case Tok_packed: return "Tok_packed";
			case Tok_procedure: return "Tok_procedure";
			case Tok_program: return "Tok_program";
			case Tok_record: return "Tok_record";
			case Tok_repeat: return "Tok_repeat";
			case Tok_set: return "Tok_set";
			case Tok_string: return "Tok_string";
			case Tok_then: return "Tok_then";
			case Tok_to: return "Tok_to";
			case Tok_type: return "Tok_type";
			case Tok_unit: return "Tok_unit";
			case Tok_until: return "Tok_until";
			case Tok_uses: return "Tok_uses";
			case Tok_var: return "Tok_var";
			case Tok_while: return "Tok_while";
			case Tok_with: return "Tok_with";
			case Tok_identifier: return "Tok_identifier";
			case Tok_unsigned_real: return "Tok_unsigned_real";
			case Tok_digit_sequence: return "Tok_digit_sequence";
			case Tok_hex_digit_sequence: return "Tok_hex_digit_sequence";
			case Tok_string_literal: return "Tok_string_literal";
			case Tok_Comment: return "Tok_Comment";
			case Tok_Directive: return "Tok_Directive";
			case Tok_Eof: return "Tok_Eof";
			default: return "";
		}
	}
	bool tokenTypeIsLiteral( int r ) {
		return r > TT_Literals && r < TT_Keywords;
	}
	bool tokenTypeIsKeyword( int r ) {
		return r > TT_Keywords && r < TT_Specials;
	}
	bool tokenTypeIsSpecial( int r ) {
		return r > TT_Specials && r < TT_Max;
	}
	static inline char at( const QByteArray& str, int i ){
		return ( i >= 0 && i < str.size() ? str[i] : 0 );
	}
	TokenType tokenTypeFromString( const QByteArray& str, int* pos ) {
		int i = ( pos != 0 ? *pos: 0 );
		TokenType res = Tok_Invalid;
		switch( at(str,i) ){
		case '(':
			if( at(str,i+1) == '*' ){
				res = Tok_Latt; i += 2;
			} else {
				res = Tok_Lpar; i += 1;
			}
			break;
		case ')':
			res = Tok_Rpar; i += 1;
			break;
		case '*':
			if( at(str,i+1) == ')' ){
				res = Tok_Ratt; i += 2;
			} else {
				res = Tok_Star; i += 1;
			}
			break;
		case '+':
			res = Tok_Plus; i += 1;
			break;
		case ',':
			res = Tok_Comma; i += 1;
			break;
		case '-':
			res = Tok_Minus; i += 1;
			break;
		case '.':
			if( at(str,i+1) == '.' ){
				res = Tok_2Dot; i += 2;
			} else {
				res = Tok_Dot; i += 1;
			}
			break;
		case '/':
			res = Tok_Slash; i += 1;
			break;
		case ':':
			if( at(str,i+1) == '=' ){
				res = Tok_ColonEq; i += 2;
			} else {
				res = Tok_Colon; i += 1;
			}
			break;
		case ';':
			res = Tok_Semi; i += 1;
			break;
		case '<':
			switch( at(str,i+1) ){
			case '=':
				res = Tok_Leq; i += 2;
				break;
			case '>':
				res = Tok_LtGt; i += 2;
				break;
			default:
				res = Tok_Lt; i += 1;
				break;
			}
			break;
		case '=':
			res = Tok_Eq; i += 1;
			break;
		case '>':
			if( at(str,i+1) == '=' ){
				res = Tok_Geq; i += 2;
			} else {
				res = Tok_Gt; i += 1;
			}
			break;
		case '@':
			res = Tok_At; i += 1;
			break;
		case '[':
			res = Tok_Lbrack; i += 1;
			break;
		case ']':
			res = Tok_Rbrack; i += 1;
			break;
		case '^':
			res = Tok_Hat; i += 1;
			break;
		case 'a':
			switch( at(str,i+1) ){
			case 'n':
				if( at(str,i+2) == 'd' ){
					res = Tok_and; i += 3;
				}
				break;
			case 'r':
				if( at(str,i+2) == 'r' ){
					if( at(str,i+3) == 'a' ){
						if( at(str,i+4) == 'y' ){
							res = Tok_array; i += 5;
						}
					}
				}
				break;
			}
			break;
		case 'b':
			if( at(str,i+1) == 'e' ){
				if( at(str,i+2) == 'g' ){
					if( at(str,i+3) == 'i' ){
						if( at(str,i+4) == 'n' ){
							res = Tok_begin; i += 5;
						}
					}
				}
			}
			break;
		case 'c':
			switch( at(str,i+1) ){
			case 'a':
				if( at(str,i+2) == 's' ){
					if( at(str,i+3) == 'e' ){
						res = Tok_case; i += 4;
					}
				}
				break;
			case 'o':
				if( at(str,i+2) == 'n' ){
					if( at(str,i+3) == 's' ){
						if( at(str,i+4) == 't' ){
							res = Tok_const; i += 5;
						}
					}
				}
				break;
			}
			break;
		case 'd':
			switch( at(str,i+1) ){
			case 'i':
				if( at(str,i+2) == 'v' ){
					res = Tok_div; i += 3;
				}
				break;
			case 'o':
				if( at(str,i+2) == 'w' ){
					if( at(str,i+3) == 'n' ){
						if( at(str,i+4) == 't' ){
							if( at(str,i+5) == 'o' ){
								res = Tok_downto; i += 6;
							}
						}
					}
				} else {
					res = Tok_do; i += 2;
				}
				break;
			}
			break;
		case 'e':
			switch( at(str,i+1) ){
			case 'l':
				if( at(str,i+2) == 's' ){
					if( at(str,i+3) == 'e' ){
						res = Tok_else; i += 4;
					}
				}
				break;
			case 'n':
				if( at(str,i+2) == 'd' ){
					res = Tok_end; i += 3;
				}
				break;
			case 'x':
				if( at(str,i+2) == 't' ){
					if( at(str,i+3) == 'e' ){
						if( at(str,i+4) == 'r' ){
							if( at(str,i+5) == 'n' ){
								if( at(str,i+6) == 'a' ){
									if( at(str,i+7) == 'l' ){
										res = Tok_external; i += 8;
									}
								}
							}
						}
					}
				}
				break;
			}
			break;
		case 'f':
			switch( at(str,i+1) ){
			case 'i':
				if( at(str,i+2) == 'l' ){
					if( at(str,i+3) == 'e' ){
						res = Tok_file; i += 4;
					}
				}
				break;
			case 'o':
				if( at(str,i+2) == 'r' ){
					if( at(str,i+3) == 'w' ){
						if( at(str,i+4) == 'a' ){
							if( at(str,i+5) == 'r' ){
								if( at(str,i+6) == 'd' ){
									res = Tok_forward; i += 7;
								}
							}
						}
					} else {
						res = Tok_for; i += 3;
					}
				}
				break;
			case 'u':
				if( at(str,i+2) == 'n' ){
					if( at(str,i+3) == 'c' ){
						if( at(str,i+4) == 't' ){
							if( at(str,i+5) == 'i' ){
								if( at(str,i+6) == 'o' ){
									if( at(str,i+7) == 'n' ){
										res = Tok_function; i += 8;
									}
								}
							}
						}
					}
				}
				break;
			}
			break;
		case 'g':
			if( at(str,i+1) == 'o' ){
				if( at(str,i+2) == 't' ){
					if( at(str,i+3) == 'o' ){
						res = Tok_goto; i += 4;
					}
				}
			}
			break;
		case 'i':
			switch( at(str,i+1) ){
			case 'f':
				res = Tok_if; i += 2;
				break;
			case 'm':
				if( at(str,i+2) == 'p' ){
					if( at(str,i+3) == 'l' ){
						if( at(str,i+4) == 'e' ){
							if( at(str,i+5) == 'm' ){
								if( at(str,i+6) == 'e' ){
									if( at(str,i+7) == 'n' ){
										if( at(str,i+8) == 't' ){
											if( at(str,i+9) == 'a' ){
												if( at(str,i+10) == 't' ){
													if( at(str,i+11) == 'i' ){
														if( at(str,i+12) == 'o' ){
															if( at(str,i+13) == 'n' ){
																res = Tok_implementation; i += 14;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				break;
			case 'n':
				switch( at(str,i+2) ){
				case 'l':
					if( at(str,i+3) == 'i' ){
						if( at(str,i+4) == 'n' ){
							if( at(str,i+5) == 'e' ){
								res = Tok_inline; i += 6;
							}
						}
					}
					break;
				case 't':
					if( at(str,i+3) == 'e' ){
						if( at(str,i+4) == 'r' ){
							if( at(str,i+5) == 'f' ){
								if( at(str,i+6) == 'a' ){
									if( at(str,i+7) == 'c' ){
										if( at(str,i+8) == 'e' ){
											res = Tok_interface; i += 9;
										}
									}
								}
							}
						}
					}
					break;
				default:
					res = Tok_in; i += 2;
					break;
				}
				break;
			}
			break;
		case 'l':
			if( at(str,i+1) == 'a' ){
				if( at(str,i+2) == 'b' ){
					if( at(str,i+3) == 'e' ){
						if( at(str,i+4) == 'l' ){
							res = Tok_label; i += 5;
						}
					}
				}
			}
			break;
		case 'm':
			if( at(str,i+1) == 'o' ){
				if( at(str,i+2) == 'd' ){
					res = Tok_mod; i += 3;
				}
			}
			break;
		case 'n':
			switch( at(str,i+1) ){
			case 'i':
				if( at(str,i+2) == 'l' ){
					res = Tok_nil; i += 3;
				}
				break;
			case 'o':
				if( at(str,i+2) == 't' ){
					res = Tok_not; i += 3;
				}
				break;
			}
			break;
		case 'o':
			switch( at(str,i+1) ){
			case 'f':
				res = Tok_of; i += 2;
				break;
			case 'r':
				res = Tok_or; i += 2;
				break;
			case 't':
				if( at(str,i+2) == 'h' ){
					if( at(str,i+3) == 'e' ){
						if( at(str,i+4) == 'r' ){
							if( at(str,i+5) == 'w' ){
								if( at(str,i+6) == 'i' ){
									if( at(str,i+7) == 's' ){
										if( at(str,i+8) == 'e' ){
											res = Tok_otherwise; i += 9;
										}
									}
								}
							}
						}
					}
				}
				break;
			}
			break;
		case 'p':
			switch( at(str,i+1) ){
			case 'a':
				if( at(str,i+2) == 'c' ){
					if( at(str,i+3) == 'k' ){
						if( at(str,i+4) == 'e' ){
							if( at(str,i+5) == 'd' ){
								res = Tok_packed; i += 6;
							}
						}
					}
				}
				break;
			case 'r':
				if( at(str,i+2) == 'o' ){
					switch( at(str,i+3) ){
					case 'c':
						if( at(str,i+4) == 'e' ){
							if( at(str,i+5) == 'd' ){
								if( at(str,i+6) == 'u' ){
									if( at(str,i+7) == 'r' ){
										if( at(str,i+8) == 'e' ){
											res = Tok_procedure; i += 9;
										}
									}
								}
							}
						}
						break;
					case 'g':
						if( at(str,i+4) == 'r' ){
							if( at(str,i+5) == 'a' ){
								if( at(str,i+6) == 'm' ){
									res = Tok_program; i += 7;
								}
							}
						}
						break;
					}
				}
				break;
			}
			break;
		case 'r':
			if( at(str,i+1) == 'e' ){
				switch( at(str,i+2) ){
				case 'c':
					if( at(str,i+3) == 'o' ){
						if( at(str,i+4) == 'r' ){
							if( at(str,i+5) == 'd' ){
								res = Tok_record; i += 6;
							}
						}
					}
					break;
				case 'p':
					if( at(str,i+3) == 'e' ){
						if( at(str,i+4) == 'a' ){
							if( at(str,i+5) == 't' ){
								res = Tok_repeat; i += 6;
							}
						}
					}
					break;
				}
			}
			break;
		case 's':
			switch( at(str,i+1) ){
			case 'e':
				if( at(str,i+2) == 't' ){
					res = Tok_set; i += 3;
				}
				break;
			case 't':
				if( at(str,i+2) == 'r' ){
					if( at(str,i+3) == 'i' ){
						if( at(str,i+4) == 'n' ){
							if( at(str,i+5) == 'g' ){
								res = Tok_string; i += 6;
							}
						}
					}
				}
				break;
			}
			break;
		case 't':
			switch( at(str,i+1) ){
			case 'h':
				if( at(str,i+2) == 'e' ){
					if( at(str,i+3) == 'n' ){
						res = Tok_then; i += 4;
					}
				}
				break;
			case 'o':
				res = Tok_to; i += 2;
				break;
			case 'y':
				if( at(str,i+2) == 'p' ){
					if( at(str,i+3) == 'e' ){
						res = Tok_type; i += 4;
					}
				}
				break;
			}
			break;
		case 'u':
			switch( at(str,i+1) ){
			case 'n':
				switch( at(str,i+2) ){
				case 'i':
					if( at(str,i+3) == 't' ){
						res = Tok_unit; i += 4;
					}
					break;
				case 't':
					if( at(str,i+3) == 'i' ){
						if( at(str,i+4) == 'l' ){
							res = Tok_until; i += 5;
						}
					}
					break;
				}
				break;
			case 's':
				if( at(str,i+2) == 'e' ){
					if( at(str,i+3) == 's' ){
						res = Tok_uses; i += 4;
					}
				}
				break;
			}
			break;
		case 'v':
			if( at(str,i+1) == 'a' ){
				if( at(str,i+2) == 'r' ){
					res = Tok_var; i += 3;
				}
			}
			break;
		case 'w':
			switch( at(str,i+1) ){
			case 'h':
				if( at(str,i+2) == 'i' ){
					if( at(str,i+3) == 'l' ){
						if( at(str,i+4) == 'e' ){
							res = Tok_while; i += 5;
						}
					}
				}
				break;
			case 'i':
				if( at(str,i+2) == 't' ){
					if( at(str,i+3) == 'h' ){
						res = Tok_with; i += 4;
					}
				}
				break;
			}
			break;
		case '{':
			res = Tok_Lbrace; i += 1;
			break;
		case '}':
			res = Tok_Rbrace; i += 1;
			break;
		}
		if(pos) *pos = i;
		return res;
	}
}
