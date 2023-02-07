// This file was automatically generated by EbnfStudio; don't modify it!
#include "AsmSynTree.h"
using namespace Asm;

SynTree::SynTree(quint16 r, const Token& t ):d_tok(r){
	d_tok.d_lineNr = t.d_lineNr;
	d_tok.d_colNr = t.d_colNr;
	d_tok.d_sourcePath = t.d_sourcePath;
}

const char* SynTree::rToStr( quint16 r ) {
	switch(r) {
		case R_addrop: return "addrop";
		case R_argument: return "argument";
		case R_comment_: return "comment";
		case R_directive: return "directive";
		case R_expression: return "expression";
		case R_factor: return "factor";
		case R_filename: return "filename";
		case R_line: return "line";
		case R_macrocall_: return "macrocall";
		case R_macrodef: return "macrodef";
		case R_mnemonic: return "mnemonic";
		case R_op: return "op";
		case R_program: return "program";
		case R_reg: return "reg";
		case R_size: return "size";
		case R_statement: return "statement";
	default: if(r<R_First) return tokenTypeName(r); else return "";
}
}
