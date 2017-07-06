#include"tree.c"
#define maxsize 257
#include<stdio>
#include<stdlib>

int main(int argc, char*argv[])
{
	FILE *fp1;
	int words=0;
	
	 if(argc!=2){
		  printf("Unable to acquire the file name \n");
		  return 0;
	 } 
	 fp1=fopen(argv[1],"r");
	if(fp1==NULL) {
	printf("Unable to open the file\n");
	return 0;
	}
//creates a temporary array to store character counts as well as the leaves
//array to store the count values into a tree array
	int count[maxsize];
	struct tree *leaves[maxsize];
	struct tree *heap[maxsize];
	int i;
	int heapcount=0;

	c=getc(fp1);
	while(c!=EOF){
		count[c]++;
	}
//creates leaves array
	for(i=0;i<maxsize;i++){
		if(count[i]!=0){
			leaves[i]=createTree(count[i],NULL,NULL);
		}	
	}
	leaves[256]=createTree(EOF,NULL,NULL);

	for(i=0;i<maxsize;i++){
		if(leaves[i]!+NULL){
			heap[heapcount]=createTree(leaves[i]->value,NULL,NULL);
			heapcount++;
			balance((heapcount-1)/2);
		}	
	} 

	void balance(int index){
			struct tree* temp;
			int c=index;
			int p=(index-1)/2;
			while((c-1)>=0){
				if(heap[c]<heap[p])
				temp=heap[c];
				heap[c]=heap[p];
				heap[p]=temp;
				c--;
			}
	}
		
		

	void delete(){


}
//balance function
//then create heap w/ function 
