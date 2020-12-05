%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
int scope=0;


%}

BLOCKCOMMENT "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/" 
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

INTEGER [0-9]+

CHAR \'.?\'
STRING \".+\"

IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
%%

{BLOCKCOMMENT}  /* do nothing */
{LINECOMMENT}  /* do nothing */

"&" return REFERENCE;
"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"void" {return T_VOID;}

"=" return LOP_ASSIGN;

";" return  SEMICOLON;
"," return COMMA;
"if" return IF;
"else" return ELSE;
"while" return WHILE;
"return" return RETURN;
"printf" return PRINTF;
"scanf" return SCANF;
"for" return FOR;

"++" return ADDADD;//
"--" return MINUSMINUS;//
"+" return ADD;
"-" return MINUS;//
"*" return MULT;//
"/" return DIV;
"%" return MOD;//
"+=" return ADDSELF;//
"-=" return MINUSSELF;//


"!" return NOT;
"==" return EQUAL;
"!=" return NOTEQUAL;//
">" return GREATER;
"<" {return SMALLER;}
">=" return GORE;
"<=" return SORE;
"&&" return AND;//
"||" return OR;


"(" return LPAREN;
")" return RPAREN;
"{" {
    scope++;
    return LBRACE;
    }
"}" {
    scope--;
    return RBRACE;
    }

{INTEGER} {
    //number int
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->int_val = yytext[1];
    yylval = node;
    return CHAR;
}

{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->var_name = string(yytext);
    yylval = node;
    return STRING;
}

{WHILTESPACE} /* do nothing */

{EOL} {lineno++;}

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%