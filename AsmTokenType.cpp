// This file was automatically generated by EbnfStudio; don't modify it!
#include "AsmTokenType.h"

namespace Asm {
	const char* tokenTypeString( int r ) {
		switch(r) {
			case Tok_Invalid: return "<invalid>";
			case Tok_Hash: return "#";
			case Tok_Amp: return "&";
			case Tok_Lpar: return "(";
			case Tok_Rpar: return ")";
			case Tok_Star: return "*";
			case Tok_Plus: return "+";
			case Tok_Comma: return ",";
			case Tok_Minus: return "-";
			case Tok_Slash: return "/";
			case Tok_Colon: return ":";
			case Tok_Semi: return ";";
			case Tok_Lt: return "<";
			case Tok_LtGt: return "<>";
			case Tok_Eq: return "=";
			case Tok_Gt: return ">";
			case Tok_Hat: return "^";
			case Tok_Bar: return "|";
			case Tok_Tilde: return "~";
			case Tok_ABCD: return "ABCD";
			case Tok_ADD: return "ADD";
			case Tok_ADDA: return "ADDA";
			case Tok_ADDI: return "ADDI";
			case Tok_ADDQ: return "ADDQ";
			case Tok_ADDX: return "ADDX";
			case Tok_AND: return "AND";
			case Tok_ANDI: return "ANDI";
			case Tok_ASCII: return "ASCII";
			case Tok_ASL: return "ASL";
			case Tok_ASR: return "ASR";
			case Tok_BCC: return "BCC";
			case Tok_BCHG: return "BCHG";
			case Tok_BCLR: return "BCLR";
			case Tok_BCS: return "BCS";
			case Tok_BEQ: return "BEQ";
			case Tok_BGE: return "BGE";
			case Tok_BGT: return "BGT";
			case Tok_BHI: return "BHI";
			case Tok_BHS: return "BHS";
			case Tok_BLE: return "BLE";
			case Tok_BLO: return "BLO";
			case Tok_BLS: return "BLS";
			case Tok_BLT: return "BLT";
			case Tok_BMI: return "BMI";
			case Tok_BNE: return "BNE";
			case Tok_BPL: return "BPL";
			case Tok_BRA: return "BRA";
			case Tok_BSET: return "BSET";
			case Tok_BSR: return "BSR";
			case Tok_BTST: return "BTST";
			case Tok_BVC: return "BVC";
			case Tok_BYTE: return "BYTE";
			case Tok_CHK: return "CHK";
			case Tok_CLR: return "CLR";
			case Tok_CMP: return "CMP";
			case Tok_CMPA: return "CMPA";
			case Tok_CMPI: return "CMPI";
			case Tok_CMPM: return "CMPM";
			case Tok_DBEQ: return "DBEQ";
			case Tok_DBF: return "DBF";
			case Tok_DBRA: return "DBRA";
			case Tok_DEF: return "DEF";
			case Tok_DIVS: return "DIVS";
			case Tok_DIVU: return "DIVU";
			case Tok_ELSE: return "ELSE";
			case Tok_END: return "END";
			case Tok_ENDC: return "ENDC";
			case Tok_ENDM: return "ENDM";
			case Tok_EOR: return "EOR";
			case Tok_EORI: return "EORI";
			case Tok_EQU: return "EQU";
			case Tok_EXG: return "EXG";
			case Tok_EXT: return "EXT";
			case Tok_FUNC: return "FUNC";
			case Tok_IF: return "IF";
			case Tok_ILLEGAL: return "ILLEGAL";
			case Tok_INCLUDE: return "INCLUDE";
			case Tok_JMP: return "JMP";
			case Tok_JSR: return "JSR";
			case Tok_LEA: return "LEA";
			case Tok_LINK: return "LINK";
			case Tok_LIST: return "LIST";
			case Tok_LSL: return "LSL";
			case Tok_LSR: return "LSR";
			case Tok_MACRO: return "MACRO";
			case Tok_MACROLIST: return "MACROLIST";
			case Tok_MOVE: return "MOVE";
			case Tok_MOVEA: return "MOVEA";
			case Tok_MOVEM: return "MOVEM";
			case Tok_MOVEP: return "MOVEP";
			case Tok_MOVEQ: return "MOVEQ";
			case Tok_MULS: return "MULS";
			case Tok_MULU: return "MULU";
			case Tok_NBCD: return "NBCD";
			case Tok_NEG: return "NEG";
			case Tok_NEGX: return "NEGX";
			case Tok_NOLIST: return "NOLIST";
			case Tok_NOMACROLIST: return "NOMACROLIST";
			case Tok_NOP: return "NOP";
			case Tok_NOPATCHLIST: return "NOPATCHLIST";
			case Tok_NOT: return "NOT";
			case Tok_OR: return "OR";
			case Tok_ORG: return "ORG";
			case Tok_ORI: return "ORI";
			case Tok_PATCHLIST: return "PATCHLIST";
			case Tok_PEA: return "PEA";
			case Tok_PROC: return "PROC";
			case Tok_REF: return "REF";
			case Tok_RESET: return "RESET";
			case Tok_ROL: return "ROL";
			case Tok_ROR: return "ROR";
			case Tok_RORG: return "RORG";
			case Tok_ROXL: return "ROXL";
			case Tok_ROXR: return "ROXR";
			case Tok_RTE: return "RTE";
			case Tok_RTR: return "RTR";
			case Tok_RTS: return "RTS";
			case Tok_SBCD: return "SBCD";
			case Tok_SEG: return "SEG";
			case Tok_SNE: return "SNE";
			case Tok_STOP: return "STOP";
			case Tok_SUB: return "SUB";
			case Tok_SUBA: return "SUBA";
			case Tok_SUBI: return "SUBI";
			case Tok_SUBQ: return "SUBQ";
			case Tok_SUBX: return "SUBX";
			case Tok_SWAP: return "SWAP";
			case Tok_TAS: return "TAS";
			case Tok_TITLE: return "TITLE";
			case Tok_TRAP: return "TRAP";
			case Tok_TRAPV: return "TRAPV";
			case Tok_TST: return "TST";
			case Tok_UNLK: return "UNLK";
			case Tok_WORD: return "WORD";
			case Tok_number: return "number";
			case Tok_string: return "string";
			case Tok_ident: return "ident";
			case Tok_substitute: return "substitute";
			case Tok_label: return "label";
			case Tok_Comment: return "Comment";
			case Tok_eol: return "eol";
			case Tok_dotW: return "dotW";
			case Tok_dotL: return "dotL";
			case Tok_dotB: return "dotB";
			case Tok_dotS: return "dotS";
			case Tok_Eof: return "<eof>";
			default: return "";
		}
	}
	const char* tokenTypeName( int r ) {
		switch(r) {
			case Tok_Invalid: return "Tok_Invalid";
			case Tok_Hash: return "Tok_Hash";
			case Tok_Amp: return "Tok_Amp";
			case Tok_Lpar: return "Tok_Lpar";
			case Tok_Rpar: return "Tok_Rpar";
			case Tok_Star: return "Tok_Star";
			case Tok_Plus: return "Tok_Plus";
			case Tok_Comma: return "Tok_Comma";
			case Tok_Minus: return "Tok_Minus";
			case Tok_Slash: return "Tok_Slash";
			case Tok_Colon: return "Tok_Colon";
			case Tok_Semi: return "Tok_Semi";
			case Tok_Lt: return "Tok_Lt";
			case Tok_LtGt: return "Tok_LtGt";
			case Tok_Eq: return "Tok_Eq";
			case Tok_Gt: return "Tok_Gt";
			case Tok_Hat: return "Tok_Hat";
			case Tok_Bar: return "Tok_Bar";
			case Tok_Tilde: return "Tok_Tilde";
			case Tok_ABCD: return "Tok_ABCD";
			case Tok_ADD: return "Tok_ADD";
			case Tok_ADDA: return "Tok_ADDA";
			case Tok_ADDI: return "Tok_ADDI";
			case Tok_ADDQ: return "Tok_ADDQ";
			case Tok_ADDX: return "Tok_ADDX";
			case Tok_AND: return "Tok_AND";
			case Tok_ANDI: return "Tok_ANDI";
			case Tok_ASCII: return "Tok_ASCII";
			case Tok_ASL: return "Tok_ASL";
			case Tok_ASR: return "Tok_ASR";
			case Tok_BCC: return "Tok_BCC";
			case Tok_BCHG: return "Tok_BCHG";
			case Tok_BCLR: return "Tok_BCLR";
			case Tok_BCS: return "Tok_BCS";
			case Tok_BEQ: return "Tok_BEQ";
			case Tok_BGE: return "Tok_BGE";
			case Tok_BGT: return "Tok_BGT";
			case Tok_BHI: return "Tok_BHI";
			case Tok_BHS: return "Tok_BHS";
			case Tok_BLE: return "Tok_BLE";
			case Tok_BLO: return "Tok_BLO";
			case Tok_BLS: return "Tok_BLS";
			case Tok_BLT: return "Tok_BLT";
			case Tok_BMI: return "Tok_BMI";
			case Tok_BNE: return "Tok_BNE";
			case Tok_BPL: return "Tok_BPL";
			case Tok_BRA: return "Tok_BRA";
			case Tok_BSET: return "Tok_BSET";
			case Tok_BSR: return "Tok_BSR";
			case Tok_BTST: return "Tok_BTST";
			case Tok_BVC: return "Tok_BVC";
			case Tok_BYTE: return "Tok_BYTE";
			case Tok_CHK: return "Tok_CHK";
			case Tok_CLR: return "Tok_CLR";
			case Tok_CMP: return "Tok_CMP";
			case Tok_CMPA: return "Tok_CMPA";
			case Tok_CMPI: return "Tok_CMPI";
			case Tok_CMPM: return "Tok_CMPM";
			case Tok_DBEQ: return "Tok_DBEQ";
			case Tok_DBF: return "Tok_DBF";
			case Tok_DBRA: return "Tok_DBRA";
			case Tok_DEF: return "Tok_DEF";
			case Tok_DIVS: return "Tok_DIVS";
			case Tok_DIVU: return "Tok_DIVU";
			case Tok_ELSE: return "Tok_ELSE";
			case Tok_END: return "Tok_END";
			case Tok_ENDC: return "Tok_ENDC";
			case Tok_ENDM: return "Tok_ENDM";
			case Tok_EOR: return "Tok_EOR";
			case Tok_EORI: return "Tok_EORI";
			case Tok_EQU: return "Tok_EQU";
			case Tok_EXG: return "Tok_EXG";
			case Tok_EXT: return "Tok_EXT";
			case Tok_FUNC: return "Tok_FUNC";
			case Tok_IF: return "Tok_IF";
			case Tok_ILLEGAL: return "Tok_ILLEGAL";
			case Tok_INCLUDE: return "Tok_INCLUDE";
			case Tok_JMP: return "Tok_JMP";
			case Tok_JSR: return "Tok_JSR";
			case Tok_LEA: return "Tok_LEA";
			case Tok_LINK: return "Tok_LINK";
			case Tok_LIST: return "Tok_LIST";
			case Tok_LSL: return "Tok_LSL";
			case Tok_LSR: return "Tok_LSR";
			case Tok_MACRO: return "Tok_MACRO";
			case Tok_MACROLIST: return "Tok_MACROLIST";
			case Tok_MOVE: return "Tok_MOVE";
			case Tok_MOVEA: return "Tok_MOVEA";
			case Tok_MOVEM: return "Tok_MOVEM";
			case Tok_MOVEP: return "Tok_MOVEP";
			case Tok_MOVEQ: return "Tok_MOVEQ";
			case Tok_MULS: return "Tok_MULS";
			case Tok_MULU: return "Tok_MULU";
			case Tok_NBCD: return "Tok_NBCD";
			case Tok_NEG: return "Tok_NEG";
			case Tok_NEGX: return "Tok_NEGX";
			case Tok_NOLIST: return "Tok_NOLIST";
			case Tok_NOMACROLIST: return "Tok_NOMACROLIST";
			case Tok_NOP: return "Tok_NOP";
			case Tok_NOPATCHLIST: return "Tok_NOPATCHLIST";
			case Tok_NOT: return "Tok_NOT";
			case Tok_OR: return "Tok_OR";
			case Tok_ORG: return "Tok_ORG";
			case Tok_ORI: return "Tok_ORI";
			case Tok_PATCHLIST: return "Tok_PATCHLIST";
			case Tok_PEA: return "Tok_PEA";
			case Tok_PROC: return "Tok_PROC";
			case Tok_REF: return "Tok_REF";
			case Tok_RESET: return "Tok_RESET";
			case Tok_ROL: return "Tok_ROL";
			case Tok_ROR: return "Tok_ROR";
			case Tok_RORG: return "Tok_RORG";
			case Tok_ROXL: return "Tok_ROXL";
			case Tok_ROXR: return "Tok_ROXR";
			case Tok_RTE: return "Tok_RTE";
			case Tok_RTR: return "Tok_RTR";
			case Tok_RTS: return "Tok_RTS";
			case Tok_SBCD: return "Tok_SBCD";
			case Tok_SEG: return "Tok_SEG";
			case Tok_SNE: return "Tok_SNE";
			case Tok_STOP: return "Tok_STOP";
			case Tok_SUB: return "Tok_SUB";
			case Tok_SUBA: return "Tok_SUBA";
			case Tok_SUBI: return "Tok_SUBI";
			case Tok_SUBQ: return "Tok_SUBQ";
			case Tok_SUBX: return "Tok_SUBX";
			case Tok_SWAP: return "Tok_SWAP";
			case Tok_TAS: return "Tok_TAS";
			case Tok_TITLE: return "Tok_TITLE";
			case Tok_TRAP: return "Tok_TRAP";
			case Tok_TRAPV: return "Tok_TRAPV";
			case Tok_TST: return "Tok_TST";
			case Tok_UNLK: return "Tok_UNLK";
			case Tok_WORD: return "Tok_WORD";
			case Tok_number: return "Tok_number";
			case Tok_string: return "Tok_string";
			case Tok_ident: return "Tok_ident";
			case Tok_substitute: return "Tok_substitute";
			case Tok_label: return "Tok_label";
			case Tok_Comment: return "Tok_Comment";
			case Tok_eol: return "Tok_eol";
			case Tok_dotW: return "Tok_dotW";
			case Tok_dotL: return "Tok_dotL";
			case Tok_dotB: return "Tok_dotB";
			case Tok_dotS: return "Tok_dotS";
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
		case '#':
			res = Tok_Hash; i += 1;
			break;
		case '&':
			res = Tok_Amp; i += 1;
			break;
		case '(':
			res = Tok_Lpar; i += 1;
			break;
		case ')':
			res = Tok_Rpar; i += 1;
			break;
		case '*':
			res = Tok_Star; i += 1;
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
		case '/':
			res = Tok_Slash; i += 1;
			break;
		case ':':
			res = Tok_Colon; i += 1;
			break;
		case ';':
			res = Tok_Semi; i += 1;
			break;
		case '<':
			if( at(str,i+1) == '>' ){
				res = Tok_LtGt; i += 2;
			} else {
				res = Tok_Lt; i += 1;
			}
			break;
		case '=':
			res = Tok_Eq; i += 1;
			break;
		case '>':
			res = Tok_Gt; i += 1;
			break;
		case 'A':
			switch( at(str,i+1) ){
			case 'B':
				if( at(str,i+2) == 'C' ){
					if( at(str,i+3) == 'D' ){
						res = Tok_ABCD; i += 4;
					}
				}
				break;
			case 'D':
				if( at(str,i+2) == 'D' ){
					switch( at(str,i+3) ){
					case 'A':
						res = Tok_ADDA; i += 4;
						break;
					case 'I':
						res = Tok_ADDI; i += 4;
						break;
					case 'Q':
						res = Tok_ADDQ; i += 4;
						break;
					case 'X':
						res = Tok_ADDX; i += 4;
						break;
					default:
						res = Tok_ADD; i += 3;
						break;
					}
				}
				break;
			case 'N':
				if( at(str,i+2) == 'D' ){
					if( at(str,i+3) == 'I' ){
						res = Tok_ANDI; i += 4;
					} else {
						res = Tok_AND; i += 3;
					}
				}
				break;
			case 'S':
				switch( at(str,i+2) ){
				case 'C':
					if( at(str,i+3) == 'I' ){
						if( at(str,i+4) == 'I' ){
							res = Tok_ASCII; i += 5;
						}
					}
					break;
				case 'L':
					res = Tok_ASL; i += 3;
					break;
				case 'R':
					res = Tok_ASR; i += 3;
					break;
				}
				break;
			}
			break;
		case 'B':
			switch( at(str,i+1) ){
			case 'C':
				switch( at(str,i+2) ){
				case 'C':
					res = Tok_BCC; i += 3;
					break;
				case 'H':
					if( at(str,i+3) == 'G' ){
						res = Tok_BCHG; i += 4;
					}
					break;
				case 'L':
					if( at(str,i+3) == 'R' ){
						res = Tok_BCLR; i += 4;
					}
					break;
				case 'S':
					res = Tok_BCS; i += 3;
					break;
				}
				break;
			case 'E':
				if( at(str,i+2) == 'Q' ){
					res = Tok_BEQ; i += 3;
				}
				break;
			case 'G':
				switch( at(str,i+2) ){
				case 'E':
					res = Tok_BGE; i += 3;
					break;
				case 'T':
					res = Tok_BGT; i += 3;
					break;
				}
				break;
			case 'H':
				switch( at(str,i+2) ){
				case 'I':
					res = Tok_BHI; i += 3;
					break;
				case 'S':
					res = Tok_BHS; i += 3;
					break;
				}
				break;
			case 'L':
				switch( at(str,i+2) ){
				case 'E':
					res = Tok_BLE; i += 3;
					break;
				case 'O':
					res = Tok_BLO; i += 3;
					break;
				case 'S':
					res = Tok_BLS; i += 3;
					break;
				case 'T':
					res = Tok_BLT; i += 3;
					break;
				}
				break;
			case 'M':
				if( at(str,i+2) == 'I' ){
					res = Tok_BMI; i += 3;
				}
				break;
			case 'N':
				if( at(str,i+2) == 'E' ){
					res = Tok_BNE; i += 3;
				}
				break;
			case 'P':
				if( at(str,i+2) == 'L' ){
					res = Tok_BPL; i += 3;
				}
				break;
			case 'R':
				if( at(str,i+2) == 'A' ){
					res = Tok_BRA; i += 3;
				}
				break;
			case 'S':
				switch( at(str,i+2) ){
				case 'E':
					if( at(str,i+3) == 'T' ){
						res = Tok_BSET; i += 4;
					}
					break;
				case 'R':
					res = Tok_BSR; i += 3;
					break;
				}
				break;
			case 'T':
				if( at(str,i+2) == 'S' ){
					if( at(str,i+3) == 'T' ){
						res = Tok_BTST; i += 4;
					}
				}
				break;
			case 'V':
				if( at(str,i+2) == 'C' ){
					res = Tok_BVC; i += 3;
				}
				break;
			case 'Y':
				if( at(str,i+2) == 'T' ){
					if( at(str,i+3) == 'E' ){
						res = Tok_BYTE; i += 4;
					}
				}
				break;
			}
			break;
		case 'C':
			switch( at(str,i+1) ){
			case 'H':
				if( at(str,i+2) == 'K' ){
					res = Tok_CHK; i += 3;
				}
				break;
			case 'L':
				if( at(str,i+2) == 'R' ){
					res = Tok_CLR; i += 3;
				}
				break;
			case 'M':
				if( at(str,i+2) == 'P' ){
					switch( at(str,i+3) ){
					case 'A':
						res = Tok_CMPA; i += 4;
						break;
					case 'I':
						res = Tok_CMPI; i += 4;
						break;
					case 'M':
						res = Tok_CMPM; i += 4;
						break;
					default:
						res = Tok_CMP; i += 3;
						break;
					}
				}
				break;
			}
			break;
		case 'D':
			switch( at(str,i+1) ){
			case 'B':
				switch( at(str,i+2) ){
				case 'E':
					if( at(str,i+3) == 'Q' ){
						res = Tok_DBEQ; i += 4;
					}
					break;
				case 'F':
					res = Tok_DBF; i += 3;
					break;
				case 'R':
					if( at(str,i+3) == 'A' ){
						res = Tok_DBRA; i += 4;
					}
					break;
				}
				break;
			case 'E':
				if( at(str,i+2) == 'F' ){
					res = Tok_DEF; i += 3;
				}
				break;
			case 'I':
				if( at(str,i+2) == 'V' ){
					switch( at(str,i+3) ){
					case 'S':
						res = Tok_DIVS; i += 4;
						break;
					case 'U':
						res = Tok_DIVU; i += 4;
						break;
					}
				}
				break;
			}
			break;
		case 'E':
			switch( at(str,i+1) ){
			case 'L':
				if( at(str,i+2) == 'S' ){
					if( at(str,i+3) == 'E' ){
						res = Tok_ELSE; i += 4;
					}
				}
				break;
			case 'N':
				if( at(str,i+2) == 'D' ){
					switch( at(str,i+3) ){
					case 'C':
						res = Tok_ENDC; i += 4;
						break;
					case 'M':
						res = Tok_ENDM; i += 4;
						break;
					default:
						res = Tok_END; i += 3;
						break;
					}
				}
				break;
			case 'O':
				if( at(str,i+2) == 'R' ){
					if( at(str,i+3) == 'I' ){
						res = Tok_EORI; i += 4;
					} else {
						res = Tok_EOR; i += 3;
					}
				}
				break;
			case 'Q':
				if( at(str,i+2) == 'U' ){
					res = Tok_EQU; i += 3;
				}
				break;
			case 'X':
				switch( at(str,i+2) ){
				case 'G':
					res = Tok_EXG; i += 3;
					break;
				case 'T':
					res = Tok_EXT; i += 3;
					break;
				}
				break;
			}
			break;
		case 'F':
			if( at(str,i+1) == 'U' ){
				if( at(str,i+2) == 'N' ){
					if( at(str,i+3) == 'C' ){
						res = Tok_FUNC; i += 4;
					}
				}
			}
			break;
		case 'I':
			switch( at(str,i+1) ){
			case 'F':
				res = Tok_IF; i += 2;
				break;
			case 'L':
				if( at(str,i+2) == 'L' ){
					if( at(str,i+3) == 'E' ){
						if( at(str,i+4) == 'G' ){
							if( at(str,i+5) == 'A' ){
								if( at(str,i+6) == 'L' ){
									res = Tok_ILLEGAL; i += 7;
								}
							}
						}
					}
				}
				break;
			case 'N':
				if( at(str,i+2) == 'C' ){
					if( at(str,i+3) == 'L' ){
						if( at(str,i+4) == 'U' ){
							if( at(str,i+5) == 'D' ){
								if( at(str,i+6) == 'E' ){
									res = Tok_INCLUDE; i += 7;
								}
							}
						}
					}
				}
				break;
			}
			break;
		case 'J':
			switch( at(str,i+1) ){
			case 'M':
				if( at(str,i+2) == 'P' ){
					res = Tok_JMP; i += 3;
				}
				break;
			case 'S':
				if( at(str,i+2) == 'R' ){
					res = Tok_JSR; i += 3;
				}
				break;
			}
			break;
		case 'L':
			switch( at(str,i+1) ){
			case 'E':
				if( at(str,i+2) == 'A' ){
					res = Tok_LEA; i += 3;
				}
				break;
			case 'I':
				switch( at(str,i+2) ){
				case 'N':
					if( at(str,i+3) == 'K' ){
						res = Tok_LINK; i += 4;
					}
					break;
				case 'S':
					if( at(str,i+3) == 'T' ){
						res = Tok_LIST; i += 4;
					}
					break;
				}
				break;
			case 'S':
				switch( at(str,i+2) ){
				case 'L':
					res = Tok_LSL; i += 3;
					break;
				case 'R':
					res = Tok_LSR; i += 3;
					break;
				}
				break;
			}
			break;
		case 'M':
			switch( at(str,i+1) ){
			case 'A':
				if( at(str,i+2) == 'C' ){
					if( at(str,i+3) == 'R' ){
						if( at(str,i+4) == 'O' ){
							if( at(str,i+5) == 'L' ){
								if( at(str,i+6) == 'I' ){
									if( at(str,i+7) == 'S' ){
										if( at(str,i+8) == 'T' ){
											res = Tok_MACROLIST; i += 9;
										}
									}
								}
							} else {
								res = Tok_MACRO; i += 5;
							}
						}
					}
				}
				break;
			case 'O':
				if( at(str,i+2) == 'V' ){
					if( at(str,i+3) == 'E' ){
						switch( at(str,i+4) ){
						case 'A':
							res = Tok_MOVEA; i += 5;
							break;
						case 'M':
							res = Tok_MOVEM; i += 5;
							break;
						case 'P':
							res = Tok_MOVEP; i += 5;
							break;
						case 'Q':
							res = Tok_MOVEQ; i += 5;
							break;
						default:
							res = Tok_MOVE; i += 4;
							break;
						}
					}
				}
				break;
			case 'U':
				if( at(str,i+2) == 'L' ){
					switch( at(str,i+3) ){
					case 'S':
						res = Tok_MULS; i += 4;
						break;
					case 'U':
						res = Tok_MULU; i += 4;
						break;
					}
				}
				break;
			}
			break;
		case 'N':
			switch( at(str,i+1) ){
			case 'B':
				if( at(str,i+2) == 'C' ){
					if( at(str,i+3) == 'D' ){
						res = Tok_NBCD; i += 4;
					}
				}
				break;
			case 'E':
				if( at(str,i+2) == 'G' ){
					if( at(str,i+3) == 'X' ){
						res = Tok_NEGX; i += 4;
					} else {
						res = Tok_NEG; i += 3;
					}
				}
				break;
			case 'O':
				switch( at(str,i+2) ){
				case 'L':
					if( at(str,i+3) == 'I' ){
						if( at(str,i+4) == 'S' ){
							if( at(str,i+5) == 'T' ){
								res = Tok_NOLIST; i += 6;
							}
						}
					}
					break;
				case 'M':
					if( at(str,i+3) == 'A' ){
						if( at(str,i+4) == 'C' ){
							if( at(str,i+5) == 'R' ){
								if( at(str,i+6) == 'O' ){
									if( at(str,i+7) == 'L' ){
										if( at(str,i+8) == 'I' ){
											if( at(str,i+9) == 'S' ){
												if( at(str,i+10) == 'T' ){
													res = Tok_NOMACROLIST; i += 11;
												}
											}
										}
									}
								}
							}
						}
					}
					break;
				case 'P':
					if( at(str,i+3) == 'A' ){
						if( at(str,i+4) == 'T' ){
							if( at(str,i+5) == 'C' ){
								if( at(str,i+6) == 'H' ){
									if( at(str,i+7) == 'L' ){
										if( at(str,i+8) == 'I' ){
											if( at(str,i+9) == 'S' ){
												if( at(str,i+10) == 'T' ){
													res = Tok_NOPATCHLIST; i += 11;
												}
											}
										}
									}
								}
							}
						}
					} else {
						res = Tok_NOP; i += 3;
					}
					break;
				case 'T':
					res = Tok_NOT; i += 3;
					break;
				}
				break;
			}
			break;
		case 'O':
			if( at(str,i+1) == 'R' ){
				switch( at(str,i+2) ){
				case 'G':
					res = Tok_ORG; i += 3;
					break;
				case 'I':
					res = Tok_ORI; i += 3;
					break;
				default:
					res = Tok_OR; i += 2;
					break;
				}
			}
			break;
		case 'P':
			switch( at(str,i+1) ){
			case 'A':
				if( at(str,i+2) == 'T' ){
					if( at(str,i+3) == 'C' ){
						if( at(str,i+4) == 'H' ){
							if( at(str,i+5) == 'L' ){
								if( at(str,i+6) == 'I' ){
									if( at(str,i+7) == 'S' ){
										if( at(str,i+8) == 'T' ){
											res = Tok_PATCHLIST; i += 9;
										}
									}
								}
							}
						}
					}
				}
				break;
			case 'E':
				if( at(str,i+2) == 'A' ){
					res = Tok_PEA; i += 3;
				}
				break;
			case 'R':
				if( at(str,i+2) == 'O' ){
					if( at(str,i+3) == 'C' ){
						res = Tok_PROC; i += 4;
					}
				}
				break;
			}
			break;
		case 'R':
			switch( at(str,i+1) ){
			case 'E':
				switch( at(str,i+2) ){
				case 'F':
					res = Tok_REF; i += 3;
					break;
				case 'S':
					if( at(str,i+3) == 'E' ){
						if( at(str,i+4) == 'T' ){
							res = Tok_RESET; i += 5;
						}
					}
					break;
				}
				break;
			case 'O':
				switch( at(str,i+2) ){
				case 'L':
					res = Tok_ROL; i += 3;
					break;
				case 'R':
					if( at(str,i+3) == 'G' ){
						res = Tok_RORG; i += 4;
					} else {
						res = Tok_ROR; i += 3;
					}
					break;
				case 'X':
					switch( at(str,i+3) ){
					case 'L':
						res = Tok_ROXL; i += 4;
						break;
					case 'R':
						res = Tok_ROXR; i += 4;
						break;
					}
					break;
				}
				break;
			case 'T':
				switch( at(str,i+2) ){
				case 'E':
					res = Tok_RTE; i += 3;
					break;
				case 'R':
					res = Tok_RTR; i += 3;
					break;
				case 'S':
					res = Tok_RTS; i += 3;
					break;
				}
				break;
			}
			break;
		case 'S':
			switch( at(str,i+1) ){
			case 'B':
				if( at(str,i+2) == 'C' ){
					if( at(str,i+3) == 'D' ){
						res = Tok_SBCD; i += 4;
					}
				}
				break;
			case 'E':
				if( at(str,i+2) == 'G' ){
					res = Tok_SEG; i += 3;
				}
				break;
			case 'N':
				if( at(str,i+2) == 'E' ){
					res = Tok_SNE; i += 3;
				}
				break;
			case 'T':
				if( at(str,i+2) == 'O' ){
					if( at(str,i+3) == 'P' ){
						res = Tok_STOP; i += 4;
					}
				}
				break;
			case 'U':
				if( at(str,i+2) == 'B' ){
					switch( at(str,i+3) ){
					case 'A':
						res = Tok_SUBA; i += 4;
						break;
					case 'I':
						res = Tok_SUBI; i += 4;
						break;
					case 'Q':
						res = Tok_SUBQ; i += 4;
						break;
					case 'X':
						res = Tok_SUBX; i += 4;
						break;
					default:
						res = Tok_SUB; i += 3;
						break;
					}
				}
				break;
			case 'W':
				if( at(str,i+2) == 'A' ){
					if( at(str,i+3) == 'P' ){
						res = Tok_SWAP; i += 4;
					}
				}
				break;
			}
			break;
		case 'T':
			switch( at(str,i+1) ){
			case 'A':
				if( at(str,i+2) == 'S' ){
					res = Tok_TAS; i += 3;
				}
				break;
			case 'I':
				if( at(str,i+2) == 'T' ){
					if( at(str,i+3) == 'L' ){
						if( at(str,i+4) == 'E' ){
							res = Tok_TITLE; i += 5;
						}
					}
				}
				break;
			case 'R':
				if( at(str,i+2) == 'A' ){
					if( at(str,i+3) == 'P' ){
						if( at(str,i+4) == 'V' ){
							res = Tok_TRAPV; i += 5;
						} else {
							res = Tok_TRAP; i += 4;
						}
					}
				}
				break;
			case 'S':
				if( at(str,i+2) == 'T' ){
					res = Tok_TST; i += 3;
				}
				break;
			}
			break;
		case 'U':
			if( at(str,i+1) == 'N' ){
				if( at(str,i+2) == 'L' ){
					if( at(str,i+3) == 'K' ){
						res = Tok_UNLK; i += 4;
					}
				}
			}
			break;
		case 'W':
			if( at(str,i+1) == 'O' ){
				if( at(str,i+2) == 'R' ){
					if( at(str,i+3) == 'D' ){
						res = Tok_WORD; i += 4;
					}
				}
			}
			break;
		case '^':
			res = Tok_Hat; i += 1;
			break;
		case '|':
			res = Tok_Bar; i += 1;
			break;
		case '~':
			res = Tok_Tilde; i += 1;
			break;
		}
		if(pos) *pos = i;
		return res;
	}
}