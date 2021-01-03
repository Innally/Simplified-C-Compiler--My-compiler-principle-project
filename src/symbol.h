#define MAX_ID 1024
#include "pch.h"
using namespace std;
typedef struct TAG_SYMBOL_ENTRY
{
	string name;
	int token;
	string type;
	int order;
} symbol_entry;

class symbol_table
{
private:
	symbol_entry table[MAX_ID];
	int size;

public:
	stack<int> scope;

	int lookup(string name);// look for a symbol,return the order 
	int insert(string name, int token,string tp); //add a symbol
	int gettoken(string name);// look for ,but return token
	string &getname(int pos); //return a name 
	int set_type(int pos, int type);// 
	string get_type(int pos);
	void print();

	int getsize(){return size;}
	int getorder(int pos){return table[pos].order;}
	void setorder(int pos,int od){table[pos].order=od;}
	symbol_table()
	{
		size=0;
		scope.push(0);
	}
};
