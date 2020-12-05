#include "common.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();

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
        root->genNodeId(0);
        root->printNodeInfo();
        root->printAST();
        map<string,tokeninfo>::iterator it = tokentable.begin();
        cout<<tokentable.size()<<endl;
	    while(it != tokentable.end()) {
		    cout<<it->first<<" ";
            it->second.print();
		    it++;
	    }
    }
    return 0;
}