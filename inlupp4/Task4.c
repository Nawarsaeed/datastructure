#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"


void dfs_visit(Graphptr g, int src, int visited[], int timez) {
	timez=timez +1;
	g->adjLists[src].distans=timez;
	visited[src] = 1;

	Nodeptr iter = g->adjLists[src].head;

	for(;iter != NULL; iter = iter->next) {
		if(visited[iter->vertex] == 0){
			g->adjLists[iter->vertex].pi=src;
		dfs_visit(g, iter->vertex, visited,timez);
	}
	if(visited[iter->vertex] == 1)
		g->cycle = g->cycle + 1;
	}
	visited[src] = 2;
	timez = timez + 1;


}


void dfs(Graphptr g) {
	
	g->cycle = 0;
	int visited[g->totalVertices];
  int timez;
	for(int i = 0; i < g->totalVertices; i++){
		visited[i] = 0;
		g->adjLists[i].pi=-1;
	}

	timez =0;
	for(int d = 0; d < g->totalVertices; d++){
		if(visited[d]==0){
		dfs_visit(g, d, visited, timez);}
	}
	//free(visited);
}

void cycle(){
	Graphptr g=NULL;
	g = createGraph(4,Directed);
	addEdge(g, 1, 3, 1);
	addEdge(g, 3, 2, 1);
	addEdge(g, 2, 1, 1);
	addEdge(g, 3, 3, 1);
	addEdge(g, 2, 2, 1);
	addEdge(g, 2, 3, 1);
	printGraph(g);
    dfs(g);
	printf("\nThe graph has %d cycles.\n", g->cycle);
}


void acycle(){
	Graphptr g=NULL;
	g = createGraph(4,Directed);
	addEdge(g, 1, 2, 1);
	addEdge(g, 1, 3, 1);
	addEdge(g, 3, 2, 1);
	printGraph(g);
  dfs(g);
	printf("\nThe graph has %d cycles.\n", g->cycle);
}
int main()
{
printf("********(Test(1): cycle graph)*********\n");
    Graphptr cyclegraph=NULL;
		cycle(cyclegraph);


printf("********(Test(2): acycle graph)*********\n");
		Graphptr acyclegraph=NULL;
		acycle(acyclegraph);

}
