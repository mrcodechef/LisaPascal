

// This file was automatically generated by Coco/R; don't modify it.
#include "AsmParser.h"
#include "AsmPpLexer.h"


namespace Asm {


static QString coco_string_create( const wchar_t* str )
{
    return QString::fromStdWString(str);
}

int Parser::peek( quint8 la )
{
	if( la == 0 )
		return d_cur.d_type;
	else if( la == 1 )
		return d_next.d_type;
	else
		return scanner->peekToken( la - 1 ).d_type;
}

void Parser::RunParser()
{
    d_stack.push(&d_root);
    Parse();
    d_stack.pop();
}
    
void Parser::SynErr(int n, const char* ctx) {
    if (errDist >= minErrDist)
       SynErr(d_next.d_lineNr, d_next.d_colNr, n, ctx, QString(), d_next.d_sourcePath);
	errDist = 0;
}

void Parser::SemErr(const char* msg) {
	if (errDist >= minErrDist)
		error(d_cur.d_lineNr, d_cur.d_colNr, msg, d_cur.d_sourcePath);
	errDist = 0;
}

void Parser::Get() {
	for (;;) {
		d_cur = d_next;
		d_next = scanner->nextToken();
        bool deliverToParser = false;
        switch( d_next.d_type )
        {
        case Tok_Invalid:
        	if( !d_next.d_val.isEmpty() )
                error( d_next.d_lineNr, d_next.d_colNr, d_next.d_val, d_next.d_sourcePath );
            // else errors already handeled in lexer
            break;
        case Tok_Comment:
            d_comments.append(d_next);
            break;
        default:
            deliverToParser = true;
            break;
        }

        if( deliverToParser )
        {
            if( d_next.d_type == Tok_Eof )
                d_next.d_type = _EOF;

            la->kind = d_next.d_type;
            if (la->kind <= maxT)
            {
                ++errDist;
                break;
            }
        }

		d_next = d_cur;
	}
}

void Parser::Expect(int n, const char* ctx ) {
	if (la->kind==n) Get(); else { SynErr(n, ctx); }
}

void Parser::ExpectWeak(int n, int follow) {
	if (la->kind == n) Get();
	else {
		SynErr(n);
		while (!StartOf(follow)) Get();
	}
}

bool Parser::WeakSeparator(int n, int syFol, int repFol) {
	if (la->kind == n) {Get(); return true;}
	else if (StartOf(repFol)) {return false;}
	else {
		SynErr(n);
		while (!(StartOf(syFol) || StartOf(repFol) || StartOf(0))) {
			Get();
		}
		return StartOf(syFol);
	}
}

void Parser::program() {
		d_stack.push(&d_root); 
		while (StartOf(1)) {
			line();
		}
		d_stack.pop(); 
}

void Parser::line() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_line, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		while (StartOf(2)) {
			if (StartOf(3)) {
				term();
				if (StartOf(4)) {
					size();
				}
				if (la->kind == _T_Lpar) {
					addrop();
				}
				if (la->kind == _T_Colon) {
					Get();
					addTerminal(); 
				}
			} else if (la->kind == _T_label) {
				Get();
				addTerminal(); 
				if (la->kind == _T_Colon) {
					Get();
					addTerminal(); 
				}
			} else if (la->kind == _T_Hash) {
				Get();
				addTerminal(); 
				expression();
			} else {
				Get();
				addTerminal(); 
				addrop();
			}
		}
		if (StartOf(5)) {
			if (StartOf(6)) {
				directive();
			} else if (StartOf(7)) {
				statement();
			} else {
				Get();
				addTerminal(); 
				argument();
				while (la->kind == _T_Comma) {
					Get();
					addTerminal(); 
					argument();
				}
			}
		}
		Expect(_T_eol,__FUNCTION__);
		addTerminal(); 
		d_stack.pop(); 
}

void Parser::term() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_term, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		factor();
		while (( peek(1) == _T_Amp || peek(1) == _T_Bar || peek(1) == _T_Eq || peek(1) == _T_Hat || peek(1) == _T_LtGt || peek(1) == _T_Minus || peek(1) == _T_Plus || peek(1) == _T_Slash || peek(1) == _T_Star || peek(1) == _T_Tilde ) && ( peek(2) == _T_ident || peek(2) == _T_Lt || peek(2) == _T_number || peek(2) == _T_Star || peek(2) == _T_string || peek(2) == _T_substitute ) ) {
			op();
			factor();
		}
		d_stack.pop(); 
}

void Parser::size() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_size, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		if (la->kind == _T_dotW) {
			Get();
			addTerminal(); 
		} else if (la->kind == _T_dotL) {
			Get();
			addTerminal(); 
		} else if (la->kind == _T_dotB) {
			Get();
			addTerminal(); 
		} else if (la->kind == _T_dotS) {
			Get();
			addTerminal(); 
		} else SynErr(155,__FUNCTION__);
		d_stack.pop(); 
}

void Parser::addrop() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_addrop, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		Expect(_T_Lpar,__FUNCTION__);
		addTerminal(); 
		expression();
		if (StartOf(4)) {
			size();
		}
		if (la->kind == _T_Comma) {
			Get();
			addTerminal(); 
			reg();
		}
		Expect(_T_Rpar,__FUNCTION__);
		addTerminal(); 
		if (StartOf(8)) {
			if (la->kind == _T_Plus) {
				Get();
				addTerminal(); 
			} else {
				size();
			}
		}
		d_stack.pop(); 
}

void Parser::expression() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_expression, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		if (la->kind == _T_Minus) {
			Get();
			addTerminal(); 
		}
		term();
		d_stack.pop(); 
}

void Parser::directive() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_directive, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		switch (la->kind) {
		case _T_FUNC: case _T_PROC: {
			if (la->kind == _T_PROC) {
				Get();
				addTerminal(); 
			} else {
				Get();
				addTerminal(); 
			}
			Expect(_T_ident,__FUNCTION__);
			addTerminal(); 
			if (la->kind == _T_Comma) {
				Get();
				addTerminal(); 
				Expect(_T_number,__FUNCTION__);
				addTerminal(); 
			}
			break;
		}
		case _T_DEF: case _T_REF: {
			if (la->kind == _T_DEF) {
				Get();
				addTerminal(); 
			} else {
				Get();
				addTerminal(); 
			}
			Expect(_T_ident,__FUNCTION__);
			addTerminal(); 
			while (la->kind == _T_Comma) {
				Get();
				addTerminal(); 
				Expect(_T_ident,__FUNCTION__);
				addTerminal(); 
			}
			break;
		}
		case _T_ASCII: case _T_SEG: case _T_TITLE: {
			if (la->kind == _T_SEG) {
				Get();
				addTerminal(); 
			} else if (la->kind == _T_ASCII) {
				Get();
				addTerminal(); 
			} else {
				Get();
				addTerminal(); 
			}
			if (la->kind == _T_string) {
				Get();
				addTerminal(); 
			} else if (la->kind == _T_substitute) {
				Get();
				addTerminal(); 
			} else SynErr(156,__FUNCTION__);
			break;
		}
		case _T_ELSE: case _T_END: case _T_ENDC: case _T_ENDM: case _T_LIST: case _T_MACROLIST: case _T_NOLIST: case _T_NOMACROLIST: case _T_NOPATCHLIST: case _T_PAGE: case _T_PATCHLIST: {
			switch (la->kind) {
			case _T_END: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_ENDM: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_ELSE: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_ENDC: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_LIST: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_NOLIST: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_MACROLIST: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_NOMACROLIST: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_PATCHLIST: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_NOPATCHLIST: {
				Get();
				addTerminal(); 
				break;
			}
			case _T_PAGE: {
				Get();
				addTerminal(); 
				break;
			}
			}
			break;
		}
		case _T_BYTE: case _T_LONG: case _T_WORD: {
			if (la->kind == _T_BYTE) {
				Get();
				addTerminal(); 
			} else if (la->kind == _T_WORD) {
				Get();
				addTerminal(); 
			} else {
				Get();
				addTerminal(); 
			}
			expression();
			while (la->kind == _T_Comma) {
				Get();
				addTerminal(); 
				expression();
			}
			break;
		}
		case _T_ALIGN: case _T_EQU: case _T_IF: case _T_ORG: case _T_RORG: {
			if (la->kind == _T_ORG) {
				Get();
				addTerminal(); 
			} else if (la->kind == _T_RORG) {
				Get();
				addTerminal(); 
			} else if (la->kind == _T_IF) {
				Get();
				addTerminal(); 
			} else if (la->kind == _T_EQU) {
				Get();
				addTerminal(); 
			} else {
				Get();
				addTerminal(); 
			}
			expression();
			break;
		}
		case _T_INCLUDE: {
			Get();
			addTerminal(); 
			filename();
			break;
		}
		case _T_MACRO: {
			macrodef();
			break;
		}
		default: SynErr(157,__FUNCTION__); break;
		}
		d_stack.pop(); 
}

void Parser::statement() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_statement, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		if (StartOf(9)) {
			mnemonic();
			if (StartOf(4)) {
				size();
			}
			if (StartOf(10)) {
				argument();
				while (la->kind == _T_Comma) {
					Get();
					addTerminal(); 
					argument();
				}
			}
		} else if (la->kind == _T_macrocall) {
			Get();
			addTerminal(); 
		} else SynErr(158,__FUNCTION__);
		d_stack.pop(); 
}

void Parser::argument() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_argument, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		if (peek(1) == _T_Minus && peek(2) == _T_Lpar ) {
			Expect(_T_Minus,__FUNCTION__);
			addTerminal(); 
			addrop();
		} else if (StartOf(11)) {
			expression();
			if (StartOf(4)) {
				size();
			}
			if (la->kind == _T_Lpar) {
				addrop();
			}
		} else if (la->kind == _T_Hash) {
			Get();
			addTerminal(); 
			expression();
		} else if (la->kind == _T_Lpar) {
			addrop();
		} else if (la->kind == _T_label) {
			Get();
			addTerminal(); 
		} else SynErr(159,__FUNCTION__);
		d_stack.pop(); 
}

void Parser::filename() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_filename, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		Expect(_T_ident,__FUNCTION__);
		addTerminal(); 
		while (la->kind == _T_Slash) {
			Get();
			addTerminal(); 
			Expect(_T_ident,__FUNCTION__);
			addTerminal(); 
		}
		d_stack.pop(); 
}

void Parser::macrodef() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_macrodef, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		Expect(_T_MACRO,__FUNCTION__);
		addTerminal(); 
		Expect(_T_ident,__FUNCTION__);
		addTerminal(); 
		d_stack.pop(); 
}

void Parser::mnemonic() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_mnemonic, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		switch (la->kind) {
		case _T_BEQ: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_LSR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BNE: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_LSL: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BGE: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BLE: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_DBF: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BMI: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ROR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ASL: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ASR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_DBRA: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BVC: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BPL: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BGT: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BLS: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BHI: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BLT: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_DBEQ: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_SNE: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ROL: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ROXR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ROXL: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BHS: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BLO: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BCC: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BCS: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ORI: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ANDI: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_SUBI: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ADDI: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_EORI: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_CMPI: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BTST: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BCHG: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BCLR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BSET: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_MOVEP: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_MOVEA: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_MOVE: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_NEGX: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_CLR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_NEG: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_NOT: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_EXT: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_NBCD: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_SWAP: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_PEA: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ILLEGAL: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_TAS: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_TST: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_TRAP: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_LINK: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_UNLK: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_RESET: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_NOP: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_STOP: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_RTE: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_RTS: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_TRAPV: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_RTR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_JSR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_JMP: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_MOVEM: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_LEA: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_CHK: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ADDQ: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_SUBQ: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BRA: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_BSR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_MOVEQ: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_DIVU: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_DIVS: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_SBCD: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_OR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_SUB: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_SUBX: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_SUBA: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_EOR: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_CMPM: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_CMP: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_CMPA: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_MULU: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_MULS: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ABCD: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_EXG: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_AND: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ADD: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ADDX: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_ADDA: {
			Get();
			addTerminal(); 
			break;
		}
		default: SynErr(160,__FUNCTION__); break;
		}
		d_stack.pop(); 
}

void Parser::reg() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_reg, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		if (la->kind == _T_ident) {
			Get();
			addTerminal(); 
			if (StartOf(4)) {
				size();
			}
		} else if (la->kind == _T_substitute) {
			Get();
			addTerminal(); 
		} else SynErr(161,__FUNCTION__);
		d_stack.pop(); 
}

void Parser::factor() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_factor, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		switch (la->kind) {
		case _T_ident: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_string: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_number: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Lt: {
			Get();
			addTerminal(); 
			expression();
			Expect(_T_Gt,__FUNCTION__);
			addTerminal(); 
			break;
		}
		case _T_substitute: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Star: {
			Get();
			addTerminal(); 
			break;
		}
		default: SynErr(162,__FUNCTION__); break;
		}
		d_stack.pop(); 
}

void Parser::op() {
		Asm::SynTree* n = new Asm::SynTree( Asm::SynTree::R_op, d_next ); d_stack.top()->d_children.append(n); d_stack.push(n); 
		switch (la->kind) {
		case _T_Plus: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Minus: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Tilde: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Hat: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Star: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Slash: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Bar: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Amp: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_Eq: {
			Get();
			addTerminal(); 
			break;
		}
		case _T_LtGt: {
			Get();
			addTerminal(); 
			break;
		}
		default: SynErr(163,__FUNCTION__); break;
		}
		d_stack.pop(); 
}




// If the user declared a method Init and a mehtod Destroy they should
// be called in the contructur and the destructor respctively.
//
// The following templates are used to recognize if the user declared
// the methods Init and Destroy.

template<typename T>
struct ParserInitExistsRecognizer {
	template<typename U, void (U::*)() = &U::Init>
	struct ExistsIfInitIsDefinedMarker{};

	struct InitIsMissingType {
		char dummy1;
	};
	
	struct InitExistsType {
		char dummy1; char dummy2;
	};

	// exists always
	template<typename U>
	static InitIsMissingType is_here(...);

	// exist only if ExistsIfInitIsDefinedMarker is defined
	template<typename U>
	static InitExistsType is_here(ExistsIfInitIsDefinedMarker<U>*);

	enum { InitExists = (sizeof(is_here<T>(NULL)) == sizeof(InitExistsType)) };
};

template<typename T>
struct ParserDestroyExistsRecognizer {
	template<typename U, void (U::*)() = &U::Destroy>
	struct ExistsIfDestroyIsDefinedMarker{};

	struct DestroyIsMissingType {
		char dummy1;
	};
	
	struct DestroyExistsType {
		char dummy1; char dummy2;
	};

	// exists always
	template<typename U>
	static DestroyIsMissingType is_here(...);

	// exist only if ExistsIfDestroyIsDefinedMarker is defined
	template<typename U>
	static DestroyExistsType is_here(ExistsIfDestroyIsDefinedMarker<U>*);

	enum { DestroyExists = (sizeof(is_here<T>(NULL)) == sizeof(DestroyExistsType)) };
};

// The folloing templates are used to call the Init and Destroy methods if they exist.

// Generic case of the ParserInitCaller, gets used if the Init method is missing
template<typename T, bool = ParserInitExistsRecognizer<T>::InitExists>
struct ParserInitCaller {
	static void CallInit(T *t) {
		// nothing to do
	}
};

// True case of the ParserInitCaller, gets used if the Init method exists
template<typename T>
struct ParserInitCaller<T, true> {
	static void CallInit(T *t) {
		t->Init();
	}
};

// Generic case of the ParserDestroyCaller, gets used if the Destroy method is missing
template<typename T, bool = ParserDestroyExistsRecognizer<T>::DestroyExists>
struct ParserDestroyCaller {
	static void CallDestroy(T *t) {
		// nothing to do
	}
};

// True case of the ParserDestroyCaller, gets used if the Destroy method exists
template<typename T>
struct ParserDestroyCaller<T, true> {
	static void CallDestroy(T *t) {
		t->Destroy();
	}
};

void Parser::Parse() {
	d_cur = Token();
	d_next = Token();
	Get();
	program();
	Expect(0,__FUNCTION__);
}

Parser::Parser(PpLexer *scanner) {
	maxT = 154;

	ParserInitCaller<Parser>::CallInit(this);
	la = &d_dummy;
	minErrDist = 2;
	errDist = minErrDist;
	this->scanner = scanner;
}

bool Parser::StartOf(int s) {
	const bool T = true;
	const bool x = false;

	static bool set[12][156] = {
		{T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,T,x, x,x,T,x, T,T,x,x, x,T,x,x, x,x,x,x, x,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,x, T,T,T,T, T,T,x,T, x,x,x,x, x,x,x,x},
		{x,x,T,x, x,x,T,x, x,T,x,x, x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,T,T,T, T,T,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,T,x, x,x,x,x, x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,T,T,T, T,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, T,T,T,T, x,x,x,x},
		{x,x,x,x, x,x,x,x, T,x,x,x, x,x,x,x, x,x,x,x, x,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,x, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,T, x,x,T,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,T,x, x,x,x,x, x,x,x,x, T,x,x,T, T,T,T,x, x,T,x,x, T,T,x,T, x,x,x,x, T,T,x,x, T,T,x,x, x,x,x,x, x,x,x,x, T,T,x,T, x,x,T,x, T,T,x,T, T,x,x,x, T,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,T,x,x, x,x,T,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,T,T,T, T,T,T,x, T,T,x,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,x,T, T,T,T,T, T,T,T,T, x,T,T,x, x,x,x,T, T,x,T,T, x,x,T,x, T,T,T,T, x,x,T,T, x,x,T,T, T,T,T,T, T,T,T,T, x,x,T,x, T,T,x,T, x,x,T,x, x,T,T,T, x,T,T,T, T,T,T,x, T,T,T,T, T,T,T,T, T,x,T,T, T,T,x,x, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, T,T,T,T, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,T,T,T, T,T,T,x, T,T,x,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,x,T, T,T,T,T, T,T,T,T, x,T,T,x, x,x,x,T, T,x,T,T, x,x,T,x, T,T,T,T, x,x,T,T, x,x,T,T, T,T,T,T, T,T,T,T, x,x,T,x, T,T,x,T, x,x,T,x, x,T,T,T, x,T,T,T, T,T,T,x, T,T,T,T, T,T,T,T, T,x,T,T, T,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,T,x, T,x,T,x, x,T,x,x, x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,T,T,T, T,T,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,T,x, x,T,x,x, x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,T,T,T, T,x,x,x, x,x,x,x, x,x,x,x}
	};



	return set[s][la->kind];
}

Parser::~Parser() {
	ParserDestroyCaller<Parser>::CallDestroy(this);
}

void Parser::SynErr(int line, int col, int n, const char* ctx, const QString& str, const QString& path ) {
	QString s;
	QString ctxStr;
	if( ctx )
		ctxStr = QString( " in %1" ).arg(ctx);
    if( n == 0 )
        s = QString("EOF expected%1").arg(ctxStr);
    else if( n < TT_Specials )
        s = QString("'%2' expected%1").arg(ctxStr).arg(tokenTypeString(n));
    else if( n <= TT_Max )
        s = QString("%2 expected%1").arg(ctxStr).arg(tokenTypeString(n));
    else
	switch (n) {
			case 0: s = coco_string_create(L"EOF expected"); break;
			case 1: s = coco_string_create(L"T_Literals_ expected"); break;
			case 2: s = coco_string_create(L"T_Hash expected"); break;
			case 3: s = coco_string_create(L"T_Amp expected"); break;
			case 4: s = coco_string_create(L"T_Lpar expected"); break;
			case 5: s = coco_string_create(L"T_Rpar expected"); break;
			case 6: s = coco_string_create(L"T_Star expected"); break;
			case 7: s = coco_string_create(L"T_Plus expected"); break;
			case 8: s = coco_string_create(L"T_Comma expected"); break;
			case 9: s = coco_string_create(L"T_Minus expected"); break;
			case 10: s = coco_string_create(L"T_Slash expected"); break;
			case 11: s = coco_string_create(L"T_Colon expected"); break;
			case 12: s = coco_string_create(L"T_Semi expected"); break;
			case 13: s = coco_string_create(L"T_Lt expected"); break;
			case 14: s = coco_string_create(L"T_LtGt expected"); break;
			case 15: s = coco_string_create(L"T_Eq expected"); break;
			case 16: s = coco_string_create(L"T_Gt expected"); break;
			case 17: s = coco_string_create(L"T_Hat expected"); break;
			case 18: s = coco_string_create(L"T_Bar expected"); break;
			case 19: s = coco_string_create(L"T_Tilde expected"); break;
			case 20: s = coco_string_create(L"T_Keywords_ expected"); break;
			case 21: s = coco_string_create(L"T_ABCD expected"); break;
			case 22: s = coco_string_create(L"T_ADD expected"); break;
			case 23: s = coco_string_create(L"T_ADDA expected"); break;
			case 24: s = coco_string_create(L"T_ADDI expected"); break;
			case 25: s = coco_string_create(L"T_ADDQ expected"); break;
			case 26: s = coco_string_create(L"T_ADDX expected"); break;
			case 27: s = coco_string_create(L"T_ALIGN expected"); break;
			case 28: s = coco_string_create(L"T_AND expected"); break;
			case 29: s = coco_string_create(L"T_ANDI expected"); break;
			case 30: s = coco_string_create(L"T_ASCII expected"); break;
			case 31: s = coco_string_create(L"T_ASL expected"); break;
			case 32: s = coco_string_create(L"T_ASR expected"); break;
			case 33: s = coco_string_create(L"T_BCC expected"); break;
			case 34: s = coco_string_create(L"T_BCHG expected"); break;
			case 35: s = coco_string_create(L"T_BCLR expected"); break;
			case 36: s = coco_string_create(L"T_BCS expected"); break;
			case 37: s = coco_string_create(L"T_BEQ expected"); break;
			case 38: s = coco_string_create(L"T_BGE expected"); break;
			case 39: s = coco_string_create(L"T_BGT expected"); break;
			case 40: s = coco_string_create(L"T_BHI expected"); break;
			case 41: s = coco_string_create(L"T_BHS expected"); break;
			case 42: s = coco_string_create(L"T_BLE expected"); break;
			case 43: s = coco_string_create(L"T_BLO expected"); break;
			case 44: s = coco_string_create(L"T_BLS expected"); break;
			case 45: s = coco_string_create(L"T_BLT expected"); break;
			case 46: s = coco_string_create(L"T_BMI expected"); break;
			case 47: s = coco_string_create(L"T_BNE expected"); break;
			case 48: s = coco_string_create(L"T_BPL expected"); break;
			case 49: s = coco_string_create(L"T_BRA expected"); break;
			case 50: s = coco_string_create(L"T_BSET expected"); break;
			case 51: s = coco_string_create(L"T_BSR expected"); break;
			case 52: s = coco_string_create(L"T_BTST expected"); break;
			case 53: s = coco_string_create(L"T_BVC expected"); break;
			case 54: s = coco_string_create(L"T_BYTE expected"); break;
			case 55: s = coco_string_create(L"T_CHK expected"); break;
			case 56: s = coco_string_create(L"T_CLR expected"); break;
			case 57: s = coco_string_create(L"T_CMP expected"); break;
			case 58: s = coco_string_create(L"T_CMPA expected"); break;
			case 59: s = coco_string_create(L"T_CMPI expected"); break;
			case 60: s = coco_string_create(L"T_CMPM expected"); break;
			case 61: s = coco_string_create(L"T_DBEQ expected"); break;
			case 62: s = coco_string_create(L"T_DBF expected"); break;
			case 63: s = coco_string_create(L"T_DBRA expected"); break;
			case 64: s = coco_string_create(L"T_DEF expected"); break;
			case 65: s = coco_string_create(L"T_DIVS expected"); break;
			case 66: s = coco_string_create(L"T_DIVU expected"); break;
			case 67: s = coco_string_create(L"T_ELSE expected"); break;
			case 68: s = coco_string_create(L"T_END expected"); break;
			case 69: s = coco_string_create(L"T_ENDC expected"); break;
			case 70: s = coco_string_create(L"T_ENDM expected"); break;
			case 71: s = coco_string_create(L"T_EOR expected"); break;
			case 72: s = coco_string_create(L"T_EORI expected"); break;
			case 73: s = coco_string_create(L"T_EQU expected"); break;
			case 74: s = coco_string_create(L"T_EXG expected"); break;
			case 75: s = coco_string_create(L"T_EXT expected"); break;
			case 76: s = coco_string_create(L"T_FUNC expected"); break;
			case 77: s = coco_string_create(L"T_IF expected"); break;
			case 78: s = coco_string_create(L"T_ILLEGAL expected"); break;
			case 79: s = coco_string_create(L"T_INCLUDE expected"); break;
			case 80: s = coco_string_create(L"T_JMP expected"); break;
			case 81: s = coco_string_create(L"T_JSR expected"); break;
			case 82: s = coco_string_create(L"T_LEA expected"); break;
			case 83: s = coco_string_create(L"T_LINK expected"); break;
			case 84: s = coco_string_create(L"T_LIST expected"); break;
			case 85: s = coco_string_create(L"T_LONG expected"); break;
			case 86: s = coco_string_create(L"T_LSL expected"); break;
			case 87: s = coco_string_create(L"T_LSR expected"); break;
			case 88: s = coco_string_create(L"T_MACRO expected"); break;
			case 89: s = coco_string_create(L"T_MACROLIST expected"); break;
			case 90: s = coco_string_create(L"T_MOVE expected"); break;
			case 91: s = coco_string_create(L"T_MOVEA expected"); break;
			case 92: s = coco_string_create(L"T_MOVEM expected"); break;
			case 93: s = coco_string_create(L"T_MOVEP expected"); break;
			case 94: s = coco_string_create(L"T_MOVEQ expected"); break;
			case 95: s = coco_string_create(L"T_MULS expected"); break;
			case 96: s = coco_string_create(L"T_MULU expected"); break;
			case 97: s = coco_string_create(L"T_NBCD expected"); break;
			case 98: s = coco_string_create(L"T_NEG expected"); break;
			case 99: s = coco_string_create(L"T_NEGX expected"); break;
			case 100: s = coco_string_create(L"T_NOLIST expected"); break;
			case 101: s = coco_string_create(L"T_NOMACROLIST expected"); break;
			case 102: s = coco_string_create(L"T_NOP expected"); break;
			case 103: s = coco_string_create(L"T_NOPATCHLIST expected"); break;
			case 104: s = coco_string_create(L"T_NOT expected"); break;
			case 105: s = coco_string_create(L"T_OR expected"); break;
			case 106: s = coco_string_create(L"T_ORG expected"); break;
			case 107: s = coco_string_create(L"T_ORI expected"); break;
			case 108: s = coco_string_create(L"T_PAGE expected"); break;
			case 109: s = coco_string_create(L"T_PATCHLIST expected"); break;
			case 110: s = coco_string_create(L"T_PEA expected"); break;
			case 111: s = coco_string_create(L"T_PROC expected"); break;
			case 112: s = coco_string_create(L"T_REF expected"); break;
			case 113: s = coco_string_create(L"T_RESET expected"); break;
			case 114: s = coco_string_create(L"T_ROL expected"); break;
			case 115: s = coco_string_create(L"T_ROR expected"); break;
			case 116: s = coco_string_create(L"T_RORG expected"); break;
			case 117: s = coco_string_create(L"T_ROXL expected"); break;
			case 118: s = coco_string_create(L"T_ROXR expected"); break;
			case 119: s = coco_string_create(L"T_RTE expected"); break;
			case 120: s = coco_string_create(L"T_RTR expected"); break;
			case 121: s = coco_string_create(L"T_RTS expected"); break;
			case 122: s = coco_string_create(L"T_SBCD expected"); break;
			case 123: s = coco_string_create(L"T_SEG expected"); break;
			case 124: s = coco_string_create(L"T_SNE expected"); break;
			case 125: s = coco_string_create(L"T_STOP expected"); break;
			case 126: s = coco_string_create(L"T_SUB expected"); break;
			case 127: s = coco_string_create(L"T_SUBA expected"); break;
			case 128: s = coco_string_create(L"T_SUBI expected"); break;
			case 129: s = coco_string_create(L"T_SUBQ expected"); break;
			case 130: s = coco_string_create(L"T_SUBX expected"); break;
			case 131: s = coco_string_create(L"T_SWAP expected"); break;
			case 132: s = coco_string_create(L"T_TAS expected"); break;
			case 133: s = coco_string_create(L"T_TITLE expected"); break;
			case 134: s = coco_string_create(L"T_TRAP expected"); break;
			case 135: s = coco_string_create(L"T_TRAPV expected"); break;
			case 136: s = coco_string_create(L"T_TST expected"); break;
			case 137: s = coco_string_create(L"T_UNLK expected"); break;
			case 138: s = coco_string_create(L"T_WORD expected"); break;
			case 139: s = coco_string_create(L"T_Specials_ expected"); break;
			case 140: s = coco_string_create(L"T_macrocall expected"); break;
			case 141: s = coco_string_create(L"T_number expected"); break;
			case 142: s = coco_string_create(L"T_string expected"); break;
			case 143: s = coco_string_create(L"T_ident expected"); break;
			case 144: s = coco_string_create(L"T_substitute expected"); break;
			case 145: s = coco_string_create(L"T_label expected"); break;
			case 146: s = coco_string_create(L"T_Comment expected"); break;
			case 147: s = coco_string_create(L"T_eol expected"); break;
			case 148: s = coco_string_create(L"T_dotW expected"); break;
			case 149: s = coco_string_create(L"T_dotL expected"); break;
			case 150: s = coco_string_create(L"T_dotB expected"); break;
			case 151: s = coco_string_create(L"T_dotS expected"); break;
			case 152: s = coco_string_create(L"T_Eof expected"); break;
			case 153: s = coco_string_create(L"T_MaxToken_ expected"); break;
			case 154: s = coco_string_create(L"??? expected"); break;
			case 155: s = coco_string_create(L"invalid size"); break;
			case 156: s = coco_string_create(L"invalid directive"); break;
			case 157: s = coco_string_create(L"invalid directive"); break;
			case 158: s = coco_string_create(L"invalid statement"); break;
			case 159: s = coco_string_create(L"invalid argument"); break;
			case 160: s = coco_string_create(L"invalid mnemonic"); break;
			case 161: s = coco_string_create(L"invalid reg"); break;
			case 162: s = coco_string_create(L"invalid factor"); break;
			case 163: s = coco_string_create(L"invalid op"); break;

		default:
		{
			s = QString( "generic error %1").arg(n);
		}
		break;
	}
    if( !str.isEmpty() )
        s = QString("%1 %2").arg(s).arg(str);
	error(line, col, s, path);
	//count++;
}

} // namespace

