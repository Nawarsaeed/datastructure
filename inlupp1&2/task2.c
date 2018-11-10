

#include <stdlib.h>
#include <stdio.h>

typedef struct stack_struct{

	int data;
	struct stack_struct * nextptr;

}Stackstruct;
typedef Stackstruct *stack_ptr;

//prototayp
void push(stack_ptr *stack, int d);
int  pop(stack_ptr *stack);
double is_empty(stack_ptr sPtr);
void print_list(stack_ptr stack);



void push(stack_ptr *stack, int d)
{
    stack_ptr new = malloc(sizeof(Stackstruct)); //create node

	if(new !=NULL){
	new->data=d;  //Place a value in node
	new->nextptr=*stack;
	*stack=new;
}

}

int pop(stack_ptr *stack)
{
	
	stack_ptr temp= *stack;
	int popvalue=(*stack)->data;
	*stack=(*stack)->nextptr;
	free(temp);
	
	return popvalue;

	}


double is_empty(stack_ptr sPtr)
{
	return sPtr==NULL;
	}

void print_list(stack_ptr stack)
{
	if (stack==NULL){
	printf("The stack is Empty,underflow \n");
}
	else {
	while(stack !=NULL)
	{
		printf("%d -->", stack->data);
	      stack=stack->nextptr;
		}
	printf("\n");
}

	}
stack_ptr create_stack(){

	return NULL;
	}



int main ()
{
	stack_ptr startptr=create_stack();
    //push some values
    push(&startptr,1);
		push(&startptr,2);
		push(&startptr,3);
    print_list(startptr); // print the values

		//if not empty, then pop
    if(!is_empty(startptr)){
    printf("The popped value is %d.\n", pop(&startptr));
		printf("The popped value is %d.\n", pop(&startptr));
		printf("The popped value is %d.\n", pop(&startptr));
  }
  print_list(startptr);

	printf("*******Use pop on an empty stack***\n");
	stack_ptr startptr1= malloc(sizeof(Stackstruct));
	pop(&startptr1);
	print_list(startptr1);
return 0;
	}
