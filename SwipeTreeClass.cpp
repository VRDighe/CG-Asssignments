#include<iostream>
#include<math.h>
using namespace std;
class tnode {
private:
	int data;
	tnode *lptr;
	tnode *rptr;
public:
	tnode *insert(int val);
	void create(int val);
	void inorder(tnode *);
	int swapTree(tnode *);

};
tnode *root =NULL;
tnode *tnode :: insert(int val)
{
	tnode *newNode =new tnode;
	newNode->data=val;
	newNode->lptr =newNode->rptr =NULL;
	return newNode;
}
void tnode :: create(int val)
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
void tnode ::inorder(tnode *Root)
{
	tnode *temp =Root;
	if(temp==NULL)
	return ;
	inorder(temp->lptr);
	cout<<temp->data<<endl;
	inorder(temp->rptr);
}
int tnode :: swapTree(tnode *Root)
{
	tnode *current = Root;

	if(current==NULL)
		return 0;
	tnode *temp =current->rptr;
	current->rptr = current->lptr;
	current->lptr = temp;
	swapTree(current->lptr);
	swapTree(current->rptr);
}
int main()
{
	tnode bt;
	int num,a,choise;
	cout<<"Nodes in tree : ";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cout<<"Enter the data : ";
		cin>>num;
		bt.create(num);
	}
	do 
	{
		cout<<"\n\t\t1.Inser a new node\n\t\t2.Swipe the tree\n\t\t3.Inorder traversal\n\t\t4.Exit\n\t\tYour choise : ";
		cin>>choise;
		switch(choise)
		{
			case 1:
			cout<<"Enter the data : ";
			cin>>num;
			bt.create(num);
			break;
			case 2:
			bt.swapTree(root);			
			cout<<"Tree Swiped ! ";
			break;
			case 3:
			cout<<"Inorder Traversal of Tree : \n";
			bt.inorder(root);
			break;
		}
	}while(choise<4);
	
}