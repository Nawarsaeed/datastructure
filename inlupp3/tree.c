#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef
struct treenode {
  struct treenode *leftPtr;
  int data;
  struct treenode *righttPtr;
}Treenode;
typedef Treenode *TreenodePtr;

void insertNode(TreenodePtr *treeptr, int value);
void inorder(TreenodePtr treeptr);


void insertNode(TreenodePtr *treeptr, int value)
{
  //if tree is Empty
  if(*treeptr==NULL){
    *treeptr=malloc(sizeof(Treenode));
  //if memory is allocsted, assign data
  if(*treeptr !=NULL){
    (*treeptr)->data=value;
    (*treeptr)->leftPtr=NULL;
    (*treeptr)->righttPtr=NULL;
  }
  else{
    printf("%d not inserted, no memory available.\n", value);

  }
}
  //tree is not empty
  else
  {
    //data to insert is less than data in current noden
    if(value < (*treeptr)->data){
      insertNode(&((*treeptr)-> leftPtr),value);
    }
    //data to insert is greater than data in current noden
    else if(value >(*treeptr)->data){
      insertNode(&((*treeptr)->righttPtr),value);
    }
    //duplicate data calue ignored
  /*  else{
      printf("%s","dup" );
    }*/

  }
}
void inorder(TreenodePtr treeptr)
{
  //if tree is not empty , then traverse
  if(treeptr !=NULL){
    inorder(treeptr->leftPtr);
    printf("%3d",treeptr->data );
    inorder(treeptr->righttPtr);
  }
}

int main(void)
{
  TreenodePtr rootptr=NULL; //tree initially Empty
  srand(time(NULL));
  printf("the emelmnets in the tree are: \n");
  for(unsigned int i=1; i<=10; i++){
    int item=rand()%30;
    printf("%3d",item );
    insertNode(&rootptr,item);
  }
  printf("\n\nIn order is:");

  inorder(rootptr);
}
