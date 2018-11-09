
#include <stdlib.h>
#include <stdio.h>

// en struct som presenterar en listnode
typedef
struct listNode{

	int data;
	struct listNode * nextptr;

}ListNode;
//synonyms
int openfromfile(FILE *ptr_file);
int addfromfile(ListNode **list);
int is_empty(ListNode *sPtr);
void print_list(ListNode** list);
void sortedInsert(ListNode** result, ListNode* new_Node);
ListNode *InsertionSort(ListNode **head);

ListNode *InsertionSort(ListNode **head)
{
    // Initialize the linked list
    ListNode *result =NULL;

    // search the given list
    ListNode *curr = *head;
    while (curr != NULL)
    {
        // check the next iteration
        ListNode *next = curr->nextptr;
        // insert current in the linked list
        sortedInsert(&result,curr);
        curr = next;
    }
return result;

}
//Inserting the node in correct position in result list
void sortedInsert(ListNode** result, ListNode* new_Node)
{
   ListNode* temp;
   //If there is no element in result list
   if (*result == NULL || (*result)->data >= new_Node->data)
   {
       new_Node->nextptr = *result;
       *result = new_Node;
   }
   else
   {
       //finding the position to insert the node
       temp = *result;
       while (temp->nextptr!=NULL && temp->nextptr->data < new_Node->data)
       {
           temp = temp->nextptr;
       }
       new_Node->nextptr = temp->nextptr;
       temp->nextptr = new_Node;
   }
}



// returns 1 if the list is empty , 0 aotherways
int is_empty(ListNode* sPtr)
{
	return sPtr==NULL;
	}
/* funktion is used to print the list
 * @param list is a pointer pointing to the end of the list
 */
void print_list(ListNode** list)
{
ListNode*temp=*list;
while(temp!=NULL) //till the list ends (NULL marks ending of list)
  {
    if(temp->nextptr!=NULL){
    printf("%d->",temp->data);}
    else{
    printf("%d\n",temp->data);
}
    temp=temp->nextptr; //move to next node

  }
  printf("");
}

int addfromfile(ListNode **list)
{
	FILE *fp;
	char rad;
	int line;
	fp = fopen("output.txt", "r");

	if (fp == NULL){
			 printf("Could not open file");
			 return 1;
	 }
	 fscanf(fp, "%d", &line);
	 ListNode* new_node = malloc(sizeof(ListNode));
	 /* put in the data  */
	 new_node->data=line;

	 /* link the old list off the new node */
	 new_node->nextptr = (*list);

	 /* move the head to point to the new node */
	 (*list) = new_node;


   for(rad=getc(fp); rad!=EOF; rad = getc(fp)) {
	 fscanf(fp, "%d",&line);
		 ListNode* new_node = malloc(sizeof(ListNode));


		 /* put in the data  */
		 new_node->data  = line;

		 /* link the old list off the new node */
		 new_node->nextptr = (*list);

		 /* move the head to point to the new node */
		 (*list) = new_node;


		 }

	 fclose(fp);
	 return 0;
}

/*A function to add element inot the linked list */
void push(ListNode** head_ref, int new_data)
{
    /* allocate node */
    ListNode* new_node = malloc(sizeof(ListNode));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->nextptr = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
int main ()
{
 int it;
	ListNode* startptr=NULL;
  ListNode* result=NULL;

//openfromfile(startptr);
	addfromfile(&startptr);  // sunbroutin of function push
	printf("Input of elements:");
	print_list(&startptr);




  result=InsertionSort(&startptr);
	printf("Output of elements:");
  print_list(&result);

	return 0;
	}
