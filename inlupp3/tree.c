#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef
struct treenode {
  int data;
  struct treenode *leftPtr;
  struct treenode *righttPtr;
  struct treenode *parent;
}Treenode;
typedef Treenode *TreenodePtr;

typedef struct root{
  struct treenode *rootnode;
}Root;
typedef Root *rootptr;

void insertNode(rootptr T, TreenodePtr z);
void Delete(rootptr T, int v);
void inorder(TreenodePtr treeptr);
TreenodePtr minimum(TreenodePtr x);
void Transplant(rootptr T, TreenodePtr u, TreenodePtr v);

TreenodePtr Create_node(int d){
TreenodePtr tree =malloc(sizeof(Treenode));
tree->data=d;
tree->leftPtr=NULL;
tree->righttPtr=NULL;
tree->parent=NULL;
return tree;

}
void Transplant(rootptr T, TreenodePtr u, TreenodePtr v) {
	//root node
	if (u->parent == NULL) {

		T->rootnode = v;

	}
  else if (u == u->parent->leftPtr) {
		u->parent->leftPtr = v;
	}
  else {
		u->parent->righttPtr = v;
	}
	if (v != NULL) {
		v->parent = u->parent;
	}

}


int size(TreenodePtr node)
{
  if (node==NULL)
    return 0;
  else
    return(size(node->leftPtr) + 1 + size(node->righttPtr));
}


TreenodePtr Iterative_search(TreenodePtr x,int k){

  while(x!=NULL && k!= x->data ){
  if(k < x->data){

    x=x->leftPtr;
  }
  else{

    x=x->righttPtr;}

}

return x;
}
TreenodePtr maximum(TreenodePtr x){


  while (x->righttPtr !=NULL) {
    x=x->righttPtr;
  }
  return x;

}

TreenodePtr minimum(TreenodePtr x){

  while (x->leftPtr !=NULL) {
    x=x->leftPtr;
  }

  return x;
}


void Delete(rootptr T, int v){
  TreenodePtr z = malloc(sizeof(Treenode));
  z = Iterative_search(T->rootnode, v);
  if(z->leftPtr == NULL){

    Transplant(T,z,z->righttPtr);

  }
  else if(z->righttPtr == NULL){
    Transplant(T,z,z->leftPtr);
  }
  else{

    TreenodePtr y= minimum(z->righttPtr);

    if(y->parent !=z){
      Transplant(T,y,y->righttPtr);
      y->righttPtr=z->righttPtr;
      y->righttPtr->parent=y;
    }
    Transplant(T,z,y);

    y->leftPtr=z->leftPtr;
    y->leftPtr->parent=y;
  }


}
void insertNode(rootptr T, TreenodePtr z)
{
   TreenodePtr y = NULL;
   TreenodePtr x = T->rootnode;

   while (x != NULL) {
       y = x;
       if (z->data < x->data) {
           x = x->leftPtr;
       } else {
           x = x->righttPtr;
       }
   }

   z->parent = y;
   if (y == NULL) {
       T->rootnode = z;
   }
   else if  (z->data < y->data) {
           y->leftPtr = z;
       }
   else {
           y->righttPtr = z;
       }
   }
void inorder(TreenodePtr treeptr)
{
  //if tree is not empty , then traverse
  if(treeptr !=NULL){
    inorder(treeptr->leftPtr);
    printf("%d\t",treeptr->data );
    inorder(treeptr->righttPtr);
  }
}


TreenodePtr Successor(TreenodePtr x) {
    if (x->righttPtr != NULL) {
        return minimum(x->righttPtr);
    }
    TreenodePtr y = x->parent;
    while (y != NULL && x == y-> righttPtr) {
        x = y;
        y = y->parent;
    }
    return y;
}

TreenodePtr Predecessor (TreenodePtr x) {
    if (x->leftPtr != NULL) {
        return maximum(x->leftPtr);
    }
    TreenodePtr y = x->parent;
    while (y != NULL && x == y-> leftPtr) {
        x = y;
        y = y->parent;
    }
    return y;
}

int Depth(TreenodePtr N)
{
   if (N==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int leftDepth = Depth(N->leftPtr);
       int rirghtDepth = Depth(N->righttPtr);

       /* use the larger one */
       if (leftDepth > rirghtDepth)
           return(leftDepth+1);
       else return(rirghtDepth+1);
   }
}



void addfromfile()
{
  rootptr root=malloc(sizeof(Root));
  root->rootnode=NULL;
  int item;
  char rad;
	FILE *fp;
	int line;


	 //char *string[MAX];
	fp = fopen("output.txt", "r");

	if (fp == NULL){
			 printf("Could not open file");
			 
	 }
   fscanf(fp, "%d", &line);
   insertNode(root, Create_node(line));
                                  //T ,
   for (rad=getc(fp); rad!=EOF; rad = getc(fp)) {
     /* code */

	 fscanf(fp, "%d",&line);
//   Create_node(new_node, line[i]);
//   new_node->data=line[i];
//   printf("%d3",new_node->data );
//    new_node = Create_node(line[i]);
    insertNode(root, Create_node(line));
//  free(new_node);
}
  //   insertNode(root,new_node);
Delete(root,line);

 fclose(fp);


     printf("\n\nIn order is:");
    // TreenodePtr new_node = root->rootnode;
     inorder(root->rootnode);

     printf("\n\nThe minimim key is:%d\n",minimum(root->rootnode)->data);
     printf("\n\nThe maximum key is:%d\n",maximum(root->rootnode)->data);
     printf("\n\nThe depth of the tree is: %d", Depth(root->rootnode));
     printf("\n\nThe size of the tree is: %d", size(root->rootnode));



     item=431;
     printf("\n\nThe searched elemnet %d",item );
     if(Iterative_search(root->rootnode,item) == NULL){
       printf(" is not found in the list\n");
     }
     else{
       printf(" is founded!\n");
     }

    TreenodePtr Position=Iterative_search(root->rootnode,item);
     printf("\n\nThe Successor of %d is: ",item);
     if(item !=maximum(root->rootnode)->data){
     printf("%d\n",Successor(Position)->data);}
     else{
       printf("There is no Successor after item %d\n",item );
     }


     printf("\n\nThe Predecessor of %d is: ",item);
     if(item !=minimum(root->rootnode)->data){
       printf("%d\n",Predecessor(Position)->data);
     }
     else{
       printf("There is no Predecessor before item %d\n",item );

     }


    

     printf("\n\nThe elemnet %d has been deleted\n",item);
     Delete(root, item);

     printf("\n\nThe updated  inorder tree is:");
     inorder(root->rootnode);

}



int main()
{



  printf("\n\n*******Numbers from a file********\n");

  addfromfile();


return 0;

}


