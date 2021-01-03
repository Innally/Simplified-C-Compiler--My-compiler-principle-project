#include "common.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();
extern symbol_table symtbl;

using namespace std;
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    yyparse();
    if(root != NULL) {
        //print root
        root->genNodeId(0);
        root->printNodeInfo();
        //print the other node
        root->printAST();
        symtbl.print();
    }
    ofstream out("test.s",std::ios::out);
    
    tree t(root);
    t.get_label();
    t.gen_code(out);
    return 0;
}