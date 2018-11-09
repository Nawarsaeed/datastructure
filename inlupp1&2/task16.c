#include <stdio.h>
#include <stdbool.h>
#define	MAX	50


/* This function takes the numbers from a file and store them in an array*/
int openfromfile(int array[])
	{
		FILE *ptr_file;
		int i;
    //char *string[MAX];
		ptr_file = fopen("output.txt", "r");// reding mode of the file
		if(ptr_file==NULL){
			printf("Error" );
		}

		for(i=0; i<MAX;i++){
			fscanf(ptr_file,"%d", &array[i]); //store the number form the file
		}


fclose(ptr_file);

return 0;

	}
/* This function is implemented to make distance between th operartions*/
void	printline(int	count){
  	int	i;
     for(i=	0;i	<count-1;i++){
    	printf("=");
     }
   printf("=\n");
 }

/*This funcktion is used to make a [] between the arrays*/
void	display(int array[]){
  	int	i;
     printf("[");
      //	navigate	through	all	items
    for(i	=	0;i<MAX;i++)
    {
       printf("%d	",array[i]);
     	}
  printf("]\n");
}

void	swap(	int array[], int	num1,	int	num2)
{
 int	temp	=	array[num1];
  array[num1]	=	array[num2];
 array[num2]	=	temp;
}

/*
*This function is implemented to select the elements from the arrays
* @param left is the first element of the array who will be copmared to the pivot
*@param Right is the last element of the array to be compared to the pivot*/
int	partition(int array[], int	left,	int	right,int	pivot)
 {
	int	leftPointer	=	left-1;
  int	rightPointer	=	right;
   while(true){


     while(array[++leftPointer]	<	pivot){
       //do	nothing
     }
     while(rightPointer	>	0	&&	array[--rightPointer]	>	pivot){
          //do	nothing
        }
     if(leftPointer	>=	rightPointer){
    	break;
    }
      else{
        printf("item swapped	:%d,%d\n",array[leftPointer],array[rightPointer]);
       swap(array,leftPointer,rightPointer);
      }
      }

printf("pivot swapped	:%d,%d\n",array[leftPointer],array[right]);
swap(array,leftPointer,right);
printf("Updated	Array:	");
 display(array);
return leftPointer;
 }

/*this is the quickSort function that does the comperation between rigth, left and the pivot*/
void	quickSort(int array[], int	left,	int	right){
   if(right-left	<=	0){
      return; }
      else	{ int	pivot	=	array[right]; // Make	the	right-most index valu	pivot
   int	partitionPoint	=	partition(array,left,	right,	pivot);
  	quickSort(array,left,partitionPoint-1);
    quickSort(array, partitionPoint+1,right);
   }
  }
void main(){
	 int Array[MAX];
   openfromfile(Array);

   printf("Input	Array:");
   display(Array);

	 printline(50);
   quickSort(Array,0,MAX-1);

	 printline(50);
   printf("\n\nOutput	Array: ");
	 display(Array);
}
