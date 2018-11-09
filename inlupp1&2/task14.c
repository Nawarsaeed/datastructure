#include	<stdio.h>
#define	max	50

/* This function takes the numbers from a file and store them in an array*/
int openfromfile(int array[max])
	{

		FILE *ptr_file;
		int i;
		ptr_file = fopen("output.txt", "r");
		if(ptr_file==NULL){
			printf("Error" );
		}

		for(i=0; i<max;i++){
			fscanf(ptr_file,"%d", &array[i]);
		}


fclose(ptr_file);

return 0;

	}

/* This function is implemented to merge tow subaarays of array[]*/
void merg(int array[], int	low,	int	mid,	int	high)
	{
		 int left = mid - low;
		 int right = high - mid;

		 int array_left[left];
		 int array_right[right];

		 for (int i = 0; i < left; i++)
				 array_left[i] = array[low + i];
		 for (int j = 0; j < right; j++)
				 array_right[j] = array[mid + j];

		 int i = 0, j = 0, k = low;
		 while (i < left && j < right) {
				 if (array_left[i] <= array_right[j])
						 array[k++] = array_left[i++];
				 else
						 array[k++] = array_right[j++];
		 }
		 /* select the remaining elements of array_left[], if there
       are any */
		 while (i < left)
				 array[k++] = array_left[i++];

				 /* select the remaining elements of array_right[], if there
		 			are any */
		 while (j < right)
				 array[k++] = array_right[j++];
	 }
 /* this function is implemented to make the mergesort
 * @param low is for left index.
 *@param high is right index of the
   sub-array of arrray[] to be sorted */
void	sort(int array[], int	low,	int	high)	{
	if (low < high - 1) {
	int middle = (low + high ) / 2;

	sort(array, low, middle);
	sort(array, middle, high );

	merg(array, low, middle, high );
}

}
int	main()	{
	int array[max];
  int	i;


	openfromfile(array);
  printf("List	before	sorting\n");
  for(i	=	0;	i	<	max;	i++)
    printf("%d	",	array[i]);
    sort(array,0,	max);
  printf("\nList	after	sorting\n");
  for(i	=	0;	i	<	max;	i++)
      	printf("%d	",	array[i]);
return 0;

	}
