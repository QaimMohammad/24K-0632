#include<stdio.h>
int main(){
	int array[5],i,smallest,secondSmallest;
	
	printf("Enter 5 elements for the array(value must be LESS than 9999)\n");
	for(i=0;i<5;i++)
	{ do{
	
		printf("Please Enter Element - %d\n",i);
		scanf("%d",&array[i]);
		if (array[i]>=9999)
		printf("Invalid Input!\n");
		}
      while(array[i]>=9999);
	
	}

    if (array[0]<array[1])
     {
     	smallest=array[0];
     	secondSmallest=array[1];
     	
	 }
	else if(array[0]>array[1]){
	 	
	 	smallest=array[1];
	 	secondSmallest=array[0];
	 	
	 }
	for(i=2;i<5;i++)
	 {
	 	if(array[i]<smallest){
	 		
	 		secondSmallest=smallest;
	 		smallest=array[i];
	 		
		 }
		 else if(array[i]<secondSmallest && array[i]!=smallest){
		 	secondSmallest=array[i];
		 }
	 }
	printf("The second smallest element in the array is - %d ",secondSmallest);

	 return 0;
}
