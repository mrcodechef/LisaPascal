#ifndef __ASM_SYNTREE__
#define __ASM_SYNTREE__
// This file was automatically generated by EbnfStudio; don't modify it!

#include <LisaPascal/AsmTokenType.h>
#include <LisaPascal/AsmToken.h>
#include <QList>

namespace Asm {

	struct SynTree {
		enum ParserRule {
			R_First = TT_Max + 1,
			R_addrop,
			R_argument,
			R_comment_,
			R_directive,
			R_expression,
			R_factor,
			R_filename,
			R_line,
			R_macrocall_,
			R_macrodef,
			R_mnemonic,
			R_op,
			R_program,
			R_reg,
			R_size,
			R_statement,
			R_term,
			R_Last
		};
		SynTree(quint16 r = Tok_Invalid, const Token& = Token() );
		SynTree(const Token& t ):d_tok(t){}
		~SynTree() { foreach(SynTree* n, d_children) delete n; }

		static const char* rToStr( quint16 r );

		Asm::Token d_tok;
		QList<SynTree*> d_children;
	};

}
#endif // __ASM_SYNTREE__
