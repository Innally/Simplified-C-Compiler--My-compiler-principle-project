#include <iostream>
//#include <string>

using namespace ::std;

#include "symbol.h"
 
symbol_table symtbl;

int symbol_table::lookup(string name)
{
	//cout<<"this time the stack top is "<<scope.top()<<endl;
	for (int i = size-1; i >=0; i--)
		{
			if (table[i].name == name )
			{
				i=table[i].order;
				if(scope.top()>i)
				 	return i-2048;
				else
				{
					return i;
				}	
			}
		}
	// cout<<"faild,there is no symbol"<<endl;
	return -1;
}

int symbol_table::insert(string name, int token,string tp)
{
	//cout<<"stack top is "<<scope.top()<<endl;
	if(scope.top())
	if (size >= 1024)
		return -1;
	table[size].name = name;
	table[size].token = token;
	table[size].type = tp;
	table[size].order=size;
	size++;
	return size - 1;
}

int symbol_table::gettoken(string name)
{
	for (int i = size-1; i >=0; i--)
		{
			if (table[i].name == name)
			i=table[i].order-1;
			return table[i].token;
		}
	return -1;
}

string& symbol_table::getname(int pos)
{
	return table[pos].name;
}

int symbol_table::set_type(int pos, int type)
{
	if (pos < 0 || pos >= size)
	{
		cerr << "Bad identifier" << endl;
		return -1;
	}

	table[pos].type = type;
	return 0;
}

string symbol_table::get_type(int pos)
{
	if (pos < 0 || pos >= size)
	{
		cerr << "Bad or not an identifier " <<pos<< endl;
		return "err";
	}

	return table[pos].type;
}
void symbol_table::print()
{
	for(int i=0;i<size;i++)
	{
		cout<<"name "<<table[i].name<<" token "<<table[i].token<<" type "<<table[i].type<<" order "<<table[i].order<<endl; 
	}
}