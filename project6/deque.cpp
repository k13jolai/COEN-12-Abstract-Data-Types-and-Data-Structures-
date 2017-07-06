#include <iostream>
#include "deque.h"
#include <assert.h>
//Jordan Lai COEN 12L Tu 2:15-5
//Lab 6

//The purpose of this code is to provide functions to store and remove integer values in a circular doubly linked list similar to that of deque.c but instead implementing a c++ class rather than a struct "Deque."

//This being so, besides outlining the Node structure, member functions have been written to allow for the creation, editting, and destruction of a Deque.
using namespace std;

//The Node structure provides the outline for each node in the linked list, which contains an integer value and two node pointers to the successor/predecessor
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

//Replacing *createDeque, the constructor for the Deque class allocates memory for the head Node, such that Deque->head is never NULL and sets the count of the list to 0 to bein with. O(1)
Deque::Deque(){
	count=0;
	head=(Node*) malloc(sizeof(Node));
	head->data=0;
	head->next=head;
	head->prev=head;
}

//The destructor of the Deque class frees the memory of every Node in the Deque before finally deleting the head node and Deque itself. O(n)
Deque::~Deque(){
	Node *np;
	Node *nm;
	np=head->next;
	nm=np->next;
	while(np!=head){
		delete np;
		np=nm;
		nm=np->next;
	}
	delete head;
}

//Simply returns the number of elements currently stored in the Deque. O(1)
int Deque::size(){
	return count;
}

//Memory is first allocated for a new node, which is then added to at the beginning of the Deque (right after the head node) O(1)
void Deque::addFirst(int x){
	Node *newnode;
	Node *temp;
	temp=head;
	newnode= (Node*) malloc(sizeof(Node));
	newnode->data=x;
	newnode->prev=head;
	newnode->next=head->next;
	count++;
	temp->next->prev=newnode;
	temp->next=newnode;
}

//Memory is first allocated for a new node, which is then added to the very end of the list, right after the current "last node" and right before the head node. O(1)
void Deque::addLast(int x){
	Node *newnode;
	Node *temp;
	temp=head;
	newnode= (Node*) malloc(sizeof(Node));
	newnode->data=x;
	newnode->prev=head->prev;
	newnode->next=temp;
	temp->prev->next=newnode;
	temp->prev=newnode;
}

//Alters the linked list such that the first node after the head node is marked for deletion while also setting head->next to the node following the deleted node. Returns the value stored in the deleted node. O(1)
int Deque::removeFirst(){
	assert(head!=NULL);
	int storedata;
	Node *temp;
	Node *np;
	temp=head;
	np=temp->next;
	temp->next=np->next;
	np->next->prev=temp;
	storedata=np->data;
	count--;
	delete np;
	return storedata;
}
  
//Alters the linked lsit such that the first node before the head node is marked for deletion while also setting head->prev to the node right before the deleted node. The returned value is the integer stored in the deleted node. O(1)
int Deque::removeLast(){
	assert(head!=NULL);
	int storedata;
	Node *temp;
	Node *np;
	temp=head;
	np=temp->prev;
	temp->prev=np->prev;
	np->prev->next=temp;
	storedata=np->data;
	count--;
	delete np;
	return storedata;
}

//Returns, but doesn't delete, the value stored in the first node of the array. O(1)
int Deque::getFirst(){
	assert(head!=NULL);
	return head->next->data;
}

//Returns, but doesn't delete, the value stored in the last node of the array. O(1)
int Deque::getLast(){
	assert(head!=NULL);
	return head->prev->data;
}
