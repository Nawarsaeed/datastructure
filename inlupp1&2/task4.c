

#include <stdlib.h>
#include <stdio.h>

typedef struct queueNode{ //a struct for the queue node

	int data;
	struct queueNode * nextptr;

}QueueNode;
typedef QueueNode *queueNodePtr;

//prototayp
int dequeue(queueNodePtr *headptr, queueNodePtr *tailptr);
void  enqueue(queueNodePtr *headptr, queueNodePtr *tailptr, int value);
double is_empty(queueNodePtr sPtr);
void print_list(queueNodePtr stack);


/*This function is implemented to push items into the queue
*@param headptr is a queue node poniter who points at the head
*@param tailptr is a queue pointer who points at hte end
*@param value is an inte variabel that data will be stored in
*/
void  enqueue(queueNodePtr *headptr, queueNodePtr *tailptr, int value)
{
  queueNodePtr  new = malloc(sizeof(QueueNode)); //create node

	if(new !=NULL){
	new->data=value;  //Place a value in node
	new->nextptr=NULL; //node does not link to another
	if(is_empty(*headptr)){
    *headptr=new;
  }
  else{
    (*tailptr)->nextptr=new;
  }
  *tailptr=new;


}
else{
  printf("%d not inserted, no memory available(voerflow).\n",value );
}

}
/*This function is implemented to delete items from the queue
*@param headptr is a queue node poniter who points at the head
*@param tailptr is a queue pointer who points at hte end 
*/
int dequeue(queueNodePtr *headptr, queueNodePtr *tailptr){
	queueNodePtr temp= *headptr;
	int value=(*headptr)->data;
	*headptr=(*headptr)->nextptr;

  if(*headptr==NULL){
    *tailptr=NULL;
  }
  free(temp);
  return value;

	}


double is_empty(queueNodePtr sPtr)
{
	return sPtr==NULL;
	}

void print_list(queueNodePtr queue)
{
	if (queue==NULL){
	printf("The queue is Empty, underflow\n");
}
	else {
	while(queue !=NULL)
	{
		printf("%d -->", queue->data);
	      queue=queue->nextptr;
		}
	printf("\n");
}

	}
queueNodePtr creat_queue(){

	return NULL;
	}

void queue(queueNodePtr head, queueNodePtr tail){

	head=creat_queue();
        tail=creat_queue();


		enqueue(&head,&tail,1);
		enqueue(&head,&tail,2);
		enqueue(&head,&tail,3);
		enqueue(&head,&tail,4);
		print_list(head);


		//if the queue is not empty
		if(!is_empty(head)){
		printf("%d has been dequeued\n", dequeue(&head,&tail));
		printf("%d has been dequeued\n", dequeue(&head,&tail));
		printf("The updated queue contains:\n");
		print_list(head);

}
}
void emptyqueue(queueNodePtr head, queueNodePtr tail){

		head  =creat_queue();
                tail =creat_queue();
		enqueue(&head,&tail,0);
		dequeue(&head,&tail);
		print_list(head);

	}

int main (void)
{

	printf("*******Enqueue a few items and then dequeue them***\n" );
		queueNodePtr headptr=creat_queue();
	  queueNodePtr tailptr=creat_queue();
		queue(headptr,tailptr);


  printf("*******Use pop on an empty stack***\n" );
	queueNodePtr headptr1=creat_queue();
  queueNodePtr tailptr1=creat_queue();
  emptyqueue(headptr1, tailptr1);

	return 0;

  }
