#include<stdio.h>
#define	MAX	50 //it depends entirely on the size of the file



/* This function takes the numbers from a file and store them in an array*/
int openfromfile(int Array[MAX])
	{
		FILE *ptr_file;
		int i;
		ptr_file = fopen("output.txt", "r");
		if(ptr_file==NULL){
			printf("Error" );
		}

		for(i=0; i<MAX;i++){
			fscanf(ptr_file,"%d", &Array[i]);
		}


fclose(ptr_file);

return 0;

	}


void	display(int	array[]){
int	i;
  //	navigate	through	all	items
	for(i	=	0;i<MAX;i++){
   printf("%d ",array[i]);
 }
 printf("\n");
}
/* This function is implemented to sort an array using insertion sort*/
void	insertionSort(int array[]){

  int	valueToInsert;
  int	holePosition;
	int	i;
  //	loop	through	all	numbers
  for(i	=	1;	i	<	MAX;	i++){
     //	select	a	value	to	be	inserted.
     valueToInsert	=	array[i];
   //	select	the	hole	position	where	number	is	to	be	inserted
   holePosition	=	i;
    //	check	if	previous	no.	is	larger	than	value	to	be	inserted
  	while	(holePosition	>	0	&& array[holePosition-1]	>	valueToInsert)
    {	array[holePosition]	= array[holePosition-1];
       holePosition--;

     	}
    if(holePosition	!=	i){
     //	insert	the	number	at	hole	position
     array[holePosition]	=	valueToInsert;
   	}

   }	}
void main(){
	int array[MAX];
	openfromfile(array);
    printf("Input	Array: ");
    display(array);

    insertionSort(array);
     printf("Output	Array: ");
    display(array);

 }
