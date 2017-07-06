//The object of this code is to provide a set, as well as functions for a main function to use to record, delete, and search for via binary search a set of words that are read from text files. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include"set.h" 

char *elt;
//The parameters for the organized set are established here. 
struct set
{
	int count;
	int length;
	char **data;
};


// O(1)
SET *createSet(int maxElts)
{
	SET *sp;
	sp=malloc(sizeof(SET));
	assert (sp!=NULL);
	sp->count=0;
	sp->length=maxElts;
	sp->data=malloc(sizeof(char*)*maxElts);
	assert(sp->data!=NULL);
	
	return sp;
}
//This function is used to clear the set of all words that are recorded in it 0(n)
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


//This function is used to show the current number of words stored in the set. 0(1)
int numElements(SET *sp)
{

	assert(sp!=NULL);
	return sp->count;
}
//This function searches for a word via the binary search method O(logn)
int findElement(SET *sp, char *elt,bool*found)
{
	int lo,mid,hi,diff;
	lo=0;
	hi=sp->count-1;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		diff=strcmp(elt,sp->data[mid]);
		if(diff<0)
		{
			hi=mid-1;
		}

		else if(diff>0)
		{
			lo=mid+1;
		}

		else if(diff==0)
		{
			*found=true;
			return mid;
		}

	}
	*found=false;
	return lo; 
}

//This function's purpose is to record whether or not a word exists in the set O(logn)
bool hasElement(SET *sp, char *elt)
{
	bool found;
	assert(sp!=NULL && elt!=NULL);
	findElement(sp,elt,&found);
	return found;
}
	

//After searching for a word in the set, this function either adds a new word by shifting older entries to the left to make room for it in the organized set, or quits if the word already exists
//O(n)
bool addElement(SET *sp, char *elt) 
{	
	int i;
	bool found;
	if(sp->count==sp->length)
	{
		return false;
	}

	int x=findElement(sp,elt,&found);
	
	if(found==true)
	{
		return false;
	}

	for(i=sp->count;i>x;i--)
	{
		sp->data[i]=sp->data[i-1];
		
	}
	sp->data[x]=strdup(elt);
	sp->count++;
	return true; 	
}
//After searching for a word in the set, this function either deletes a word and shifts entries proceding entries to the right, or quits if the word does not exist. 
//O(n)
bool removeElement(SET *sp, char *elt)
{	
	int i;
	bool found;	
	if(sp->count==0)
	{
		return false;
	}


	
	int x=findElement(sp,elt,&found);

	if(found==false)
	{
		return false;
	}
	free(sp->data[x]);
	
	for(i=x+1;i<sp->count;i++)
	{
		sp->data[i-1]=sp->data[i];
	}

	sp->count--;
	return true;
}


