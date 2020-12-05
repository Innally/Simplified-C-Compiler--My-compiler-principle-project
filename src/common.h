#ifndef COMMON_H
#define COMMON_H

#include "pch.h"
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::stack;
using std::unordered_map;
#define YYSTYPE TreeNode *

#include "./tree.h"
#include "./main.tab.h"

struct tokeninfo
{
    int scope;
    int line;
    string name;
    string type;
    void print()
    {   
        cout<<"line:"<<line<<" name:"<<name<<" scope:"<<scope<<" type:"<<type;
    }
};
static map<string,tokeninfo> tokentable;

#endif