#include <stdio.h>
#include <stdlib.h>


typedef struct queue_struct
{
	int *array;
	int front;
	int rear;
	int capacity;

}Queuestruct;

typedef Queuestruct * queue_ptr;

//sysnonyms
queue_ptr create_queue(unsigned int p);
int isEmpty(queue_ptr queue);
int isFull(queue_ptr queue);


/*this function is implemented to create a queue as an array
*@Param p is used to make the capacity of the queue*/
queue_ptr create_queue(unsigned int p){
	queue_ptr queue = malloc(sizeof(Queuestruct));
    queue->front =0;
    queue->rear = 0;
    queue->capacity = p;
    queue->array =(int *) malloc(sizeof(int)*p); // the array taht will contains the element
    return queue;
	}
/*this function is implemented to add element into the queue*/
void enqueue(queue_ptr queue, int f){
	if (isFull(queue)){
          printf("The queue is full\n");
					return;

      }
			/*the first element will be adding to the array as a fro pointer
			*And the rerar will point on the next element
			*/
      queue->array[queue->rear] = f;
      queue->rear++;
	}

/*This function is implemented to remove elments from the array*/
int dequeue(queue_ptr queue)
{
	int item;
  if (isEmpty(queue)){

          printf("the queue is empty\n");
					return -1;

      }
			// Removing an elemet will happen, when the frontpointer movies
      return queue->array[queue->front++];
		}
int isEmpty(queue_ptr queue)
		{
		    return queue->front == queue->rear || queue->rear==0;
		}

int isFull(queue_ptr queue)
		{
		    return queue->rear == queue->capacity; //full if rear =capacity
		}


int printQueue(queue_ptr queue)
		{

			if(isEmpty(queue)) {
			 return -1;}
			 else if (isFull(queue)){

				 return 0;
			 }
	  else {
			 printf("Queue contains \n");
			 for(int i = queue->front; i < queue->rear; i++) {
							 printf("%d-> ", queue->array[i]);
			 }
	 }
}

int main(void){

printf("**********Use dequeue on an empty queue*****\n" );
queue_ptr A =create_queue(4);
dequeue(A);

printf("\n\n**********Enqueue a few items and then dequeue them*****\n" );
queue_ptr B =create_queue(4);


			enqueue(B,3);
      enqueue(B,7);
			enqueue(B,8);
			printQueue(B);

			if (!isEmpty(B)) {
      printf("\nThe dequeued value is: %d",dequeue(B));
			printf("\nThe dequeued value is: %d",dequeue(B));


		}

		printf("\nThe updated ");
		printQueue(B);


printf("\n\n**********enqueue another element on completely filled array *****\n" );

queue_ptr C =create_queue(4);

			enqueue(C,3);
			enqueue(C,7);
			enqueue(C,8);
			enqueue(C,9);
			enqueue(C,10);
			printQueue(C);

	}
