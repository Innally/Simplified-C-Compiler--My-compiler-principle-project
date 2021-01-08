%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );

    extern symbol_table symtbl;
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
%left ADD MINUS MULT DIV MOD
%left EQUAL NOTEQUAL 
%left GREATER SMALLER GORE SORE
%right NOT
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
    | block {$$=$1;}////////////////////////
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
: T IDENTIFIER LOP_ASSIGN expr{  // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_DECL;

    node->var_name="declaration";
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $4->stype=STMT_DECL;
    $4->get_temp_var();
    $$ = node;

    TreeNode *t=$2;
    string type=$1->type->getTypeInfo();
    string tempname=t->var_name;
    int index=symtbl.lookup(tempname);
    if(index<=-1)
        {
            symtbl.insert(tempname,symtbl.sconum,type);
            node->attr.symtbl_seq=symtbl.lookup(tempname);
        }
        // else if(symtbl.get_type(index)!=type)
        // {
        //     symtbl.insert(tempname,symtbl.sconum,type);
        // }
    else
        {
            //double declarations in one scope, erro
            cerr<<"you already declared "<<tempname<<tempname<<" in this scope."<<endl; 
        }
} 
| T IDENTIFIERS {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->var_name="declaration";
    node->stype=STMT_DECL;
    node->addChild($1);


    node->addChild($2);
    $$ = node;

    //give T's type to IDENTIFIERS
    TreeNode * t=$2;
    // insert into symbol table
    string type=$1->type->getTypeInfo();
    while(t)
    {
        string tempname=t->var_name;
        int index=symtbl.lookup(tempname);
        if(index<=-1)
            {
                symtbl.insert(tempname,symtbl.sconum,type);
            }
        // else if(symtbl.get_type(index)!=type)
        // {
        //     symtbl.insert(tempname,symtbl.sconum,type);
        // }
        else
        {
            //double declarations in one scope, erro
            cerr<<"you already declared "<<tempname<<" in this scope."<<lineno<<endl; 
        }
        t=t->sibling;
    }     
}
;

block
: LBRACE statements RBRACE{$$=$1;$$->stype=STMT_BLOCK;$1->addChild($2);}

fucntion_declaration
:
 T IDENTIFIER expr block{
        NodeType NODE_TYPE; 
        if($2->var_name=="main")
            NODE_TYPE=NODE_MAIN;
        else NODE_TYPE=NODE_FUNCTION;
        TreeNode* node= new TreeNode(lineno,NODE_TYPE);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        node->addChild($4);
        $$=node;

    // insert into symbol table
    if($2->var_name!="main")
    {
        string type=$1->type->getTypeInfo();
        TreeNode* t=$2;
            string tempname=t->var_name;
            int index=symtbl.lookup(tempname);
            if(index<=-1)
                symtbl.insert(tempname,symtbl.sconum,type);
            else
            {
                //double declarations in one scope, erro
                cerr<<"you already declared "<<tempname<<" in this scope."<<lineno<<endl; 
            }  
    }
}
;

IDENTIFIERS
: IDENTIFIER{$$=$1;}
| IDENTIFIERS COMMA IDENTIFIER{$$=$1; $$->addSibling($3);}
;

assign
: IDENTIFIER LOP_ASSIGN expr {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_ASSIGN;
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($3);
        //$3->get_temp_var(); 

        $$=node;
        node->get_temp_var(); 
        node->AS_typecheck(false);
    }
|IDENTIFIER LOP_ASSIGN assign {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_ASSIGN;
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($3);
        $3->nodeType=NODE_CONSTINT;
        $3->stype=STMT_DECL;
        $3->get_temp_var(); 
        $$=node;
        //node->get_temp_var(); 
        node->AS_typecheck(false);
        $3->nodeType=NODE_EXPR;
        $3->stype=STMT_ASSIGN;
    }
| IDENTIFIER ADDSELF expr{
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_ADDSELF;
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($3);
        //$3->get_temp_var();
        $$=node;
        node->get_temp_var(); 
        node->AS_typecheck(false);   

}
| IDENTIFIER MINUSSELF expr{
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_MINUSSELF;
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($3);
        //$3->get_temp_var();
        $$=node;
        node->get_temp_var(); 
        node->AS_typecheck(false);   
   
}
| IDENTIFIER ADDADD{
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_ADDADD;
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        $$=node;
        node->get_temp_var(); 
        node->AS_typecheck(true);   
   
}
| IDENTIFIER MINUSMINUS{
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_MINUSMINUS;
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        $$=node; 
        node->get_temp_var();   
        node->AS_typecheck(true);   
}
;



expr
: 
| MINUS expr %prec UMINUS {
    
    $$=$2;
    $$->negative=1;
    $$->type=TYPE_INT;
    $$->A_typecheck();// negative flag is 1 claims that this expr is negative expr,then check if it's char or string
    //remember to add minus atribute here.
}
| expr ADD expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_ADD;
        node->type=TYPE_INT;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        $$->A_typecheck();
   
    }
| expr MINUS expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MINUS;
        node->type=TYPE_INT;

        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        $$->A_typecheck();
   
    }

| expr COMMA expr {$$=$1;$1->addSibling($3);}
| LPAREN expr RPAREN{$$=$2;}
| LPAREN RPAREN{TreeNode *node=new TreeNode(lineno,NODE_EXPR);$$=node; }
| pri_expr {$$=$1;}
;


pri_expr
:
IDENTIFIER
{
    int ifexist=symtbl.lookup($1->var_name);
    if(ifexist==-1)
        cerr<<"IDENTIFIER "<<$1->var_name<<" not declared at line "<<$1->lineno<<endl;
    $$ = $1;
}
|LPAREN pri_expr RPAREN{$$=$2;}
| pri_expr MULT pri_expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MULT;
        node->type=TYPE_INT;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        $$->A_typecheck();   
    }
| pri_expr DIV pri_expr {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_DIV;
        node->type=TYPE_INT;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        $$->A_typecheck();   
    }
| pri_expr MOD pri_expr{
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MOD;
        node->type=TYPE_INT;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        $$->A_typecheck();   
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
| LPAREN expr RPAREN
{
    $$=$2;
}
| MINUS pri_expr %prec UMINUS {
    
    $$=$2;
    $$->negative=1;
    $$->type=TYPE_INT;
    $$->A_typecheck();// negative flag is 1 claims that this expr is negative expr,then check if it's char or string
    //remember to add minus atribute here.
};





T
: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT; } 
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
    : WHILE bool_statment block {
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
        $$=node;
        
    }
    | RETURN expr SEMICOLON{
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_RETURN;
        node->addChild($2);
        $$=node;
        
    }
    | RETURN bool_statment SEMICOLON{
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_RETURN;
        node->addChild($2);
        $$=node;
        
    }
bool_statment
    : LPAREN bool_statment RPAREN {$$=$2;}
    | bool_expr {$$=$1;}
    | andbool_expr{$$=$1;}
    | bool_statment OR bool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_OR;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        $$->L_typecheck();
    }
    | bool_statment OR andbool_expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_OR;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        $$->L_typecheck();
    }


andbool_expr
:
     LPAREN andbool_expr RPAREN {$$=$2;}
    | bool_expr AND bool_expr 
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_AND;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        node->L_typecheck();
    }


    ;
bool_expr
    : TRUE {$$=$1;}
    | FALSE {$$=$1;}
    | LPAREN bool_expr RPAREN {$$=$2;}
    | expr EQUAL expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        node->L_typecheck();
    }
    | not_bool_expr { $$=$1;}
    | expr NOTEQUAL expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_NOTEQUAL;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        node->L_typecheck();
    }
    | expr GREATER expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_GREATER;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        node->L_typecheck();
    }
    | expr SMALLER expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SMALLER;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        node->L_typecheck();
    }
    | expr GORE expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_GORE;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        node->L_typecheck();
    }
    | expr SORE expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SORE;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
        node->L_typecheck();
    }
    
    | bool_expr GREATER expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_GREATER;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
    }
    | bool_expr SMALLER expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SMALLER;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
    }
    | bool_expr GORE expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
    }
    | bool_expr SORE expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SORE;
        node->type=TYPE_BOOL;      
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
    }
    
    | bool_expr AND expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_AND;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
    }
    | bool_expr EQUAL expr {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        node->type=TYPE_BOOL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
        node->get_temp_var(); 
    }
    ;
not_bool_expr
:
    LPAREN not_bool_expr RPAREN{$$=$2;}
    |NOT bool_expr{
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_NOT;
        node->type=TYPE_BOOL;
        node->addChild($2);
        node->get_temp_var(); 
        $$=node;      
    };

    

printf
    : PRINTF expr {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_PRINTF;
        node->addChild($2);
        //add const

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
