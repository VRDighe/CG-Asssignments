		/* 	THE PROGRAMM TO PRINT INORDER POSTORDER EXPRESSION WITHOUT RECURSION */

#include<iostream>
#include<stack>
using namespace std;
struct treenode
{
	 char data;
	 treenode *lptr;
	 treenode *rptr;
	
};
treenode *root=NULL;

struct stackNode{
	treenode *tptr;
	stackNode *next;
};

stackNode * top = NULL;
treenode *create();
void push(stackNode *);
treenode* pop();
int inorder();
int preorder();
int postorder();

	int main()
	{
		create();
		cout<<"\nPrinting INORDER Expression :	   ";
		inorder();cout<<"\n\n";
		cout<<"\nPrinting PREORDER Expression :	   ";		
		preorder();cout<<"\n\n";
	}

int inorder()
{
	stack <treenode *>s;
	treenode *current =root;
	while(current!=NULL||s.empty()==false)
	{
		while(current!=NULL)
		{
			s.push(current);
			current =current->rptr;
		}
		current=s.top();
		s.pop();
		cout<<current->data;
		current =current->lptr;
	} 
}

int preorder()
{
	if(root==NULL)
	 return -1;
	treenode *current = root;
	stack<treenode *>sp;
	
		sp.push(root);
		while(sp.empty()==false)
		{
			treenode *temp=sp.top();
			cout<<temp->data;
			sp.pop();
			if(temp->lptr)
			sp.push(temp->lptr);
			if(temp->rptr)
			sp.push(temp->rptr);
		}
}
int postorder()
{
	if(root==NULL)
	return -1;
	treenode *current = root;
	stack<treenode *>sp;
	
		sp.push(root);
		while(sp.empty()==false)
		{
			treenode *temp=sp.top();
			cout<<temp->data;
			sp.pop();
			if(temp->lptr)
			sp.push(temp->lptr);
			if(temp->rptr)
			sp.push(temp->rptr);
		}
	
}


treenode *create()
{
	char exp[20];
	cout<<"Enter the postfix expressinon :  ";
	cin>>exp;
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
		{
			treenode *newNode =new treenode;
			newNode->data = exp[i];
			newNode->lptr=pop();
			newNode->rptr=pop();
			stackNode *sn =new stackNode;
			sn->tptr = newNode;
			sn->next = NULL;
			push(sn);
			root = newNode;	
		}
		else 
		{
			treenode *newNode =new treenode;
			newNode->data = exp[i];
			newNode->lptr=NULL;
			newNode->rptr=NULL;
			
			stackNode *sn =new stackNode;
			sn->tptr = newNode;
			sn->next = NULL;		
			push(sn);
		}

	}		
	return root;
}
void push(stackNode *sn)
{
	if(top==NULL)
	{
	top =sn;
	}
	else
	{
	sn->next =top;
	top =sn;
	}
}
treenode* pop()
{
	stackNode *temp= top;
	treenode *ret = temp->tptr;
	top = top->next;
	return ret;
	delete(temp);
	
}











