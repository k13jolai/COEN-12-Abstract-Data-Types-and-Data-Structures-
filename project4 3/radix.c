//This code provides a main function in which numbers are entered and sorted into a doubly linked list. 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<math.h>
#include"deque.h"
#define r 10

int main(void)
{

		DEQUE *dp;
		int input;
		int max=0;
		int i;
		int digits;
		int divisor=1;
		dp=createDeque();
		int j;
		int k;
		int finallydone;
		printf("Please insert a number\n");

		scanf("%d",&input);

	//dequearray is an array of doubly linked lists that will serve as a method of sorting for our main deque dp. 
		DEQUE *dequearray[10];
		for(i=0;i<r;i++)
		{
			dequearray[i]=createDeque();
			assert(dequearray[i]!=NULL);
		}
	
		while(scanf("%d",&input)==1)
		{
			assert(dp!=NULL);
	//The if statement below makes sure that all inputs stored are not negative numbers. If the input given is negative, the code errors out. 
			if(input<0)
			{
				printf("cannot read in a negative number\n");
				return -1;

			}
	//The if statement below saves the greatest value of all the inputs entered in. 
			if(input>max)
			{	
				max=input;
			}
		
			addFirst(dp,input);
		
	//The integer digits uses the max to return how many digit places the max value has
			digits=ceil(log(max+1)/log(r));

	//The sorting function below loops through the same amount of times as the value of digits. 
			for(i=0;i<digits;i++)
			{
				while(numItems(dp)>0)
				{
	//K is the current significant digit of the last value removed from the main deque. 
					j=removeLast(dp);
					k=(j/divisor)%10;
	
	//The last value removed is then sorted into a dequearray based on its current  significant digit.
					for(i=0;i<9;i++)
					{
						if(k==i)
						{
							addFirst(dequearray[i], j);
						}
					}
				}

				divisor*=10;
	//After being sorted into the dequearrays, the values are returned to the main deque dp in sorted order. 
				for(i=0;i<9;i++)
				{
					while(numItems(dequearray[i])>0)
					{
				
						j=removeLast(dequearray[i]);
						addFirst(dp, j);
					}
				}
			
			}
		}
	//Finally, when the input given is a character rather than an integer, the code lists the main deque in sorted order. 
				while(numItems(dp)>0)
				{
				finallydone=removeLast(dp);
				printf(" %d \n", finallydone);
				}	

			
		

			destroyDeque(dp);
return 0;

}


			
		
		



		
		

