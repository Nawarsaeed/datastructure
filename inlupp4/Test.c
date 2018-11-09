#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
  int data;
  struct Node* next;

}Node;

typedef struct Head{
  Node *h;
  int distance;
  int f;
  int papa;

}Head;

typedef struct Graph{
int VetNum;
int C;  //cycle
Head *list; //array

}Graph;

typedef Graph* Gptr;
