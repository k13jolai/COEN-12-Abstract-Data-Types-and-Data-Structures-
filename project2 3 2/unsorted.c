//The point of this code is to provide a main function with the ability to add, delete, and search for words that are placed in an unorganized set. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "set.h" 

char *elt;

struct set
{
	int count;
	int length;
	char **data;
};


//The set that is used is established here O(1)
SET *createSet(int maxElts)
{
	SET *sp;
	sp=malloc(sizeof(SET));
	assert(sp!=NULL);
	sp->count=0;
	sp->length=maxElts;
	sp->data=malloc(sizeof(char*)*maxElts);
	assert(sp->data!=NULL);
	
	return sp;
}
//In this function, the words in the set are freed from memory, clearing the set of its recorded information. O(n)
void destroySet(SET *sp)
{
	int i; 
	assert(sp!=NULL);
	for(i=0;i<sp->count;i++)
	{
		free(sp->data[i]);

	}

	free (sp->data);
	free (sp); 
		
}


//This function informs the user how many words are currently in the set. O(1)
int numElements(SET *sp)
{

	assert(sp!=NULL);
	return sp->count;
}
//This function searches for words in the set by comparing them with a word that is recieved as an argument O(n)
int findElement(SET *sp, char *elt)
{
	int i;
	assert(sp->data!=NULL);
	for(i=0;i<sp->count;i++)
	{
		if(strcmp(sp->data[i],elt)==1)
		{
			return i;
		}
	}

	return -1;
}
//This function either returns true if the word given as an argument exists in the set, or false if it doesn't O(n)
bool hasElement(SET *sp, char *elt)
{
	int i=findElement(sp,elt);
	
	if(i>0) 
	{
		return true;
	}

	
	return false;
}

//This function either quits out if the max number of words are in the set, or makes room for the new word in the memory and adds it to the set. O(n)
bool addElement(SET *sp, char *elt) 
{	int i;	

	if(sp->count==sp->length)
	{
		return false;
	}

	i=findElement(sp,elt);
	
	if(i==-1)
	{
		elt=strdup(elt);
		sp->data[(sp->count)++]=elt;
		return true; 
	}

	return false;
}
//This function either returns false if there are no words in the set, or checks for a word in the set and deletes it if it is found. O(n)
bool removeElement(SET *sp, char *elt)
{	int i;

	if(sp->count==0)
	{
		return false;
	}

	i=findElement(sp,elt);
	if(i<0)
	{
		return false;
	}
	
	free(sp->data[i]);
	sp->data[i]=sp->data[--(sp->count)];
	return true;
}

