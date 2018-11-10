#include <stdio.h>
#include <stdlib.h>
#define  ARRAY 20

typedef struct stack_struct
{
	int info[ARRAY];

}Stackstruct;

typedef Stackstruct * stack_ptr;


void create_stack(stack_ptr p){
	int i = 0;
	while (i < ARRAY){
		p->info[i] = 0;
		i++;}
	}
int isFull(stack_ptr p){
	if (p->info[19] != 0) // medelanden om stacken är tom
		{
		
		return 1;
		}
	return 0;
}
int push(stack_ptr p, int f){
	int i = 19;
	if (isFull(p)){
		printf("The stack is full!\nYour push of %d function will be ignored!\n",f);
		return 1;
	}
   if(!isFull(p)){
	while (i > 0 )
		{
	p->info[i] = p->info[i-1];
	i--;}
	p->info[0] = f; 
}
	return f;
	return 0;
	}
int is_empty(stack_ptr sPtr)
  {

  	return sPtr==NULL;

  	}

int pop(stack_ptr p){
	int i = 0;
	if (is_empty(p)) // medelanden om stacken är tom
		{
		printf("The stack is empty!\nYour pop function will be ignored!\n");
		return 0;
		}
	if(p->info[0] == 0 || p->info[0] != 0){
		while (i < 19){
			p->info[i] = p->info[i+1];
			i++;}
			p->info[19] = 0;
		}

return p->info[0];
}



int print(stack_ptr p){
	int i = 19;
	int f = 0;
	

	while(p->info[i] == 0){
		i--;}
	while (f < (i+1)){
		printf("%d->",p->info[f]);
		f++;

		}
		return 0;
	}




int main(void){




	//struct stack_struct s;
	stack_ptr P = malloc(sizeof(Stackstruct)); //&s;
	create_stack(P);
printf("\n\n*******Push a few items and then pop them******\n\n" );
printf("The pushed elements into the stack are:\n");
      push(P,1);
			push(P,7);
			push(P,8);
			push(P,11);
			push(P,71);
			push(P,82);
			push(P,19);
			push(P,78);
			push(P,87);
			push(P,16);
			push(P,74); // the first pushed elemnet


  print(P);

      if(!is_empty(P)){

      printf("\n\nThe stack is updated and the first item of the stack is %d\n ",pop(P));
    }
		printf("\n\nThe new stack is:\n" );
    print(P);



		printf("\n\n**********push another element on completely filled array *****\n\n" );
		int item=100;
		push(P,89);
		push(P,90);
		push(P,91);
		push(P,92);
		push(P,93);
		push(P,94);
		push(P,95);
		push(P,96);
		push(P,97);
		push(P,98);
		push(P,98);
		push(P,item); // the extra elemnet which will not be pushed into the stack
		
		print(P);

		//struct stack_struct q;
		stack_ptr k = NULL;
		printf("\n\n*******Use pop on an empty stack******\n" );
		//print(k);
		pop(k);
		//print(k);

	}
