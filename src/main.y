%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    extern int scope;
    int yylex();
    int yyerror( char const * );
    
%}
%start program

%token IF ELSE WHILE RETURN FOR

%token T_CHAR T_INT T_STRING T_BOOL  T_VOID

%token LOP_ASSIGN ADDSELF MINUSSELF

%token SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA

%token IDENTIFIER INTEGER CHAR BOOL STRING

%token TRUE FALSE

%token ADD MINUS MULT DIV MOD ADDADD MINUSMINUS

%token EQUAL NOT NOTEQUAL GREATER SMALLER GORE SORE OR AND

%token PRINTF SCANF 

%token REFERENCE POINTER

%left OR AND
%right NOT
%left ADD MINUS MULT DIV MOD
%left EQUAL NOTEQUAL 
%left GREATER SMALLER GORE SORE
%right LOP_ASSIGN
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE 
%right UMINUS

%%

program
: statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);};

statements
:  statement {$$=$1;}
|  statements statement {$$=$1; $$->addSibling($2);}

;

statement
    : SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
    | instruction {$$ = $1;}
    | if_else {$$=$1;}
    | while {$$=$1;}
    | LBRACE statements RBRACE {$$=$2;}
    | for {$$=$1;}
    | return {$$=$1;}
;

instruction
    : declaration SEMICOLON{$$=$1;}
    |printf SEMICOLON{$$=$1;}
    |scanf SEMICOLON{$$=$1;}
    |assign SEMICOLON{$$=$1;}
    |bool_statment SEMICOLON{$$=$1;}
    |fucntion_declaration{$$=$1;}
;

declaration
: T IDENTIFIERS LOP_ASSIGN expr{  // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;   

    string type=$1->type->getTypeInfo();
    string tempname=$2->var_name;
    if( (tokentable.find(tempname)!=tokentable.end()) && (tokentable[tempname].type==type) )
        //if the type and the name both are the same, then find a new name;
        if(tokentable.find(tempname)->second.scope==scope)
            while(tokentable.find(tempname)!=tokentable.end())
            {
                tempname+=".";
            }
    tokeninfo *t= new tokeninfo;
    t->name=tempname;
    t->scope=scope;
    t->type=type;
    t->line=lineno;
    t->print();
    cout<<endl;
    tokentable.insert(pair<string,tokeninfo >(tempname,*t));
} 
| T IDENTIFIERS {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;

   string type=$1->type->getTypeInfo();
    string tempname=$2->var_name;
    if( (tokentable.find(tempname)!=tokentable.end()) && (tokentable[tempname].type==type) )
    { //if the type and the name both are the same, then find a new name;
         if(tokentable.find(tempname)->second.scope==scope)
            while(tokentable.find(tempname)!=tokentable.end())
            {
                tempname+=".";
            }
    }
    tokeninfo *t= new tokeninfo;
    t->name=tempname;
    t->scope=scope;
    t->type=type;
    t->line=lineno;
    t->print();
    cout<<endl;
    tokentable.insert(pair<string,tokeninfo >(tempname,*t));   
}
;
fucntion_declaration
:
 T IDENTIFIER expr statement{
        TreeNode* node= new TreeNode(lineno,NODE_FUNCTION);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        node->addChild($4);
        $$=node;
    }
;

IDENTIFIERS
: IDENTIFIER{$$=$1;}
| IDENTIFIERS COMMA IDENTIFIER{$$=$1; $$->addSibling($2);}
;

assign
: expr LOP_ASSIGN expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_ASSIGN;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
| expr ADDSELF expr{
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_ADDSELF;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
}
| expr MINUSSELF expr{
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MINUSSELF;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
}
| expr ADDADD{
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_ADDADD;
        node->addChild($1);
        $$=node;   
}
| expr MINUSMINUS{
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MINUSMINUS;
        node->addChild($1);
        $$=node;   
}
;

expr
: IDENTIFIER {
    $$ = $1;
}
| MINUS expr %prec UMINUS {
    $$=$2;
    //remember to add minus atribute here.
}
| REFERENCE IDENTIFIER{
    $$=$2;
}
| INTEGER {
    $$ = $1;
}
| CHAR {
    $$ = $1;
}
| STRING {
    $$ = $1;
}
| expr ADD expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_ADD;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
| expr MINUS expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MINUS;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
| expr MULT expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MULT;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
| expr DIV expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_DIV;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
| expr MOD expr{
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MOD;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
}

| expr COMMA expr {$$=$1;$1->addSibling($3);}
| LPAREN expr RPAREN{$$=$2;}
| LPAREN RPAREN{TreeNode *node=new TreeNode(lineno,NODE_EXPR);$$=node; }

;


T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT; } 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE);  $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE);  $$->type = TYPE_BOOL;}
| T_STRING {$$ = new TreeNode(lineno, NODE_TYPE);  $$->type = TYPE_STRING;}
| T_VOID {$$ = new TreeNode(lineno, NODE_TYPE);  $$->type = TYPE_VOID;}
;


if_else
    : IF bool_statment statement %prec LOWER_THEN_ELSE {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_IF;
        node->addChild($2);
        node->addChild($3);
        $$=node;
        
    }
    | IF bool_statment statement ELSE statement {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_IF;
        node->addChild($2);
        node->addChild($3);
        node->addChild($5);
        $$=node;
        
    }
    ;
while
    : WHILE bool_statment statement {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_WHILE;
        node->addChild($2);
        node->addChild($3);
        $$=node;
        
    }
    ;
for 
    :FOR LPAREN  instruction instruction assign RPAREN statement{
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($3);
        node->addChild($4);
        node->addChild($5);
        node->addChild($7);
        $$=node;
        
    }
return
    : RETURN SEMICOLON {
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_RETURN;
        $$=$1;
        
    }
    | RETURN expr SEMICOLON{
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_RETURN;
        node->addChild($2);
        $$=$1;
        
    }
    | RETURN bool_statment SEMICOLON{
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_RETURN;
        node->addChild($2);
        $$=$1;
        
    }
bool_statment
    : LPAREN bool_statment RPAREN {$$=$2;}
    | bool_expr {$$=$1;}
    | bool_statment OR bool_statment {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_OR;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    ;
bool_expr
    : TRUE {$$=$1;}
    | FALSE {$$=$1;}
    | expr EQUAL expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
     |expr OR expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_OR;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | NOT bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_NOT;
        node->addChild($2);
        $$=node;
        
    }
    | expr NOTEQUAL expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_NOTEQUAL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        
    }
    | expr GREATER expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_GREATER;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        
    }
    | expr SMALLER expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SMALLER;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | expr GORE expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | expr SORE expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SORE;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    
    | expr AND expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_AND;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
     | bool_expr NOTEQUAL bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_NOTEQUAL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        
    }
    | bool_expr GREATER bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_GREATER;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        
    }
    | bool_expr SMALLER bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SMALLER;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | bool_expr GORE bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | bool_expr SORE bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SORE;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    
    | bool_expr AND bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_AND;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | bool_expr EQUAL bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    ;
printf
    : PRINTF expr {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_PRINTF;
        node->addChild($2);
        $$=node;
        
    }
    ;
scanf
    : SCANF expr {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_SCANF;
        node->addChild($2);
        $$=node;
    }
    ;

   
%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
