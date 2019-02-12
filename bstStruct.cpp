#include<iostream>
using namespace std;
struct tnode{
	int data;
	tnode *lptr,*rptr;
};
tnode *root=NULL;
tnode *insert(int val);
void create(int val);
void inorder(tnode *);
void preorder(tnode *);
void postorder(tnode*);
int main()
{
	int num,a;
	cout<<"Nodes in tree : ";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cout<<"Enter the data : ";
		cin>>num;
		create(num);
	}
	cout<<"Inorder Traversal of Tree : \n";
	inorder(root);
	cout<<"Preorder Traversal of Tree : \n";
	preorder(root);
	cout<<"Postorder Traversal of Tree : \n";
	postorder(root);
}
tnode *insert(int val)
{
	tnode *newNode =new tnode;
	newNode->data=val;
	newNode->lptr =newNode->rptr =NULL;
	return newNode;
}
void create(int val)
{
	tnode *parent,*current=root;
	if(root==NULL)
	{
		root   = insert(val);
	}
	else
	{
		while(current!=NULL)
		{
			parent =current;
			if(val<current->data)
			current =current->lptr;
			else
			current = current->rptr;
		}
		if(val<parent->data)
			parent->lptr=insert(val);
			else
			parent->rptr =insert(val);
	}
}

void inorder(tnode *Root)
{
	
	
	tnode *temp =Root;
	if(temp==NULL)
	return ;
	inorder(temp->lptr);
	cout<<temp->data<<endl;
	inorder(temp->rptr);
}
void preorder(tnode *Root)
{
	tnode *temp=Root;
	if(temp==NULL)
	return ;
	cout<<temp->data<<endl;
	preorder(temp->lptr);
	preorder(temp->rptr);
	
}
void postorder(tnode *Root)
{
	tnode *temp =Root;
	if(temp==NULL)
	return ;
	preorder(temp->lptr);
	preorder(temp->rptr);
	cout<<temp->data<<endl;


	
}






