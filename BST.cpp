#include <iostream>
using namespace std;

struct tree
{
	int info;
	tree* left;
	tree* right;
	tree* parent;
};

tree* createNewNode(int info , tree* left=NULL , tree* right=NULL , tree *parent=NULL)
{
	tree* newNode=new tree;
	newNode->info=info;
	newNode->left=left;
	newNode->right=right;
	newNode->parent=parent;
	return newNode;
}

void insertHelper(int info , tree **rootRef,tree* parent=NULL)
{ 
	if(*rootRef==NULL)
		*rootRef=createNewNode(info,NULL,NULL,parent);

	if(((*rootRef)->info)<info)
		insertHelper(info,&((*rootRef)->right),*rootRef);

	else
		insertHelper(info,&((*rootRef)->left),*rootRef);
}

void PrintInOrder(tree* root)
{
	if(root==NULL)
		return;
	PrintInOrder(root->left);
	cout<<root->info<<" ";
	PrintInOrder(root->right);
}

int main()
{
	tree* root=NULL;
	insertHelper(25,&root);
	insertHelper(15,&root);
	insertHelper(31,&root);
	insertHelper(4,&root);
	insertHelper(18,&root);
	insertHelper(28,&root);
	PrintInOrder(root);
}







