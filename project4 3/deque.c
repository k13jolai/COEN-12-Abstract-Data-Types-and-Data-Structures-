//The purpose of this code is to provide functions to store and remove integer values in a doubly linked list that also has a sentinel node. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "deque.h"

struct node
{
	int data;
    struct node *next;
	struct node *prev;
};
typedef struct node NODE;

struct deque
{
	int count;
	NODE *head;
};
//Here the doubly linked list (aka deque) is created, because the head doesn't count as part of the actual list of values, the list is never truly empty
DEQUE *createDeque(void)
{
	DEQUE *dp;
	dp=malloc(sizeof(DEQUE));
	assert(dp!=NULL);
	dp->count=0;
	dp->head=(NODE*) malloc(sizeof(NODE));
	assert(dp->head!=NULL);
	dp->head->next=dp->head;
	dp->head->prev=dp->head;

	return dp;
}

// This function frees all nodes in the list, the sentinel node, and finally the list itself. 
// O(n)
void destroyDeque(DEQUE *dp)
{
	NODE *np;
	NODE *nm;
	assert(dp!=NULL);
	np=dp->head->next;
	nm=np->next;
	while(np!=dp->head)
	{
		free(np);
		np=nm;
		nm=np->next;	
	}
	
	free(dp->head);
	free(dp);
}


//This function returns the number of values stored in the list
//O(1)
int numItems(DEQUE *dp)
{
	assert(dp!=NULL);
	return dp->count;
}

//Adds a new node as the next node after the sentinel 
//O(n)
void addFirst(DEQUE *dp, int x)
{
	assert(dp!=NULL);
	NODE *newnode;
	NODE *temp;
	temp=dp->head;
	newnode= (NODE*) malloc(sizeof(NODE));
	newnode->data=x;
	newnode->prev=dp->head;
	newnode->next=dp->head->next;
	dp->count++;
	temp->next->prev=newnode;
	temp->next=newnode;
}
//Adds a new node as the node right before the sentinel
//O(1)
void addLast(DEQUE *dp, int x)
{
	assert(dp!=NULL);
	NODE *newnode;
	NODE *temp;
	temp=dp->head;
	newnode= (NODE*) malloc(sizeof(NODE));
	dp->count++;
	newnode->data=x;
	newnode->prev=dp->head->prev;
	newnode->next=temp;
	temp->prev->next=newnode;
	temp->prev=newnode;
}

//Removes first node after the sentinel 
//O(1)
int removeFirst(DEQUE *dp)
{
	assert(dp!=NULL);
	int storedata;
	NODE *temp;
	NODE *np;
	temp=dp->head;
	np=temp->next;
	temp->next=np->next;
	np->next->prev=temp;
	storedata=np->data;
	dp->count--;
	free(np);
	return storedata;
}

//Removes the node right before the sentinel 
//O(1)
int removeLast(DEQUE *dp)
{
	assert(dp!=NULL);
	int storedata;
	NODE *temp;
	NODE *np;
	temp=dp->head;
	np=temp->prev;
	temp->prev=np->prev;
	np->prev->next=temp;
	storedata=np->data;
	dp->count--;
	free(np);
	return storedata; 
}

//Returns the first node after the sentinel  
//O(1)
int getFirst(DEQUE *dp)
{
	assert(dp!=NULL);
	assert(dp->count!=0);
	return dp->head->next->data;
}

//Returns the last node in the list 
//O(1)
int getLast(DEQUE *dp)
{
	assert(dp!=NULL);
	assert(dp->count!=0);
	return dp->head->prev->data;
}





