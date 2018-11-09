#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Queue.h"



Graphptr directedgraph(Graphptr g){


  addEdge(g, 0, 2, 1);
  addEdge(g, 2, 3, 1);
  addEdge(g, 4, 2, 1);
  addEdge(g, 3, 1, 1);
  addEdge(g, 1, 4, 1);
  printGraph(g);

}

Graphptr undirectedgraph(Graphptr g){
  addEdge(g, 1, 1, 1);
  addEdge(g, 1, 2, 1);
  addEdge(g, 2, 3, 1);
  printGraph(g);

}


Graphptr getoutNeighbors(Graphptr g,int v){

          Nodeptr temp = g->adjLists[v].head;
          while (temp !=NULL)
          {
              printf("%d -> ", temp->vertex);
              temp = temp->next;
          }

      }

Graphptr getinNeighbors(Graphptr g,int v){

      Nodeptr temp;
      temp= getinneighbors(g,v);

      while (temp !=NULL)
          {
              printf("%d -> ", temp->vertex);
              temp = temp->next;
          }


  }
Graphptr getNeighbors(Graphptr g,int v){

     getoutNeighbors(g,v);
     getinNeighbors(g,v);

}


int main()
{
  printf("===== Directed Graph=====\n");
    Graphptr a=createGraph(6,Directed);
    directedgraph(a);
    printf(" Has edge: %d\n ",hasEdge(a,1,3));
    printf("Total edges: %d\n ",getNumEdges(a));
    printf("The number of vertices in the graph is: %d\n",getNumVertices(a));

    printf("\n The vertices connected to %d with an edge is(Neighbors):", 2);
    getNeighbors(a,2);
    printf("\n The vertices connected to %d with an edge is(InNeighbors):", 2);
    getinNeighbors(a,2);
    printf("\n The vertices connected to %d with an edge is (outNeighbors):", 2);
    getoutNeighbors(a,2);


  printf("\n\n===== Undirected Graph=====\n");
    Graphptr b=createGraph(4,Undirected);
    undirectedgraph(b);
    printf(" Has edge: %d\n ",hasEdge(b,2,1));
    printf("Total edges: %d\n ",getNumEdges(b));
    printf("The number of vertices in the graph is: %d\n",getNumVertices(b));
    printf("\n The vertices connected to %d with an edge is(Neighbors):", 2);
    getNeighbors(b,2);
    printf("\n The vertices connected to %d with an edge is(InNeighbors):", 2);
    getinNeighbors(b,2);
    printf("\n The vertices connected to %d with an edge is (outNeighbors):  ", 2);
    getoutNeighbors(b,2);
  }
/*
    printf("The number of vertices in the graph is: %d\n",getNumVertices(directedgraph));
    printf("The number of edges in the graph is: %d\n ",getNumEdges(directedgraph));
    printf("Has edge: %d\n ",hasEdge(directedgraph,0,5));

    return 0;
}*/
