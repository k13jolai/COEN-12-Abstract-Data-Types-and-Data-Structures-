//Jordan Lai Project 3 
//The point of this code is to provide a main function with the ability to add, delete, and search for words that are placed in a sorted set via a has table. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#define EMPTY 0
#define FILLED 1
#define DELETED 2
#include "set.h"

char *elt;

struct set
{
	int count;
	int length;
	char **data;
	char *flags;
};

//The set that is used is established here O(n)
SET *createSet(int maxElts)
{
	int x;
	SET *sp;
	sp=malloc(sizeof(SET));
	assert(sp!=NULL);
	sp->count=0;
	sp->length=maxElts;
	sp->data=malloc(sizeof(char*)*maxElts);
	assert(sp->data!=NULL);
	sp->flags=malloc(sizeof(char)*maxElts);
	assert(sp->flags!=NULL);
	for(x=0;x<maxElts;x++)
	{
		sp->flags[x]=EMPTY;
	}
	return sp;
}
//In this function, the words in the set are freed from memory, clearing the set of its recorded information. O(n)
void destroySet(SET *sp)
{
	int i; 
	assert(sp!=NULL);
	for(i=0;i<sp->count;i++)
	{
		if(sp->flags[i]==FILLED)
		{
			free(sp->data[i]);
		}
	}

	free (sp->data);
	free (sp); 

	return;
}


//This function informs the user how many words are currently in the set. O(1)
int numElements(SET *sp)
{
	assert(sp!=NULL);
	return sp->count;
}

//This gives us our hash number to be used when we search using linear probing in findElement O(n) 
unsigned hashstring (char *s ){
	unsigned hash= 0;

	while (*s!= '\0')
	{	hash= 31*hash+ *s++; 

	}	
	return hash;
}

//This function searches for words in the set by comparing them with a word that is recieved as an argument
//If the flag is filled and the words match, the spot of that word is returned. 
//The first deleted spot is also recorded and returned if no match is found. 
//Best case: O(1) Worst Case: O(n)
int findElement(SET *sp, char *elt,bool *found)
{
	int i;
	assert(sp!=NULL && elt!=NULL);
	unsigned spot;
	spot=hashstring(elt);
	int deletedspot;
	int k=0;
//The Flag is checked here if the current spot is filled. If so, the code checks if there is a match.
	for(i=0;i<sp->length;i++)
	
	{
		if(sp->flags[(spot+i)%sp->length]==FILLED)
		{
			if(strcmp(sp->data[(spot+i)%sp->length],elt)==0)
			{

			*found=true;
			return (spot+i)%sp->length;
	
			}
		}
//The flag is checked here if the current spot once was filled but was deleted. If so, the spot is remembered for later use.
		if(sp->flags[(spot+i)%sp->length]==DELETED)
		{
			while(k==0)
			{
                        deletedspot=(spot+i)%sp->length;
				k=-1; 
			}
		}
//If the code finds a slot with an empty flag, if there is no deleted spot recorded, the code returns the current spot instead. 

		else if(sp->flags[(spot+i)%sp->length]==EMPTY)
		{
			*found=false;
			if(k==-1)
			{
				return deletedspot;
			}

			return (spot+i)%sp->length;
		}



	}

	*found=false;
	return deletedspot; 

}
//This function either returns true if the word given as an argument exists in the set, or false if it doesn't.
//Best Case O(1) Worse Case  O(n)
bool hasElement(SET *sp, char *elt)
{
	assert(sp!=NULL && elt!=NULL);
	bool found;
	int i=findElement(sp,elt,&found);
	
	return found;

}

//This function either quits out if the max number of words are in the set, or makes room for the new word in the memory and adds it to the set unless an instance of the word is already present. 
//Best Case O(1) Worst Case O(n)
bool addElement(SET *sp, char *elt) 
{
	assert(sp!=NULL && elt!=NULL); 
	bool found;	
	int i;
	if(sp->count==sp->length)
	{
		return false;
	}

	i=findElement(sp,elt,&found);
	
	if(found==true)
	{
		return false;
	}

	if(found==false)
	{
		elt=strdup(elt);
		sp->data[i]=elt;
		sp->flags[i]=FILLED; 
		sp->count++;
		return true; 
	}
	return false;
}
//This function either returns false if there are no words in the set, or checks for a word in the set and deletes it if it is found.
//Best Case O(1) Worst Case O(n)
bool removeElement(SET *sp, char *elt)
{
	assert(sp!=NULL && elt!=NULL);
	int i;
	bool found;
	if(sp->count==0)
	{
		return false;
	}

	i=findElement(sp,elt,&found);

	if(found==true)
	{
		free(sp->data[i]);
		sp->count--;
	   	sp->flags[i]=DELETED;	
		return true;
	}
	return false;
}

