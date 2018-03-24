

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
	new->nextptr=*stack; //node does not link to another
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
	printf("The stack is Empty\n");
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
stack_ptr creat_stack(){

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
	stack_ptr startptr=creat_stack();
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
    push(&startptr,item);
    print_list(startptr);
    break;

    case 2:
    //if stack is not empty
    if(!is_empty(startptr)){
    printf("The popped value is %d.\n", pop(&startptr));
  }
  print_list(startptr);
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
