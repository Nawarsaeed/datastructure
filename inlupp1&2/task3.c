#include <stdio.h>
#include <stdlib.h>
#define  ARRAY 20

typedef struct stack_struct
{
	int indx;
	int info[ARRAY];
	int top;
}Stackstruct;

typedef Stackstruct * stack_ptr;


void create_stack(stack_ptr p){
	int i = 0;
	while (i < ARRAY){
		p->info[i] = 0;
		i++;}
	}

int push(stack_ptr p, int f){
	int i = 19;

	if (p->info[19] == 0){
	while (i > 0){
	p->info[i] = p->info[i-1];
	i--;}
	p->info[0] = f;
	return 0;}
	else{
		return 1;}
}


int pop(stack_ptr p){
	int i = 0;
	if(p->info[0] != 0){
		while (i < 19){
			p->info[i] = p->info[i+1];
			i++;}
			p->info[19] = 0;}

	}

  double is_empty(stack_ptr sPtr)
  {
  	return sPtr==NULL;
  	}
void print(stack_ptr p){
	int i = 19;
	int f = 0;
	if (p->info[0] == 0){
		printf("The stack is empty!\nYour pop function will be ignored!\n");
		}
	if (p->info[19] != 0){
		printf("The stack is full!\nYour push function will be ignored!\n");
		}
	while(p->info[i] == 0){
		i--;}
	while (f < (i+1)){
		printf("%d\n",p->info[f]);
		f++;

		}
	}
  void instructions(void){
    printf("Enter choice:\n"
          "1 to push a value\n"
          "2 to pop a value\n"
          "3 to end program");

  }


int main(void){
	struct stack_struct s;
	stack_ptr P = &s;
	create_stack(P);
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
      push(P,item);
      print(P);
      break;

      case 2:
      //if stack is not empty
      if(!is_empty(P)){
      printf("The popped value is %d.\n", pop(P));
    }
    print(P);
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

/*
	for(int i=1; i <argc;i++){
	item=atof(argv[i]);
	push(p,item);
}
	pop(p);
	print(p);
	return 0;}*/
