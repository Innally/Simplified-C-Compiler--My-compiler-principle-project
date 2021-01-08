%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;

extern symbol_table symtbl;

%}

BLOCKCOMMENT "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/" 
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

INTEGER [0-9]+

CHAR \'.+\'
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
"string" return T_STRING;


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
"<" return SMALLER;
">=" return GORE;
"<=" return SORE;
"&&" return AND;//
"||" return OR;


"(" return LPAREN;
")" return RPAREN;
"true" {   
    TreeNode* node=new TreeNode(lineno,NODE_CONSTINT);
    node->var_name="true";
    node->type=TYPE_INT;
    node->attr.vali=1;
    yylval=node;
    return TRUE;
}

"false" {   
    TreeNode* node=new TreeNode(lineno,NODE_CONSTINT);
    node->var_name="false";
    node->attr.vali=0;
    node->type=TYPE_INT;
    yylval=node;
    return FALSE;
}

"{" {
    TreeNode* node=new TreeNode(lineno,NODE_BLOCK);
    node->var_name="new code block";
    yylval=node;
    int t=symtbl.getsize()-1;
    if (t<0)
        t=0;
    symtbl.scope.push(t);
    symtbl.sconum++;
    return LBRACE;
    }
"}" {
    symtbl.sconum--;
    int pos=symtbl.scope.top();
    if(pos>0)
    {
        string name=symtbl.getname(pos);
        string type=symtbl.get_type(pos);
        symtbl.insert(name,symtbl.sconum,type);
        symtbl.setorder(symtbl.getsize()-1,symtbl.getorder(pos));
        symtbl.scope.pop();

    }
    return RBRACE;
    }

{INTEGER} {
    //number int
    TreeNode* node = new TreeNode(lineno, NODE_CONSTINT);
    node->var_name="int";
    node->type = TYPE_INT;
    node->attr.vali = atoi(yytext);
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONSTCHAR);
    node->type = TYPE_CHAR;
    string temp=string(yytext);
    if(temp.length()==3)
        node->attr.vali = yytext[1];
    else {
        if(yytext[2]=='t')
            node->attr.vali = 9;
        if(yytext[2]=='n')
            node->attr.vali=10;
    }
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
    TreeNode* node = new TreeNode(lineno, NODE_CONSTSTRING);
    node->type=TYPE_STRING;
    node->var_name = string(yytext);
    symtbl.insert(node->var_name);
    node->attr.symtbl_seq=symtbl.getrosize()-1;//this seq is for getting the string later

    yylval = node;
    return STRING;
}

{WHILTESPACE} /* do nothing */

{EOL} {lineno++;}

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%