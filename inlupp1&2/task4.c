

#include <stdlib.h>
#include <stdio.h>

typedef struct queueNode{

	int data;
	struct queueNode * nextptr;

}QueueNode;
typedef QueueNode *queueNodePtr;

//prototayp
int dequeue(queueNodePtr *headptr, queueNodePtr *tailptr);
void  enqueue(queueNodePtr *headptr, queueNodePtr *tailptr, int value);
double is_empty(queueNodePtr sPtr);
void print_list(queueNodePtr stack);



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
  printf("%d not inserted, no memory available.\n",value );
}

}

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
	printf("The queue is Empty\n");
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

void instructions(void){
  printf("Enter choice:\n"
        "1 to push a value\n"
        "2 to pop a value\n"
        "3 to end program");

}


int main (void)
{
	queueNodePtr headptr=creat_queue();
  queueNodePtr tailptr=creat_queue();
	int item;


instructions();
printf("%s","?");
unsigned int choice;
scanf("%u",&choice);

while(choice !=3){
  switch(choice){
    case 1:
    printf("enter an integer: ");
		scanf("%d",&item);
    enqueue(&headptr,&tailptr,item);
    print_list(headptr);
    break;

    case 2:
    //if stack is not empty
    if(!is_empty(headptr)){
      item=dequeue(&headptr,&tailptr);
    printf("%d has been dequeued\n", item);
  }
  print_list(headptr);
  break;

   default:
   printf("invaild choice\n");
   instructions();
   break;
  }
  printf("%s","?");
  scanf("%u",&choice);
}
	printf("End of program\n");
	}
