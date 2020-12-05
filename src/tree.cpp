#include "tree.h"
#include<queue>
void TreeNode::addChild(TreeNode* child) {
  
    //cout<<"add child entered "<<child;cout<<endl;
    //printSpecialInfo();
    //cout<<endl;
    if(this->child!=nullptr)
        this->child->addSibling(child);
    else
    {
        this->child=child;
    }
}

void TreeNode::addSibling(TreeNode* sibling){
    //cout<<"add sibling entered "<<sibling;cout<<endl;
    //printSpecialInfo();
    //cout<<endl;
    TreeNode* t=this;
    int i=0;
    while(t->sibling)
    {
        i++;
        if(i>10)
            break;
        //cout<<t<<endl;
        t=t->sibling;
    }
    t->sibling=sibling;
    
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno=lineno;
    this->nodeType=type;
    //cout<<"new node created"<< this;
    //printSpecialInfo();
    //cout<<endl;
    
}

int TreeNode::genNodeId(int lastnodeid) {
     std::queue<TreeNode*> Q;
    TreeNode* i=child;
    
    if(i==nullptr)
        return lastnodeid;
    do{
        i->nodeID=++lastnodeid;
        Q.push(i);
        i=i->sibling;
        
    } while(i);

    while (!Q.empty())
    {
        i=Q.front();
        lastnodeid=i->genNodeId(lastnodeid);
        Q.pop();
    }
    return lastnodeid;
}

void TreeNode::printNodeInfo() {
    cout<<"@"<<nodeID<<" ";
    cout<<"Info: lineno:"<<lineno<<" type:";
    this->printSpecialInfo();
    cout<<" ";
    cout<<"Child: ";
    this->printChildrenId();
    cout<<endl;
}

void TreeNode::printChildrenId() {
    
    TreeNode* t=child;
    if(t)
    {
        std::cout<<t->nodeID<<" ";
    }
    else 
        return;
    while(t->sibling)
    {
        t=t->sibling;
        std::cout<<t->nodeID<<" ";
    }
}

void TreeNode::printAST() {
    std::queue<TreeNode*> Q;
    TreeNode* i=child;
    if(i==nullptr)
        return;
    do{
        i->printNodeInfo();
        Q.push(i);
        i=i->sibling;
    }while(i);

    while (!Q.empty())
    {
        i=Q.front();
        i->printAST();
        Q.pop();
    }
}


// You can output more info...
void TreeNode::printSpecialInfo() {
    switch(this->nodeType){
        case NODE_CONST:
            cout<<"const";
            break;
        case NODE_VAR:
            cout<<"variable";
            break;
        case NODE_EXPR:
            cout<<"expression";
            break;
        case NODE_STMT:
            cout<<sType2String(stype);
            break;
        case NODE_TYPE:
            cout<<nodeType2String(type);
            break;
        case NODE_PROG:
            cout<<"program";
            break;
        case NODE_OP:
            cout<<opType2String(optype);
            break;
        case NODE_FUNCTION:
            cout<<"function";
        default:
            break;
    }
}

string TreeNode::sType2String(StmtType type) {
    switch (type)
    {
    case STMT_SKIP:
        return "skip";
        break;
    case STMT_DECL:
        return "declare";
        break;
    case STMT_WHILE:
        return "while";
        break;
    case STMT_FOR:
        return "for";
        break;
    case STMT_PRINTF:
        return "printf";
        break;
    case STMT_SCANF:
        return "scanf";
        break;
    case STMT_RETURN:
        return "return";
        break;
    case STMT_IF:
        return"if";
        break;

    default:
        return "notype";
        break;
    }
}


string TreeNode::opType2String (OperatorType type){
     switch (type)
    {
    case OP_ADD:
        return "add";
        break;
    case OP_AND:
        return "and";
        break;
    case OP_ASSIGN:
        return "assign";
        break;
    case OP_DIV:
        return "divide";
        break;
    case OP_EQUAL:
        return "equal";
        break;
    case OP_GORE:
        return "greater or equal";
        break;
    case OP_GREATER:
        return "greater";
        break;
    case OP_MINUS:
        return "minus";
        break;
    case OP_MULT:
        return "multiply";
        break;
    case OP_NOT:
        return "not";
        break;
    case OP_NOTEQUAL:
        return "not";
        break;
    case OP_OR:
        return "or";
        break;
    case OP_SMALLER:
        return "smaller";
        break;
    case OP_SORE:
        return "smaller or equal";
        break;
    case OP_MOD:
        return " mode";
        break;
    case OP_MINUSSELF:
        return "minus itself then assign back.";
        break;
    case OP_ADDSELF:
        return "add itself then assign back.";
        break;
    default:
        return "notype";
        break;
    }
}

string TreeNode::nodeType2String (Type* type)
{
    return type->getTypeInfo();
}