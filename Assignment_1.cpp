 /*	Problem statement :Construct an expression tree from postfix expression and perform recursive Inorder, Preorder and
	Post order traversals

*/
#include<iostream>
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
void inorder(treenode *);
void preorder(treenode *);
void postorder(treenode *);

int main()
{
	int choise;
	treenode *Root = create();
	do
	{
		cout<<"\t\t1.Inorder Traversal\n\t\t2.Preorder Traversal\n\t\t3.Postorder Traversal\n\t\t4.Exit\n\tYour choise : ";
		cin>>choise;
			switch(choise)
			{
				case 1:
				cout<<"Printing Inorder traversal of tree : \n";
				inorder(Root);				cout<<"\n\n";
				break;
				case 2:
				cout<<"Printing Preorder traversal of tree : \n";				
				preorder(Root);				cout<<"\n\n";
				break;
				case 3:
				cout<<"Printing Postorder traversal of tree : \n";				
				postorder(Root);				cout<<"\n\n";
				break;
				cout<<"\n\n";
			}
	}while(choise<4);
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
			newNode->rptr=pop();
			newNode->lptr=pop();
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
void inorder(treenode *root)
{
	
	treenode *temp=root;
	
	if(temp ==NULL)
	return ;inorder(temp->lptr);
	cout<<temp->data;
	inorder(temp->rptr);
}
void preorder(treenode *root)
{
	treenode *temp=root;
	
	if(temp ==NULL)
	return ;
	cout<<temp->data;
	inorder(temp->lptr);
	inorder(temp->rptr);
}


void postorder(treenode *root)
{
	treenode *temp=root;
	
	if(temp ==NULL)
	return ;
	inorder(temp->lptr);
	inorder(temp->rptr);
	cout<<temp->data;
}



