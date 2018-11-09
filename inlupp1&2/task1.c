
#include <stdlib.h>
#include <stdio.h>
typedef

struct listNode{
	int data;
	struct listNode * nextPtr;
  struct listNode * prevPtr;


}ListNode;

typedef ListNode * DoublyList;//struct synonym

///it's like an empty list
DoublyList creat_list()
{

	return NULL;
	}
DoublyList delete(DoublyList *head,  DoublyList key);
int maximum(DoublyList head);
int minimum(DoublyList head);
DoublyList search(DoublyList head,  int value);
void *Insert(DoublyList *head, int data);
int IsEmpty(DoublyList head);
void PrintList(DoublyList);


/*this function is implemented to inser items into the list
*@parma head is a pointer whos points at the begining of list
*@param tail points at the end of the list
*/
void *Insert(DoublyList *head,  int value)
{
DoublyList newNode;
	DoublyList traverser, checker;
	newNode = malloc(sizeof(ListNode)); // create an empty list
	newNode->data = value;
	if(*head == NULL)  // if the head has no value
	{
		newNode->nextPtr = NULL;
		newNode->prevPtr = NULL;
		*head = newNode;
	}
	else
	{
		if((*head)->data > value)
		{
			newNode->prevPtr = NULL;
			newNode->nextPtr = *head;
			(*head)->prevPtr = newNode;
			*head = newNode;
		}
		else
		{
			traverser = *head;
			checker = traverser->nextPtr;
			while(checker != NULL)
			{
				if(traverser->data <= value && checker->data > value)
					break;
				traverser = traverser->nextPtr;
				checker = checker->nextPtr;
			}
			newNode->nextPtr = checker;
			newNode->prevPtr = traverser;
			traverser->nextPtr = newNode;
			if(checker != NULL)
				checker->prevPtr = newNode;
		}
	}
}

DoublyList delete(DoublyList *head,  DoublyList key)
	{
		DoublyList traverser;
		if(key == NULL)
			printf("Value not present in the list\n");
		else
		{
			if(*head == key)
			{
				*head = key->nextPtr;
				if(*head != NULL)
					(*head)->prevPtr = NULL;
				free(key);
			}
			else
			{
				traverser = *head;
				while(traverser->nextPtr != key)
					traverser = traverser->nextPtr;
				traverser->nextPtr = key->nextPtr;
				if(key->nextPtr != NULL)
					key->nextPtr->prevPtr = traverser;
				free(key);
			}
		}
	}

int maximum(DoublyList head)
{

    int max=head->data;

    // Check loop while head not equal to NULL
    while (head != NULL) {

        // If max is less then head->data then
        // assign value of head->data to max
        // otherwise node point to next node.
				if (max < head->data)
            max = head->data;
        head = head->nextPtr;
			}
  return max;

}


int minimum(DoublyList head)
{

    int min = head->data;

    // Check loop while head not equal to NULL
    while (head != NULL) {

        // If max is less then head->data then
        // assign value of head->data to max
        // otherwise node point to next node.
        if (min > head->data)
            min = head->data;
        head = head->nextPtr;
    }

    return min;
}

int SUCCESSOR(DoublyList x){

	if (x->nextPtr != NULL) {
         return minimum(x->nextPtr);
 }
 else{
 	return x->data;
 }

}


int PREDECESSOR(DoublyList x){

	if (x->prevPtr != NULL) {
        return minimum(x->prevPtr);
}
else{
	return x->data;
}
}

DoublyList search(DoublyList head,  int value){
	while(head != NULL)
{
	if(head->data == value)
		return head;
	else
		head = head->nextPtr;
}

return NULL;
}


int IsEmpty(DoublyList head)
{
	return head==NULL;
	}

void PrintList(DoublyList head)
{
	if(head == NULL)
		printf("The list is empty\n");
	else
	{

		do
		{
			printf("%d ",head->data);
			head = head->nextPtr;
		}
		while(head != NULL);
		printf("\n");
	}
}
//This function is implemented to test all of the dynamic sets
void test(DoublyList startptr){
	int item =2555;
	startptr=creat_list();
	Insert(&startptr,6);
	Insert(&startptr,2555);
	Insert(&startptr,3000);
	Insert(&startptr,2);
	printf("The inserted elements are:");
	PrintList(startptr);

	printf("\n\nThe minimim key is:%d\n",minimum(startptr));
  printf("\n\nThe maximum key is:%d\n",maximum(startptr));

  DoublyList searchh= search(startptr,item);
  if(searchh != NULL){
    printf("\n\n %d is found in the list\n",item);

		printf("\n\nThe Successor of %d is:%d\n",item,SUCCESSOR(searchh));
		printf("\n\nThe predecessor of %d is:%d\n",item,PREDECESSOR(searchh));
	;
		delete(&startptr,searchh);
		printf("\n\nThe element %d Has been deleted\n",item);
	}
	else{
			printf("\n\n %d is not found in the list\n",item);
		}


		printf("\n\nThe updated list is:");
    PrintList(startptr);

}

int main ()
{

	DoublyList startptr=creat_list();
	test(startptr);

return 0;

	}
