#include "tree.h"

void TreeNode::addChild(TreeNode* child) {
  
    // cout<<"add child entered "<<child;cout<<endl;
    // printSpecialInfo();
    // cout<<endl;
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
    negative=0;
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
            return;
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
            cerr<<child1->var_name<<" and "<<child2->var_name<<" are of diffrent type, can't do this assign operation at line "<<lineno<<endl;      
    }
    
}


void tree::get_temp_var(TreeNode *t)
{
	if (t->nodeType != NODE_EXPR)
		return;
	if (t->optype < OP_ASSIGN || t->optype > OP_EQUAL)
		return;

	TreeNode *arg1 = t->child;
	TreeNode *arg2 = arg1->sibling;

	if (arg1->nodeType == NODE_EXPR)
		tree::temp_var_seq--;
	if (arg2 && arg2->nodeType == NODE_EXPR)
		tree::temp_var_seq--;
	t->temp_var = tree::temp_var_seq;
	tree::temp_var_seq++;
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

            then->label.begin_label=cdt->label.true_label=new_label();//if cdt is true then goto then

            if(el)
                el->label.begin_label=cdt->label.false_label=new_label();// if cdt is false then goto else

            if(t->label.next_label == "")
                t->label.next_label=new_label();
            
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
            blcok->label.begin_label=cdt->label.true_label;

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

    
}

string tree::new_label(void)
{
    //get a new lable from label_seq,and label_seq++;
	char tmp[20];

	sprintf(tmp, "@%d", tree::label_seq);
	tree::label_seq++;
	return tmp;
}

void tree::recursive_get_label(TreeNode *t)
{
	if (t->nodeType == NODE_STMT)
		stmt_get_label(t);
	else if (t->nodeType == NODE_EXPR)
		expr_get_label(t);
}

void tree::expr_get_label(TreeNode *t)
{
	if (t->type != TYPE_BOOL)// if it's not boolean expr then recursive labeling ends
		return;
	TreeNode *e1 = t->child;
	TreeNode *e2 = e1->sibling;
	switch (t->optype)
	{
	case OP_AND:
		e1->label.true_label = new_label();
		e2->label.true_label = t->label.true_label;
		e1->label.false_label = e2->label.false_label = t->label.false_label;
		break;
	case OP_OR:
        e1->label.true_label=e2->label.true_label=t->label.true_label;
        e1->label.false_label=new_label();
        e2->label.false_label=t->label.false_label;
		break;

    case OP_NOT:
        {  
            e1->label.true_label=t->label.false_label;
            e1->label.true_label=t->label.true_label;
        }
        break;
    // case OP_EQUAL:
    //         // true entry = t-> entry, false entry the same
	// 	break;
    // case OP_NOTEQUAL:
    //         // same as eaqual
	// 	break;
	// case OP_GREATER:
    //         //same as before
	// 	break;
    // case OP_GORE:
    //     //same
	// 	break;
	// case OP_SMALLER:
    //     //same
	// 	break;
	// case OP_SORE:
    //     {

    //     }
	// 	break;
    default:
        break;
        /* ... */
	}
    //if it's not logical
	if (e1)
		recursive_get_label(e1);
	if (e2)
		recursive_get_label(e2);
}

//-----------------------generate code.------------------
void tree::gen_header(ostream &out)
{
	out << "# your asm code header here" << endl;
	/*your code here*/
}

void tree::gen_code(ostream &out)
{
	gen_header(out);
	TreeNode *p = root->child;
	if (p->stype == STMT_DECL)
		gen_decl(out, p);
    out << endl << endl << "# your asm code here" << endl;
	out << "\t.text" << endl;
    out << "\t.globl _start" << endl;
	recursive_gen_code(out, root);
	if (root->label.next_label != "")
		out << root->label.next_label << ":" << endl;
	out << "\tret" << endl;
}

void tree::gen_decl(ostream &out,TreeNode *t)
{
    cout<<"get in ge_decl"<<endl;
    out << endl << "# define your veriables and temp veriables here" << endl;
	out << "\t.bss" << endl;
	for (; t && t->stype == STMT_DECL; t = t->sibling)
	{
        cout<<"re"<<endl;
		for (TreeNode *p = t->child; p; p = p->sibling)
		{   
            cout<<p->nodeID<<" ";
            cout<<p->var_name<<endl;;
            if (symtbl.get_type(symtbl.lookup(p->var_name)) == "int")
			{
                cout<<"int"<<endl;
                out << "_" << symtbl.getname(p->attr.symtbl_seq) << ":" << endl;
                out << "\t.zero\t4" << endl;
                out << "\t.align\t4" << endl;
            }
            // if(p->type== TYPE_CHAR)
            // {
            //     out << "_" << symtbl.getname(p->attr.symtbl_seq) << ":" << endl;
            //     out << "\t.zero\t4" << endl;
            //     out << "\t.align\t4" << endl;

            // }
        }
	}
	for (int i = 0; i < temp_var_seq; i++)
	{
		out << "t" <<  i << ":" << endl;
        out << "\t.zero\t4" << endl;
        out << "\t.align\t4" << endl;
	}
}


void tree::recursive_gen_code(ostream &out, TreeNode *t)
{
	if (t->nodeType == NODE_STMT)
	{
		stmt_gen_code(out, t);
	}
	else if (t->nodeType == NODE_EXPR  )
	{
		expr_gen_code(out, t);
	}
}

void tree::stmt_gen_code(ostream &out, TreeNode *t)
{
	if (t->stype == STMT_BLOCK)// iterate every node of the tree
	{
        cout<<"block"<<endl;
        TreeNode* iter;
		for (iter=t->child ; iter; iter=iter->sibling)
		{
			recursive_gen_code(out, iter);
			for (TreeNode *p = iter->sibling; p; p = p->sibling)
				recursive_gen_code(out, p);
		}
	}
	if (t->stype == STMT_WHILE)
	{
		if (t->label.begin_label != "")
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, t->child);
		recursive_gen_code(out, t->child->sibling);
		out << "\tjmp " << t->label.begin_label << endl;
	}
	else if (t->stype == STMT_PRINTF)
	{
		

	}
    else if(t->stype==STMT_SCANF)
    {
        /* code */
    }
    // else if(t->stype==STMT_DECL)
    // {
    //     /* code */
    // }
    else if(t->stype==STMT_IF)
    {
        if (t->label.begin_label != "")
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, t->child);
		recursive_gen_code(out, t->child->sibling);
    }
    else if(t->stype==STMT_FOR)
    {
        if (t->label.begin_label != "")
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, t->child);
		recursive_gen_code(out, t->child->sibling);
        recursive_gen_code(out,t->child->sibling->sibling);
        out << "\tjmp " << t->label.begin_label << endl;

    }

    else if(t->stype==STMT_RETURN)
    {
        if(t->label.begin_label!="")
                out<<t->label.begin_label<<":"<<endl;
        recursive_gen_code(out,t->child);
        out << "\tret " ;
    }
    /* ... */
}


void tree::expr_gen_code(ostream &out, TreeNode *t)
{
	TreeNode *e1 = t->child;
	TreeNode *e2 = e1->sibling;
	switch (t->optype)
	{
	case OP_ASSIGN:
        cout<<"assign";
        out << "\tmovel $";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", " << endl;
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
		break;

	case OP_ADD:
		out << "\tmovl $";
		if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
		out << ", %eax" <<endl;
		out << "\taddl $";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
		out << "\tmovl %eax, $t" << t->temp_var << endl;
		break;
    case OP_AND:
        out << "\tmovel $";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out << ", %eax" <<endl;
        out<<"\tcompl %eax,0"<<endl;
        out<<"\tje "<<t->label.false_label<<endl;//if the first expr is not true, then jmp to false
        out << "\tmovel $";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
        out<<"\tcompl %eax,0"<<endl;
        out<<"\tje "<<t->label.false_label<<endl;//if the second expr is not true, then jmp to false
        out<<"\tjmp "<<t->label.true_label<<endl;// i they both true, then goto true
        break;
	case OP_ADDADD:
        out<<"\tincl &";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out<<endl;
		break;
    case OP_ADDSELF:
        out << "\tmovel $";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out << ", %eax" <<endl;
        out << "\taddl &";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
		out << "\tmovl %eax, $t" << t->temp_var << endl;
		break;
    case OP_DIV:
         out << "\tmovel $";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out << ", %eax" <<endl;
        out << "\tidivl &";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
		out << "\tmovl %eax, $t" << t->temp_var << endl;
		break;
    case OP_EQUAL://////////////////
        out << "\tcmp $";
        if (e2->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)// CONST INT
        	out << e2->attr.vali;
		else out << "t" << e2->temp_var;// A TEMP RESULT
        out << ", " ;
		if (e1->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out <<"\tje "<<t->label.true_label << endl;
        out <<"\tjmp "<<t->label.false_label<<endl;
		break;
    case OP_GORE:
        out << "\tcmp $";
        if (e2->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)// CONST INT
        	out << e2->attr.vali;
		else out << "t" << e2->temp_var;// A TEMP RESULT
        out << ", " ;
		if (e1->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out <<"\tjge "<<t->label.true_label << endl;
        out <<"\tjmp "<<t->label.false_label<<endl;
		break;
    case OP_GREATER:
        out << "\tcmp $";
        if (e2->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)// CONST INT
        	out << e2->attr.vali;
		else out << "t" << e2->temp_var;// A TEMP RESULT
        out << ", " ;
		if (e1->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out <<"\tjg "<<t->label.true_label << endl;
        out <<"\tjmp "<<t->label.false_label<<endl;

		break;
    case OP_MINUS:
        out << "\tmovel $";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out << ", %eax" <<endl;
        out << "\tsubl &";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
		out << "\tmovl %eax, $t" << t->temp_var << endl;
		break;
    case OP_MINUSMINUS:
        out<<"\tincl &";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out<<endl;
		break;

    case OP_MINUSSELF:
        out << "\tmovel $";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out << ", %eax" <<endl;
        out << "\tsubl &";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
		out << "\tmovl %eax, $t" << t->temp_var << endl;
        break;

    case OP_MOD:
        out << "\tmovel $";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out << ", %eax" <<endl;
        out << "\tidivl &";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
		out << "\tmovl %ebx, $t" << t->temp_var << endl;//ebx is the remainder
		break;
    case OP_MULT:
         out << "\tmovel $";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out << ", %eax" <<endl;
        out << "\timull &";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
		out << "\tmovl %eax, $t" << t->temp_var << endl;
		break;
    case OP_NOT:
        out << "\tcmp $";
        if (e2->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)// CONST INT
        	out << e2->attr.vali;
		else out << "t" << e2->temp_var;// A TEMP RESULT
        out << ", 1" ;
		out <<"\tje "<<t->label.false_label << endl;
        out <<"\tjmp "<<t->label.true_label<<endl;

		break;
    case OP_NOTEQUAL:
        out << "\tcmp $";
        if (e2->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)// CONST INT
        	out << e2->attr.vali;
		else out << "t" << e2->temp_var;// A TEMP RESULT
        out << ", " ;
		if (e1->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out <<"\tje "<<t->label.false_label << endl;
        out <<"\tjmp "<<t->label.true_label<<endl;
		break;

    case OP_OR:
        out << "\tmovel $";
        if (e1->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)// CONST INT
        	out << e1->attr.vali;
		else out << "t" << e1->temp_var;// A TEMP RESULT
        out << ", %eax" <<endl;
        out<<"\tcompl %eax,0"<<endl;
        out<<"\tjne "<<t->label.false_label<<endl;//if the first expr is true, then jmp to ture lable
        out<<"\tjmp "<<t->label.true_label<<endl;
        out << "\tmovel $";
		if (e2->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << ", %eax" << endl;
        out<<"\tcompl %eax,0"<<endl;
        out<<"\tjne "<<t->label.true_label<<endl;//if the second expr is not true, then jmp to false
        out<<"\tjmp "<<t->label.false_label<<endl;// i they both true, then goto true
		break;
    case OP_SMALLER:
        out << "\tcmp $";
        if (e2->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)// CONST INT
        	out << e2->attr.vali;
		else out << "t" << e2->temp_var;// A TEMP RESULT
        out << ", " ;
		if (e1->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out <<"\tjl "<<t->label.true_label << endl;
        out <<"\tjmp "<<t->label.false_label<<endl;
		break;
    case OP_SORE:
        out << "\tcmp $";
        if (e2->nodeType == NODE_VAR)// ID
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->nodeType == NODE_CONSTINT)// CONST INT
        	out << e2->attr.vali;
		else out << "t" << e2->temp_var;// A TEMP RESULT
        out << ", " ;
		if (e1->nodeType == NODE_VAR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->nodeType == NODE_CONSTINT)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out <<"\tjle "<<t->label.true_label << endl;
        out <<"\tjmp "<<t->label.false_label<<endl;

		break;      
    /* ... */
	}
}