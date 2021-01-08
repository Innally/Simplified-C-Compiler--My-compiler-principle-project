#ifndef TREE_H
#define TREE_H

#include "symbol.h"
#include "pch.h"
#include "type.h"
extern symbol_table symtbl;

struct Label {
	string true_label;
	string false_label;
	string begin_label;
	string next_label;
};

enum NodeType
{
    
    NODE_CONST=1, 
    NODE_CONSTINT,
    NODE_CONSTCHAR,
    NODE_CONSTSTRING,

    NODE_MAIN,
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,
    NODE_FUNCTION,
    NODE_BLOCK,
    NODE_STMT,
    NODE_PROG,
    NODE_OP

};

enum OperatorType
{
    OP_ASSIGN=100,  // =
    OP_ADD,
    OP_MINUS,
    OP_MULT,
    OP_DIV,
    OP_MOD,
    OP_ADDSELF,
    OP_MINUSSELF,
    OP_ADDADD,
    OP_MINUSMINUS,
    OP_NOTEQUAL,
    OP_GREATER,
    OP_SMALLER,
    OP_GORE,
    OP_SORE,
    OP_AND,
    OP_OR,
    OP_NOT,
    OP_EQUAL,
};

// enum LogicalType
// {
//     OP_NOTEQUAL=200,
//     OP_GREATER,
//     OP_SMALLER,
//     OP_GORE,
//     OP_SORE,
//     OP_AND,
//     OP_OR,
//     OP_NOT,
//     OP_EQUAL,

// };

enum StmtType {
    STMT_SKIP=300,
    STMT_DECL,
    STMT_WHILE,
    STMT_FOR,
    STMT_IF,
    STMT_RETURN,
    STMT_SCANF,
    STMT_PRINTF,
    STMT_BLOCK,
    STMT_ASSIGN

};

union NodeAttr {
	int vali;
	char valc;
    bool valb;
	int symtbl_seq;
	
	NodeAttr(void){vali=0;};
	NodeAttr(int i)	{ vali = i; }
	NodeAttr(char c) { valc = c; }
    NodeAttr(bool b){ valb=b; }
};

struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;
    NodeAttr attr;
    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;
    Label label;
    int scopenum;

public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    string var_name;
    string str_val;
    bool negative;
    int temp_var;

public:
    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();

    int genNodeId(int);

public:
    static string nodeType2String (Type* type);
    static string opType2String(OperatorType type);
    static string sType2String (StmtType type);
    void L_typecheck();//logical expr check
    void A_typecheck();//arithmetic expr check
    void AS_typecheck(bool);//asign expr check
    void get_temp_var();

public:
    TreeNode(int lineno, NodeType type);
};



class tree
{
private:
	TreeNode *root;
	int node_seq = 0;
	int temp_var_seq = 0;
	int label_seq = 0;

private:
	string new_label(void);  
	void recursive_get_label(TreeNode *t);
	void stmt_get_label(TreeNode *t);
	void expr_get_label(TreeNode *t);
	void gen_header(ostream &out);
	void gen_decl(ostream &out);
    void gen_rodata(ostream &out);
    void gen_tempvar(ostream&out);
	void recursive_gen_code(ostream &out, TreeNode *t);
	void stmt_gen_code(ostream &out, TreeNode *t);
	void expr_gen_code(ostream &out, TreeNode *t);

public:
	void get_label(void);
	void gen_code(ostream &out);
    tree(TreeNode* t){root=t;}
};


#endif