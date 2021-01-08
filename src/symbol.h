#define MAX_ID 1024
#include "pch.h"
using namespace std;
typedef struct TAG_SYMBOL_ENTRY
{
	string name;
	int sconum;
	string type;
	int order;
} symbol_entry;

struct rodatatable
{
	string str;
	int seq;
};


class symbol_table
{
private:
	symbol_entry table[MAX_ID];
	rodatatable ro_table[MAX_ID];
	int size;
	int rosize;
public:
	stack<int> scope;
	int temp_var;
	int max_temp_var;
	int sconum ;
	int lookup(string name);// look for a symbol,return the order 
	int insert(string name, int token,string tp); //add a symbol
	int insert(string str);
	int get_sconum(int i);// look for ,but return token
	string &getname(int pos); //return a name 
	int set_type(int pos, int type);// 
	string get_type(int pos);
	void print();
	int findout(string);//look up is used for type check,but this is using for find a  pos; 

	int getrosize(){return rosize;}
	int getsize(){return size;}
	int getorder(int pos){return table[pos].order;}
	string getrodata(int i);
	void setorder(int pos,int od){table[pos].order=od;}
	int getroseq(int pos){return ro_table[pos].seq;}

	symbol_table()
	{
		size=0;
		scope.push(0);
		sconum=0;
		rosize=0;
		temp_var=0;
		max_temp_var=0;
	}
};
