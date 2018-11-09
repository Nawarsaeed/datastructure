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


queue_ptr create_queue(int p);
void enqueue(queue_ptr queue, int f);
int dequeue(queue_ptr queue);
int isEmpty(queue_ptr queue);
int isFull(queue_ptr queue);
int printQueue(queue_ptr queue);

queue_ptr create_queue(int p){
  queue_ptr queue = malloc(sizeof(Queuestruct));
    queue->front =0;
    queue->rear = 0;
    queue->capacity = p;
    queue->array =(int *) malloc(sizeof(int)*p);
    return queue;
	}

void enqueue(queue_ptr queue, int f){
  if (isFull(queue)){
          printf("The queue is full\n");
					return;

      }

      queue->array[queue->rear] = f;
      queue->rear++;
	}


int dequeue(queue_ptr queue)
{
	int item;
  if (isEmpty(queue)){

          printf("the queue is empty\n");
					return -1;

      }

      return queue->array[queue->front++];
		}

int isEmpty(queue_ptr queue)
{
    return queue->front == queue->rear || queue->rear==0;
}

int isFull(queue_ptr queue)
{
     return queue->rear == queue->capacity;
}
int printQueue(queue_ptr queue)
		{
			int i = queue->front;
			if(isEmpty(queue)) {
			 printf("Queue is empty");
	 } else {
			 printf("\nQueue contains \n");
			 for(i = queue->front; i < queue->rear ; i++) {
							 printf("%d-> ", queue->array[i]);
			 }
	 }
}
