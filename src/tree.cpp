#include "tree.h"
#include<unistd.h>
void TreeNode::addChild(TreeNode* child) {
  
    if(this->child!=nullptr)
        this->child->addSibling(child);
    else
    {
        this->child=child;
    }
}

void TreeNode::addSibling(TreeNode* sibling){
    TreeNode* t=this;
    while(t->sibling)
    {
        t=t->sibling;
    }
    t->sibling=sibling;
    
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno=lineno;
    this->nodeType=type;
    negative=0;
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
    cout<<opType2String(this->optype)<< " ";
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


// You can coutput more info...
void TreeNode::printSpecialInfo() {
    switch(this->nodeType){
        case NODE_CONSTINT:
            cout<<"const INT";
            break;
        case NODE_CONSTCHAR:
            cout<<"const CHAR";
            break;
        case NODE_CONSTSTRING:
            cout<<"const STRING";
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
            break;
        case NODE_BLOCK:
            cout<<"block";
            break;
        case NODE_MAIN:
            cout<<"main";
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
        return"if_else";
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
    case OP_ASSIGN:
        return "assign";
        break;
    case OP_DIV:
        return "divide";
        break;
    case OP_MINUS:
        return "minus";
        break;
    case OP_MULT:
        return "multiply";
        break;
    case OP_MOD:
        return "mode";
        break;
    case OP_MINUSSELF:
        return "minus itself then assign back.";
        break;
    case OP_ADDSELF:
        return "add itself then assign back.";
        break;
    case OP_AND:
        return "and";
        break;
    case OP_GREATER:
        return "greater";
        break;
    case OP_SMALLER:
        return "smaller";
        break;
    case OP_SORE:
        return "smaller or equal";
        break;
    case OP_NOTEQUAL:
        return "not";
        break;
    case OP_OR:
        return "or";
        break;
    case OP_NOT:
        return "not";
        break;
    case OP_EQUAL:
        return "equal";
        break;
    case OP_GORE:
        return "greater or equal";
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

void TreeNode::L_typecheck()
{
    //-----------------
    //logic expr typecheck
    //---------------------
    // cout<<"l check"<<this->lineno<<endl;
    if(this->optype==OP_NOT)
    {
        if(child->nodeType==NODE_CONSTINT)//when it is a const number
            return;
        int index=symtbl.lookup(child->var_name);
        if(index<-1)
            index+=2048;
        if(index>-1 && (symtbl.get_type(index)=="char"||symtbl.get_type(index)=="string"))
            cerr<<"Boolen expression can not hold CHAR here at line "<<child->lineno<<endl;
    }
    else
    {
        TreeNode * child1,*child2;
        child1=this->child;
        child2=child1->sibling;
        if(child1->nodeType==NODE_CONSTINT);
        else
        {
            int index1=symtbl.lookup(child1->var_name);
            if(index1<-1)
                index1+=2048;
            if(index1>-1 && (symtbl.get_type(index1)=="char"||symtbl.get_type(index1)=="string"))
                cerr<<"Boolen expression can not hold CHAR here at line "<<child1->lineno<<endl;
        }
        if(child2->nodeType==NODE_CONSTINT);
        else
        {
            int index2=symtbl.lookup(child2->var_name);
            if(index2<-1)
                index2+=2048;
            if(index2>-1 && (symtbl.get_type(index2)=="char"||symtbl.get_type(index2)=="string"))
                cerr<<"Boolen expression can not hold CHAR here at line "<<child2->lineno<<endl;
        }  
    }
    
    
}

void TreeNode::A_typecheck()
{
    // cout<<"a_type"<<endl;
    if(this->negative)
    {
        if(this->nodeType==NODE_CONSTINT)
            {
                return;
            }
        int index=symtbl.lookup(this->var_name);
        if(index<-1)
            index+=2048;
        // cout<<"negative index"<<index<<"var name is"<<var_name<<endl;
        string temp = symtbl.get_type(index);
        if (temp!="int")
            cerr<<"After negative sign should be a real number at line "<<lineno<<endl;
    }
    else
    {
        TreeNode *child1,*child2;
        child1=this->child;
        child2=child1->sibling;
        int index1,index2;
        string type1,type2;

        if(child1->nodeType==NODE_CONSTINT)
        {
            type1="int";
        }
        else
        {
            index1=symtbl.lookup(child1->var_name);
            if(index1<-1)
                index1+=2048;
            if(index1>-1 && (symtbl.get_type(index1)=="char"||symtbl.get_type(index1)=="string"))
                cerr<<"char should not be in an arithmetic expression at line "<<child1->lineno<<"1"<<endl;
            else
            {
                type1="int";
            }
            
        }

        if(child2->nodeType==NODE_CONSTINT)
        {
            type2="int";
        }
        else
        {
            index2=symtbl.lookup(child2->var_name);
            if(index2<-1)
                index1+=2048;
            if(index2>-1 && (symtbl.get_type(index2)=="char"||symtbl.get_type(index2)=="string"))
                cerr<<"char should not be in an arithmetic expression at line "<<child2->lineno<<"2"<<endl;
            else
            {
                type2="int";
            }
            
        }

        if(type1!=type2)
            {
                cerr<<"char should not be in an arithmetic expression at line "<<child2->lineno<<"3"<<endl;
            }
    }

}

void TreeNode::AS_typecheck(bool unary)
{
    //-----------------
    //logic expr typecheck
    //---------------------
    if(unary)
    {
        //++ or --
        int pos=symtbl.lookup(child->var_name);
        if (pos<-1)
            pos+=2048;
        if(symtbl.get_type(pos)=="char" || symtbl.get_type(pos)=="string")
            cerr<<this->var_name<<" is a char type, can't do this ++ or -- operation at line "<<lineno<<endl;
    }
    else
    {
        //=,+=,-=,=
        TreeNode *child1,*child2;
        child1=child;
        child2=child1->sibling;
        string t1,t2;
        t1=child1->var_name;
        t2=child2->var_name;

        int pos1,pos2;
        pos1=symtbl.lookup(t1);
        pos2=symtbl.lookup(t2);
        if(pos1<-1)
            pos1+=2048;
        if(pos2<-1)
            pos2+=2048;
        t1=symtbl.get_type(pos1);
        if (child2->nodeType==NODE_CONSTINT)
            t2="int";
        else {
            t2=symtbl.get_type(pos2);
        }
        if(t1!=t2)
            ;//cerr<<child1->var_name<<" and "<<child2->var_name<<" are of diffrent type, can't do this assign operation at line "<<lineno<<endl;      
    }
    
}


void TreeNode::get_temp_var()
{
    if(this->nodeType==NODE_CONSTINT&&this->stype==STMT_DECL)
    {
        this->temp_var = symtbl.temp_var;
	    symtbl.temp_var++;
        if(symtbl.temp_var>symtbl.max_temp_var)
            symtbl.max_temp_var=symtbl.temp_var;
        return;
    }
	if (this->nodeType != NODE_EXPR&&this->nodeType!=NODE_OP)
		return;
	if (this->optype < OP_ASSIGN || this->optype > OP_EQUAL)
		return;
	TreeNode *arg1 = this->child;
	TreeNode *arg2;
    if(arg1->sibling!=nullptr)
        {arg2=arg1->sibling;}
    
	if (arg1->nodeType == NODE_EXPR ||arg1->nodeType == NODE_OP)
		symtbl.temp_var--;
	if ((arg1 && arg2 && arg2->nodeType == NODE_EXPR)||(arg1&& arg2 && arg2->nodeType == NODE_OP))
		symtbl.temp_var--;
	this->temp_var = symtbl.temp_var;
	symtbl.temp_var++;
    if(symtbl.temp_var>symtbl.max_temp_var)
        symtbl.max_temp_var=symtbl.temp_var;
}



//-----------------------get lable-----------------------------------
void tree::get_label(void)
{
	TreeNode *p = root;

	p->label.begin_label = "_start";
	recursive_get_label(p);
}


void tree::stmt_get_label(TreeNode *t)
{
	switch (t->stype)
	{
	case STMT_BLOCK:
		{
			 TreeNode *last;
			 TreeNode *p;
			for (p = t->child; p->stype == STMT_DECL; p = p->sibling) ;

			p->label.begin_label = t->label.begin_label;
			for (; p; p = p->sibling)
			{
				last = p;
				recursive_get_label(p);
			}

			t->label.next_label = last->label.next_label;
			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;
		}
		break;

	case STMT_WHILE:
		{
			 TreeNode *e = t->child;// this is the locical condition node
			 TreeNode *s = e->sibling;// this is the {} statements node

			if (t->label.begin_label == "")
				t->label.begin_label = new_label();
			s->label.next_label = t->label.begin_label;

			s->label.begin_label = e->label.true_label = new_label();

			if (t->label.next_label == "")
				t->label.next_label = new_label();
			e->label.false_label = t->label.next_label;
			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;

			recursive_get_label(e);
			recursive_get_label(s);
		}
        break;
    case STMT_IF:
        {
            TreeNode * cdt =t-> child; //this is the logical condition
            TreeNode * then=cdt->sibling;// this if is true block;
            TreeNode * el= then->sibling;// this is else block 

            if (t->label.begin_label == "")
				t->label.begin_label = new_label();
            if(t->label.next_label == "")
                t->label.next_label=new_label();
            then->label.begin_label=cdt->label.true_label=new_label();//if cdt is true then goto then

            if(el)//if else exist
                {
                    el->label.begin_label=cdt->label.false_label=new_label();// if cdt is false then goto else
                    el->label.next_label=t->label.next_label;
                }
            else{//no else
                cdt->label.false_label=t->label.next_label;
            }
            if(t->sibling)
                t->sibling->label.begin_label=t->label.next_label;
            recursive_get_label(cdt);
            recursive_get_label(then);
            if(el)
                recursive_get_label(el);
        }
        break;
    case STMT_FOR:
        {
            TreeNode * d1 =t-> child; //this is the first par in for: dec or assign instruction
            TreeNode * cdt =d1->sibling;// this the condition part in for
            TreeNode * as = cdt->sibling;// this is third pard in for 
            TreeNode * blcok = as->sibling;

            recursive_get_label(d1); //only execute once, actually not a part of the recursion 
            if(t->label.begin_label=="")
                t->label.begin_label=new_label();

            blcok->label.next_label=t->label.begin_label;
            blcok->label.begin_label=cdt->label.true_label=new_label();

            if(t->label.next_label=="")
                t->label.next_label=new_label();
            
            cdt->label.false_label=t->label.next_label;
            if(t->sibling)
                t->sibling->label.begin_label=t->label.next_label;

            recursive_get_label(cdt);
            recursive_get_label(as);
            recursive_get_label(blcok);
        }
        break;
    case STMT_RETURN:
        {
            if (t->label.begin_label=="")
                t->label.begin_label=new_label();
            if(t->label.next_label=="")
                t->label.next_label=new_label();
        }
        break;
    default:
        break;
	}
    if(t->sibling)
        recursive_get_label(t->sibling);
}

string tree::new_label(void)
{
    //get a new lable from label_seq,and label_seq++;
	char tmp[20];

	sprintf(tmp, "l%d", tree::label_seq);
	tree::label_seq++;
	return tmp;
}

void tree::recursive_get_label(TreeNode *t)
{
	if (t->nodeType == NODE_STMT)
		{stmt_get_label(t);}
	else if (t->nodeType == NODE_EXPR|| t->nodeType==NODE_OP)
		expr_get_label(t);
    else if(t->nodeType==NODE_FUNCTION|| t->nodeType==NODE_MAIN)
        {recursive_get_label(t->child->sibling->sibling->sibling);}
    else if(t->nodeType==NODE_PROG||t->nodeType==NODE_BLOCK)
        {recursive_get_label(t->child);}

}

void tree::expr_get_label(TreeNode *t)
{
	TreeNode *e1 = t->child;
	TreeNode *e2 = e1->sibling;
	if (t->type->getTypeInfo() != "bool")// if it's not boolean expr then recursive labeling ends
		{
            return;
        }
	switch (t->optype)
	{
	case OP_AND:
		e1->label.true_label = new_label();
        if(t->label.false_label=="")
            t->label.false_label=new_label();
        e2->label.begin_label=e1->label.true_label;
		e2->label.true_label = t->label.true_label;
		e1->label.false_label = e2->label.false_label = t->label.false_label;
		break;
	case OP_OR:
        e1->label.true_label=e2->label.true_label=t->label.true_label;
        e1->label.false_label=new_label();
        e2->label.begin_label=e1->label.false_label;
        e2->label.false_label=t->label.false_label;
		break;

    case OP_NOT:
        {  
            e1->label.true_label=t->label.false_label;
            e1->label.false_label=t->label.true_label;
        }
        break;
    default:
        break;
        /* ... */
	}
    //if it's not logical
	if (e1){
		recursive_get_label(e1);
    }
	if (e2)
    {
		recursive_get_label(e2);
    }
}

//-----------------------generate code.------------------
void tree::gen_header(ostream &out)
{
	cout << "# your asm code header here" << endl;
	/*your code here*/
}

void tree::gen_code(ostream &out)
{
	gen_header(cout);

	gen_decl(cout);//declaraiton
    gen_tempvar(cout);
    gen_rodata(cout);//rodata

    cout << endl << endl << "# your asm code here" << endl;
	cout << "\t.text" << endl;
    cout << "\t.globl main" << endl;
    cout<<"\t.type main, @function"<<endl;
	recursive_gen_code(cout, root);
	if (root->label.next_label != "")
		cout << root->label.next_label << ":" << endl;
	// cout << "\tret" << endl;
}

 void tree::gen_tempvar(ostream&out)
 {
     for(int i=0;i<symtbl.max_temp_var;i++)
     {
        cout<<"t"<<i<<":"<<endl;
        cout << "\t.zero\t4" << endl;
        cout << "\t.align\t4" << endl;
     }
 }


void tree::gen_decl(ostream &out)
{
    cout << endl << "# define your veriables and temp veriables here" << endl;
	cout << "\t.bss" << endl;

    int size=symtbl.getsize();
    int count=-1;
    int i=0;
    do
    {    
        if(symtbl.getorder(i)>count)// if this item on the table is the right order
        {
            if(symtbl.get_type(i)=="int"||symtbl.get_type(i)=="char")
            {
                cout << "_" << symtbl.getname(i)<<symtbl.get_sconum(i) << ":" << endl;
                cout << "\t.zero\t4" << endl;
                cout << "\t.align\t4" << endl;
                count=i;
            }
        }
        i++;
    }while(i<size);
    
}

void tree::gen_rodata(ostream &out)
{
    cout << endl << "# define your const string here" << endl;
	cout << "\t.section\t.rodata" << endl;
    cout<<"FORMAT:\n"<<"\t.asciz \"%s\\n\""<<endl;

    int rosize=symtbl.getrosize();
    for(int i=0;i<rosize;i++)
    {
        cout<<"STR"<<i<<":"<<endl;
        cout<<"\t.asciz "<<symtbl.getrodata(i)<<endl;
    }

}


void tree::recursive_gen_code(ostream &out, TreeNode *t)
{
    if(t==nullptr)
        return;
	else if (t->nodeType == NODE_STMT)
	{
		stmt_gen_code(cout, t);
	}
	else if (t->nodeType == NODE_EXPR ||t->nodeType==NODE_OP)
	{
		expr_gen_code(cout, t);
	}
    else if (t->nodeType == NODE_BLOCK)
    {
        stmt_gen_code(cout,t);
    }
    else if(t->nodeType == NODE_FUNCTION||t->nodeType == NODE_MAIN)
    {
        stmt_gen_code(cout,t);
    }
    else if (t->nodeType == NODE_PROG)
    {
        TreeNode *temp=t->child;
        while(temp)
        {
            recursive_gen_code(cout,temp);
            temp=temp->sibling;
        }
    }
}

void tree::stmt_gen_code(ostream &out, TreeNode *t)
{
    if(t->stype==STMT_ASSIGN)
    {
        expr_gen_code(cout,t);
        return;
    }
    if(t->nodeType==NODE_MAIN)
    {
        cout<<"main:"<<endl;
        recursive_gen_code(cout,t->child->sibling->sibling->sibling);
    }
	if (t->stype == STMT_BLOCK)// iterate every node of the tree
	{
        TreeNode* iter;
		for (iter=t->child ; iter; iter=iter->sibling)
		{
			recursive_gen_code(cout, iter);
			// for (TreeNode *p = iter->sibling; p; p = p->sibling)
			// 	recursive_gen_code(cout, p);
		}
	}
	if (t->stype == STMT_WHILE)
	{
		if (t->label.begin_label != "")
			cout << t->label.begin_label << ":" << endl;
		recursive_gen_code(cout, t->child);
        cout<<t->child->label.true_label<<":"<<endl;
		recursive_gen_code(cout, t->child->sibling);
		cout << "\tjmp " << t->label.begin_label << endl;
        cout<<t->label.next_label<<":"<<endl;
	}
	else if (t->stype == STMT_PRINTF)
	{
        TreeNode* child=t->child;
		stack<TreeNode*> s;
        while(child)
        {
            s.push(child);
            child=child->sibling;
        }
        bool f=0;// if there is only string ,no parameter flag
        int ssize=s.size();
        if(ssize==1)
            f=1;
        while(s.size()>1)
        {
            string varname=s.top()->var_name;
            int pos=symtbl.lookup(varname);
            if(pos<-1)
                pos+=2048;
            cout<<"\tpushl _"<<varname<<symtbl.get_sconum(pos)<<endl;
            s.pop();
	    }
        if(f)
        {
            if(t->nodeType==NODE_VAR)
                cout<<"\tpushl $"<<"FORMAT"<<endl;
        }
        int roseq=symtbl.getroseq(t->child->attr.symtbl_seq);
        cout<<"\tpushl $"<<"STR"<<roseq<<endl;
        cout<<"\tcall printf"<<endl;
        cout<<"\taddl $"<<ssize*4<<" ,%esp "<<endl;
        //recursive_gen_code(cout,t->sibling);
    }
    else if(t->stype==STMT_SCANF)
    {
        if (t->label.begin_label!=""){
            cout<<t->label.begin_label<<":"<<endl;
        }
        TreeNode*str=t->child;
        TreeNode*curr=str->sibling;
        //遍历获取输入变量个数，据此决定栈空间大小
        int idcount=0;
        while(curr !=nullptr )
        {
            idcount++ ;
            cout<<"\tleal _" <<curr->var_name<<symtbl.get_sconum(symtbl.findout(curr->var_name))<<" ,%eax" <<endl ;
            cout<<"\tpushl %eax" <<endl;
            curr=curr->sibling;
        }
        int roseq=symtbl.getroseq(str->attr.symtbl_seq);
        //cout<<"scanf "<<str->var_name<<roseq<<endl;
        cout<<"\tpushl $STR"<<roseq<<endl;
        cout<<"\tcall scanf" <<endl;
        cout<<"\taddl $"<<4* (idcount+1)<<" , %esp"<<endl;
    }
    else if(t->stype==STMT_DECL)
    {
        TreeNode* e2=t->child->sibling->sibling;
        if(e2!=nullptr)
        {
            TreeNode* e1=t->child->sibling;
            recursive_gen_code(cout,e2);
            cout << "\tmovl ";
            if (e2->nodeType == NODE_VAR)
                {
                    cout << "_" << e2->var_name<<symtbl.get_sconum(symtbl.findout(e2->var_name));
                }
            else if (e2->nodeType == NODE_CONSTINT)
                cout <<"$"<< e2->attr.vali;
            else cout << "t" << e2->temp_var;
            cout << ", %eax"<<endl ;
            cout<<"\tmovl %eax,";
            if (e1->nodeType == NODE_VAR)// ID
                cout << "_" << e1->var_name<<symtbl.get_sconum(symtbl.findout(e1->var_name));
            else if (e1->nodeType == NODE_CONSTINT)// CONST INT
                cout <<"$" << e1->attr.vali;
            else cout << "t" << e1->temp_var;// A TEMP RESULT
            cout<<endl;

        }
    }
    else if(t->stype==STMT_IF)
    {
        if (t->label.begin_label != "")
			cout << t->label.begin_label << ":" << endl;
        recursive_gen_code(cout, t->child);//
		cout << t->child->label.true_label << ":" << endl;//true lable
		recursive_gen_code(cout, t->child->sibling);
        cout<<"\tjmp "<<t->label.next_label<<endl;
        cout << t->child->label.false_label << ":" << endl;//false LABLE
        if(t->child->sibling->sibling)
        {
            recursive_gen_code(cout,t->child->sibling->sibling);
            cout<<t->label.next_label<<":"<<endl;
        }
    }
    else if(t->stype==STMT_FOR)
    {
        recursive_gen_code(cout, t->child);
        if (t->label.begin_label != "")
			cout << t->label.begin_label << ":" << endl;
		recursive_gen_code(cout, t->child->sibling);
        cout<<t->child->sibling->label.true_label<<":"<<endl;
        recursive_gen_code(cout,t->child->sibling->sibling);
        recursive_gen_code(cout,t->child->sibling->sibling->sibling);
        cout << "\tjmp " << t->label.begin_label << endl;
        cout<<t->label.next_label<<":"<<endl;

    }

    else if(t->stype==STMT_RETURN)
    {
        if(t->label.begin_label!="")
                cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,t->child);
        cout << "\tret "<<endl ;
    }
    else if(t->optype==OP_ASSIGN)
    {
        expr_gen_code(cout,t);
        //recursive_gen_code(cout,t->sibling);
    }
    /* ... */
}


void tree::expr_gen_code(ostream &out, TreeNode *t)
{

	TreeNode *e1 = t->child;
	TreeNode *e2 = e1->sibling;
    string truelable=e1->label.false_label;
    string name1=e1->var_name;
    string name2;
    if(e2)
        {name2=e2->var_name;}
	switch (t->optype)
	{
    case OP_ASSIGN://
        recursive_gen_code(cout,e2);
        if(e2->nodeType==NODE_CONSTCHAR)
        {
            cout<<"\tmovl $"<<e2->attr.vali<<",_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
        }
        else{
            if(e2->negative )
                {
                    if(e2->nodeType==NODE_VAR)
                    {
                        cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                        cout<<"\tnegl %ecx"<<endl;
                        cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                    }
                    else if(e2->nodeType!=NODE_CONSTINT)
                    {
                        cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                        cout<<"\tnegl %ecx"<<endl;
                        cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                    }
                }
                cout << "\tmovl ";
                if (e2->nodeType == NODE_VAR)
                    {
                        cout << "_" << name2<<symtbl.get_sconum(symtbl.findout(name2));
                    }
                else if (e2->nodeType == NODE_CONSTINT)
                {
                    cout <<"$" ;
                    if(e2->negative==1)
                        cout<<"-";
                    cout<< e2->attr.vali;
                }
                else cout << "t" << e2->temp_var;
                cout << ", %eax"<<endl ;
                cout<<"\tmovl %eax,";
                if (e1->nodeType == NODE_VAR)// ID
                    cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
                else if (e1->nodeType == NODE_CONSTINT)
                {
                    cout <<"$" ;
                    if(e1->negative==1)
                        cout<<"-";
                    cout<< e1->attr.vali;
                }
                else cout << "t" << e1->temp_var;// A TEMP RESULT
                cout<<endl;
                if(t->nodeType==NODE_EXPR)
                    {cout<<"\tmovl %eax"<<",t"<<t->temp_var<<endl;}
                if(e2->negative )
                {
                    if(e2->nodeType==NODE_VAR)
                    {
                        cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                        cout<<"\tnegl %ecx"<<endl;
                        cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                    }
                    else if(e2->nodeType!=NODE_CONSTINT)
                    {
                        cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                        cout<<"\tnegl %ecx"<<endl;
                        cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                    }
                }
        }
		break;

	case OP_ADD://
        // if(t->child->nodeType==NODE_EXPR)
        recursive_gen_code(cout,e1);
        if(e1->negative)
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }

        recursive_gen_code(cout,e2);
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
		cout << "\tmovl ";
		if (e1->nodeType == NODE_VAR)// ID
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
        else if (e1->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e1->negative==1)
                cout<<"-";
            cout<< e1->attr.vali;
        }
		else cout << "t" << e1->temp_var;// A TEMP RESULT
		cout << ", %eax" <<endl;
		cout << "\taddl ";
		if (e2->nodeType == NODE_VAR)
			cout << "_" << name2<<symtbl.get_sconum(symtbl.findout(name2));
        else if (e2->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e2->negative==1)
                cout<<"-";
            cout<< e2->attr.vali;
        }
		else cout << "t" << e2->temp_var;
		cout << ", %eax" << endl;
		cout << "\tmovl %eax, t" << t->temp_var << endl;
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        if(e1->negative)
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }

		break;
    case OP_AND://
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,e1);
        // cout << "\tmovl ";
        // if (e1->nodeType == NODE_VAR)// ID
		// 	cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
		// else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        // 	cout <<"$" << e1->attr.vali;
		// else cout << "t" << e1->temp_var;// A TEMP RESULT
        // cout << ", %eax" <<endl;
        // cout<<"\tcompl %eax,0"<<endl;
        // cout<<"\tje "<<t->label.false_label<<endl;//if the first expr is not true, then jmp to false
        // cout<<"\tjmp "<<e1->label.true_label<<endl;
        recursive_gen_code(cout,e2);
        // cout << "\tmovl ";
		// if (e2->nodeType == NODE_VAR)
		// 	cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name2));
		// else if (e2->nodeType == NODE_CONSTINT)
		// 	cout <<"$" << e2->attr.vali;
		// else cout << "t" << e2->temp_var;
		// cout << ", %eax" << endl;
        // cout<<"\tcompl %eax,0"<<endl;
        // cout<<"\tje "<<t->label.false_label<<endl;//if the second expr is not true, then jmp to false
        // cout<<"\tjmp "<<t->label.true_label<<endl;// i they both true, then goto true
        break;
	case OP_ADDADD://
        cout<<"\tincl ";
        if (e1->nodeType == NODE_VAR)// ID
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
		else cout << "t" << e1->temp_var;// A TEMP RESULT
        cout<<endl;
		break;
    case OP_ADDSELF://
        recursive_gen_code(cout,e2);
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        cout << "\tmovl ";
        if (e2->nodeType == NODE_VAR)
			cout << "_" << name2<<symtbl.get_sconum(symtbl.findout(name2));
	    else if (e2->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e2->negative==1)
                cout<<"-";
            cout<< e2->attr.vali;
        }
		else cout << "t" << e2->temp_var;// A TEMP RESULT
        cout << ", %eax" <<endl;
        cout << "\taddl ";
		cout << "%eax,";
        if (e1->nodeType == NODE_VAR)
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
        else if (e1->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e1->negative==1)
                cout<<"-";
            cout<< e1->attr.vali;
        }
		else cout << "t" << e1->temp_var;
        cout << endl;
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }

		break;
    case OP_DIV://
        recursive_gen_code(cout,e1);
        if(e1->negative )
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }
        recursive_gen_code(cout,e2);
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
         cout << "\tmovl ";
        if (e1->nodeType == NODE_VAR)// ID
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
		else if (e1->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e1->negative==1)
                cout<<"-";
            cout<< e1->attr.vali;
        }
		else cout << "t" << e1->temp_var;// A TEMP RESULT
        cout << ", %eax" <<endl;
        cout<<"\tcltd\n";
        cout<<"\tmovl ";
		if (e2->nodeType == NODE_VAR)
			cout << "_" << name2<<symtbl.get_sconum(symtbl.findout(name2));
		else if (e2->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e2->negative==1)
                cout<<"-";
            cout<< e2->attr.vali;
        }
		else cout << "t" << e2->temp_var;
		cout << ", %ecx" << endl;
        cout << "\tidivl %ecx\n ";
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        if(e1->negative)
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }

		cout << "\tmovl %eax, t" << t->temp_var << endl;

		break;
    case OP_EQUAL://////////////////
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,e1);
        recursive_gen_code(cout,e2);
        ////////////////////////////////////////////////////////////////////
        cout<<"\t";
		if (e2->nodeType == NODE_VAR)
			{
                cout << "movl _" << name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ebx";

            }
		else if (e2->nodeType == NODE_CONSTINT)
			{
                cout<<"movl $";
                if(e2->negative==1)
                    cout<<"-";
                cout<<e2->attr.vali<<",%ebx";

            }
		else {

            cout << "movl t" << e2->temp_var<<",%ebx";
        }
        cout<<endl;
        ///////////////////////////////////////////////////
        if (e1->nodeType == NODE_VAR)
			{
                cout << "\tmovl _" << name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%eax";

            }
		else if (e1->nodeType == NODE_CONSTINT)
			{
                cout<<"\tmovl $";
                if(e1->negative==1)
                    cout<<"-";
                cout<<e1->attr.vali<<",%eax"<<endl;
            }
		else {

            cout << "movl t" << e1->temp_var<<",%eax";
        }
        cout << "\n\tcmpl %ebx,%eax";
		cout <<"\n\tje "<<t->label.true_label << endl;
        cout <<"\tjmp "<<t->label.false_label<<endl;
		break;



    case OP_GORE://
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,e1);
        recursive_gen_code(cout,e2);
        ////////////////////////////////////////////////////////////////////
        cout<<"\t";
		if (e2->nodeType == NODE_VAR)
			{
                cout << "movl _" << name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ebx";

            }
		else if (e2->nodeType == NODE_CONSTINT)
			{
                cout<<"movl $";
                if(e2->negative==1)
                    cout<<"-";
                cout<<e2->attr.vali<<",%ebx";

            }
		else {

            cout << "movl t" << e2->temp_var<<",%ebx";
        }
        cout<<endl;
        ///////////////////////////////////////////////////
        if (e1->nodeType == NODE_VAR)
			{
                cout << "\tmovl _" << name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%eax";

            }
		else if (e1->nodeType == NODE_CONSTINT)
			{
                cout<<"\tmovl $";
                if(e1->negative==1)
                    cout<<"-";
                cout<<e1->attr.vali<<",%eax"<<endl;
            }
		else {

            cout << "movl t" << e1->temp_var<<",%eax";
        }
        cout << "\n\tcmpl %ebx,%eax";
		cout <<"\n\tjge "<<t->label.true_label << endl;
        cout <<"\tjmp "<<t->label.false_label<<endl;
		break;


    case OP_GREATER://
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,e1);
        recursive_gen_code(cout,e2);
        ////////////////////////////////////////////////////////////////////
        cout<<"\t";
		if (e2->nodeType == NODE_VAR)
			{
                cout << "movl _" << name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ebx";

            }
		else if (e2->nodeType == NODE_CONSTINT)
			{
                cout<<"movl $";
                if(e2->negative==1)
                    cout<<"-";
                cout<<e2->attr.vali<<",%ebx";

            }
		else {

            cout << "movl t" << e2->temp_var<<",%ebx";
        }
        cout<<endl;
        ///////////////////////////////////////////////////
        if (e1->nodeType == NODE_VAR)
			{
                cout << "\tmovl _" << name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%eax";

            }
		else if (e1->nodeType == NODE_CONSTINT)
			{
                cout<<"\tmovl $";
                if(e1->negative==1)
                    cout<<"-";
                cout<<e1->attr.vali<<",%eax"<<endl;
            }
		else {

            cout << "movl t" << e1->temp_var<<",%eax";
        }
        cout << "\n\tcmpl %ebx,%eax";
		cout <<"\n\tjg "<<t->label.true_label << endl;
        cout <<"\tjmp "<<t->label.false_label<<endl;

		break;


    case OP_MINUS://
        recursive_gen_code(cout,e1);
        if(e1->negative )
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }
        recursive_gen_code(cout,e2);
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        cout << "\tmovl ";
        if (e1->nodeType == NODE_VAR)// ID
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
		else if (e1->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e1->negative==1)
                cout<<"-";
            cout<< e1->attr.vali;
        }
		else cout << "t" << e1->temp_var;// A TEMP RESULT
        cout << ", %eax" <<endl;
        cout << "\tsubl ";
		if (e2->nodeType == NODE_VAR)
			cout << "_" << name2<<symtbl.get_sconum(symtbl.findout(name2));
		else if (e2->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e2->negative==1)
                cout<<"-";
            cout<< e2->attr.vali;
        }
		else cout << "t" << e2->temp_var;
		cout << ", %eax" << endl;
		cout << "\tmovl %eax, t" << t->temp_var << endl;
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        if(e1->negative)
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }

        break;


    case OP_MINUSMINUS://
        cout<<"\tdecl ";
        if (e1->nodeType == NODE_VAR)// ID
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
		else cout << "t" << e1->temp_var;// A TEMP RESULT
        cout<<endl;
		break;



    case OP_MINUSSELF://
        recursive_gen_code(cout,e2);
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        cout << "\tmovl ";
        if (e2->nodeType == NODE_VAR)// ID
			cout << "_" << name2<<symtbl.get_sconum(symtbl.findout(name2));
		else if (e2->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e2->negative==1)
                cout<<"-";
            cout<< e2->attr.vali;
        }
		else cout << "t" << e2->temp_var;// A TEMP RESULT
        cout << ", %eax" <<endl;
        cout << "\tsubl ";
		cout << "%eax,";
        if (e1->nodeType == NODE_VAR)
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
        else if (e1->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e1->negative==1)
                cout<<"-";
            cout<< e1->attr.vali;
        }
		else cout << "t" << e1->temp_var;
        cout << endl;
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        break;

    case OP_MOD://
        recursive_gen_code(cout,e1);
        if(e1->negative )
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }
        recursive_gen_code(cout,e2);
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
         cout << "\tmovl ";
        if (e1->nodeType == NODE_VAR)// ID
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
        else if (e1->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e1->negative==1)
                cout<<"-";
            cout<< e1->attr.vali;
        }
		else cout << "t" << e1->temp_var;// A TEMP RESULT
        cout << ", %eax" <<endl;
        cout<<"\tcltd\n";
        cout<<"\tmovl ";
		if (e2->nodeType == NODE_VAR)
			cout << "_" << name2<<symtbl.get_sconum(symtbl.findout(name2));
        else if (e2->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e2->negative==1)
                cout<<"-";
            cout<< e2->attr.vali;
        }
		else cout << "t" << e2->temp_var;
		cout << ", %ecx" << endl;
        cout << "\tidivl %ecx\n ";
                if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        if(e1->negative)
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }

		cout << "\tmovl %edx, t" << t->temp_var << endl;

		break;
    case OP_MULT://
        recursive_gen_code(cout,e1);
        if(e1->negative )
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }
        recursive_gen_code(cout,e2);
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
         cout << "\tmovl ";
        if (e1->nodeType == NODE_VAR)// ID
			cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
        else if (e1->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e1->negative==1)
                cout<<"-";
            cout<< e1->attr.vali;
        }
		else cout << "t" << e1->temp_var;// A TEMP RESULT
        cout << ", %eax" <<endl;
        cout << "\timull ";
		if (e2->nodeType == NODE_VAR)
			cout << "_" << name2<<symtbl.get_sconum(symtbl.findout(name2));
        else if (e2->nodeType == NODE_CONSTINT)
		{
            cout <<"$" ;
            if(e2->negative==1)
                cout<<"-";
            cout<< e2->attr.vali;
        }
		else cout << "t" << e2->temp_var;
		cout << ", %eax" << endl;
		cout << "\tmovl %eax, t" << t->temp_var << endl;
        if(e2->negative )
            {
                if(e2->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name2<<symtbl.get_sconum(symtbl.findout(name2))<<endl;
                }
                else if(e2->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e2->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e2->temp_var<<endl;
                }
            }
        if(e1->negative)
            {
                if(e1->nodeType==NODE_VAR)
                {
                    cout<<"\tmovl _"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,_"<<name1<<symtbl.get_sconum(symtbl.findout(name1))<<endl;
                }
                else if(e1->nodeType!=NODE_CONSTINT)
                {
                    cout<<"\tmovl t"<<e1->temp_var<<",%ecx"<<endl;
                    cout<<"\tnegl %ecx"<<endl;
                    cout<<"\tmovl %ecx,t"<<e1->temp_var<<endl;
                }
            }

		break;
    case OP_NOT:
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        e1->label.false_label=t->label.true_label;
        e1->label.true_label=t->label.false_label;
        recursive_gen_code(cout,e1);
		break;

    case OP_NOTEQUAL://
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,e1);
        recursive_gen_code(cout,e2);
        ////////////////////////////////////////////////////////////////////
        cout<<"\t";
		if (e2->nodeType == NODE_VAR)
			{
                cout << "movl _" << name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ebx";

            }
		else if (e2->nodeType == NODE_CONSTINT)
			{
                cout<<"movl $";
                if(e2->negative==1)
                    cout<<"-";
                cout<<e2->attr.vali<<",%ebx";

            }
		else {

            cout << "movl t" << e2->temp_var<<",%ebx";
        }
        cout<<endl;
        ///////////////////////////////////////////////////
        if (e1->nodeType == NODE_VAR)
			{
                cout << "\tmovl _" << name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%eax";

            }
		else if (e1->nodeType == NODE_CONSTINT)
			{
                cout<<"\tmovl $";
                if(e1->negative==1)
                    cout<<"-";
                cout<<e1->attr.vali<<",%eax"<<endl;
            }
		else {

            cout << "movl t" << e1->temp_var<<",%eax";
        }
        cout << "\n\tcmpl %ebx,%eax";
		cout <<"\n\tje "<<t->label.false_label << endl;
        cout <<"\tjmp "<<t->label.true_label<<endl;
		break;

    case OP_OR://
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,e1);
        // cout << "\tmovl ";
        // if (e1->nodeType == NODE_VAR)// ID
		// 	cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name1));
		// else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        // 	cout <<"$" << e1->attr.vali;
		// else cout << "t" << e1->temp_var;// A TEMP RESULT
        // cout << ", %eax" <<endl;
        // cout<<"\tcompl %eax,$1"<<endl;
        // cout<<"\tje "<<t->label.true_label<<endl;//if the first expr is true, then jmp to ture lable
        // cout<<"\tjmp "<<t->label.false_label<<endl;
        recursive_gen_code(cout,e2);
        // cout << "\tmovl ";
		// if (e2->nodeType == NODE_VAR)
		// 	cout << "_" << name1<<symtbl.get_sconum(symtbl.findout(name2));
		// else if (e2->nodeType == NODE_CONSTINT)
		// 	cout <<"$" << e2->attr.vali;
		// else cout << "t" << e2->temp_var;
		// cout << ", %ebx" << endl;
        // cout<<"\tcompl %eax,$1"<<endl;
        // cout<<"\tje "<<t->label.true_label<<endl;//if the second expr is not true, then jmp to false
        // cout<<"\tjmp "<<t->label.false_label<<endl;// i they both true, then goto true
		break;
    case OP_SMALLER://
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,e1);
        recursive_gen_code(cout,e2);
        ////////////////////////////////////////////////////////////////////
        cout<<"\t";
		if (e2->nodeType == NODE_VAR)
			{
                cout << "movl _" << name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ebx";

            }
		else if (e2->nodeType == NODE_CONSTINT)
			{
                cout<<"movl $";
                if(e2->negative==1)
                    cout<<"-";
                cout<<e2->attr.vali<<",%ebx";

            }
		else {

            cout << "movl t" << e2->temp_var<<",%ebx";
        }
        cout<<endl;
        ///////////////////////////////////////////////////
        if (e1->nodeType == NODE_VAR)
			{
                cout << "\tmovl _" << name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%eax";

            }
		else if (e1->nodeType == NODE_CONSTINT)
			{
                cout<<"\tmovl $";
                if(e1->negative==1)
                    cout<<"-";
                cout<<e1->attr.vali<<",%eax"<<endl;
            }
		else {

            cout << "movl t" << e1->temp_var<<",%eax";
        }
        cout << "\n\tcmpl %ebx,%eax";
		cout <<"\n\tjl "<<t->label.true_label;
        cout <<"\n\tjmp "<<t->label.false_label<<endl;
		break;


    case OP_SORE://
        if(t->label.begin_label!="")
            cout<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(cout,e1);
        recursive_gen_code(cout,e2);
        ////////////////////////////////////////////////////////////////////
        cout<<"\t";
		if (e2->nodeType == NODE_VAR)
			{
                cout << "movl _" << name2<<symtbl.get_sconum(symtbl.findout(name2))<<",%ebx";

            }
		else if (e2->nodeType == NODE_CONSTINT)
			{
                cout<<"movl $";
                if(e2->negative==1)
                    cout<<"-";
                cout<<e2->attr.vali<<",%ebx";

            }
		else {

            cout << "movl t" << e2->temp_var<<",%ebx";
        }
        cout<<endl;
        ///////////////////////////////////////////////////
        if (e1->nodeType == NODE_VAR)
			{
                cout << "\tmovl _" << name1<<symtbl.get_sconum(symtbl.findout(name1))<<",%eax";

            }
		else if (e1->nodeType == NODE_CONSTINT)
			{
                cout<<"\tmovl $";
                if(e1->negative==1)
                    cout<<"-";
                cout<<e1->attr.vali<<",%eax"<<endl;
            }
		else {

            cout << "movl t" << e1->temp_var<<",%eax";
        }
        cout << "\n\tcmpl %ebx,%eax";
		cout <<"\n\tjle "<<t->label.true_label << endl;
        cout <<"\tjmp "<<t->label.false_label<<endl;
		break;      
    /* ... */
	}
}