#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include <assert.h>
struct tree
{
	int value;
	struct tree* rightchild;
	struct tree* leftchild;
	struct tree* parent;
};
typedef struct tree TREE;


struct tree *createTree(int data, struct tree *left, struct tree *right)
{
	struct tree *pTree;
	pTree= malloc(sizeof(struct tree));
	assert(pTree!=NULL);
	
	pTree->value=data;
	pTree->rightchild=right;
	pTree->leftchild=left;
	pTree->parent=NULL;
	return pTree;
}

void destroyTree(struct tree*root){
//check left, check right, if both null DELETE.
	if(root==NULL){
		return;
	}
	destroyTree(root->leftchild);
	destroyTree(root->rightchild);
	free(root);
	return; 	
}

int getData(struct tree *root){
	return root->value;
}

struct tree *getLeft(struct tree *root){
	return root->leftchild;
}

struct tree *getRight(struct tree *root){
	return root->rightchild;
}

struct tree *getParent(struct tree *root){
	return root->parent;
}

void setLeft(struct tree *root, struct tree *left){
	root->leftchild=left;
	root->leftchild->parent=root;
	return;
}

void setRight(struct tree *root, struct tree *right){
		root->rightchild=right;
		root->rightchild->parent=root;
		return;
}

