#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"

enum NodeType
{
    NODE_CONST, 
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,
    NODE_FUNCTION,

    NODE_STMT,
    NODE_PROG,
    NODE_OP

};

enum OperatorType
{
    OP_ASSIGN,  // =
    OP_EQUAL,
    OP_ADD,
    OP_MINUS,
    OP_MULT,
    OP_DIV,
    OP_NOTEQUAL,
    OP_GREATER,
    OP_SMALLER,
    OP_GORE,
    OP_SORE,
    OP_AND,
    OP_OR,
    OP_NOT,
    OP_MOD,
    OP_ADDSELF,
    OP_MINUSSELF,
    OP_ADDADD,
    OP_MINUSMINUS,

};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
    STMT_WHILE,
    STMT_FOR,
    STMT_IF,
    STMT_RETURN,
    STMT_SCANF,
    STMT_PRINTF,

};

enum VarType{
    VAR_INTEGER,
    VAR_VOID,
    VAR_CHAR,
};

struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;

    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();

    int genNodeId(int);

public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    VarType vtype;
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;
    string var_name;
public:
    static string nodeType2String (Type* type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);


public:
    TreeNode(int lineno, NodeType type);
};

#endif