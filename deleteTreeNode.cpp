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
		{
			*rootRef=createNewNode(info,NULL,NULL,parent);
			return;
		}

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

int getHeight(tree* root)
{
	if(root==NULL)
		return 0;
	int left=getHeight(root->left);
	int right=getHeight(root->right);
	return (left>right)?(1+left):(1+right); 

}


tree* rootMin(tree* root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;

}

tree* search(tree* root,int no)
{
  if(root==NULL) return NULL;
	while(root->info!=no)
	{
		root=(root->info>no)?(root->left):(root->right);	
	}
	return root;
}

void transplant(tree** rootRef,tree* u,tree* v)
{
	if(u->parent==NULL)
		*rootRef=v;

	else if(u->parent->left==u)
		u->parent->left=v;
	else if(u->parent->right==u)
		u->parent->right=v;
	if(v!=NULL)
		v->parent=u->parent;
}
void Delete(tree** rootRef,tree* node)
{
	if(node==NULL)
		return;
	if(node->left==NULL)
		transplant(rootRef,node,node->right);
	if(node->right==NULL)
		transplant(rootRef,node,node->left);
	else
	{
		tree* min=rootMin(node->right);
		if(min->parent!=node) 
		{
			transplant(rootRef,min,min->right);
			min->right=node->right;
			min->right->parent=min;
		}	
		transplant(rootRef,min,node);
		min->left=node->left;
		min->left->parent=min;
	}
}
int main()
{
	tree* root=NULL;
	insertHelper(25,&root);
	insertHelper(15,&root);
	insertHelper(10,&root);
	insertHelper(31,&root);
	insertHelper(4,&root);
	insertHelper(18,&root);
	insertHelper(28,&root);
	insertHelper(34,&root);
	insertHelper(50,&root);
	PrintInOrder(root);
	cout<<"Height is:"<<getHeight(root);
	cout<<"Root Min is:"<<(rootMin(root))->info;
	cout<<"search info is:"<<search(root,4)->info;
	//cin>>"delete no">>search;
	tree* z=search(root,28);
	Delete(&root,z);
	cout<<endl<<"after deleting";
	PrintInOrder(root);
}






