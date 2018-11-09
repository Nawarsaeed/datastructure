#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"
/*This is the BFS-algorithem function
*@param graph is is the graph
*@param s is the starting Node
*/

void print_path(Graphptr graph, int s, int v)
{

	if(v == s){
		printf(" ");
		}

	if(graph->adjLists[v].pi == -1){
		printf("%d", v);
  }

	else {
    printf("%d ", v);
		print_path(graph, s, graph->adjLists[v].pi);

		}
}


void bfs(Graphptr graph, int s, int d)
{
    int visited[graph->totalVertices];
    int i;
    int w;
    for (int i = 0; i < graph->totalVertices; i++){
        visited[i] = 0;}

    queue_ptr queue=create_queue(graph->totalVertices);

    enqueue(queue, s);
    visited[s] = 1;
    graph->adjLists[s].distans=0;
//    printf("%d\n", graph->adjLists[s].distans);
//  printf("\nBFS:");
    while (!isEmpty(queue)) {
        int temp = dequeue(queue);
//        printf("%d ", temp);
    Nodeptr cur = graph->adjLists[temp].head;
        while (cur!=NULL){

            if (visited[cur->vertex]==0) { //discover the undiscoverd vertices

                enqueue(queue,cur->vertex);
                graph->adjLists[cur->vertex].distans = graph->adjLists[temp].distans + 1;

                visited[cur->vertex] = 1;
                  graph->adjLists[cur->vertex].pi=temp;

            }
            cur = cur->next;
        }
    }
    free(queue);
    print_path(graph, s, d);
}
/*This function is implemented to print a path
*@param G is a graph pointer
*@param s is source
*@param v is destnation
*/


int main()


{

  Graphptr G = createGraph(100,Directed);

	for(int i = 0; i < 100; i++){


		int down_step = i + 10;
    int up_step = i - 10;
		int right = i + 1;
		int left = i - 1;

		if(up_step  >= 0 ){
			if( up_step  == 74 || up_step  == 73 || up_step  == 72 || up_step  == 71){
				continue;
				}
			if( up_step  == 64 || up_step  == 54 || up_step  == 44){
				continue;
				}
      if( up_step  == 34 || up_step  == 24 || up_step  == 14 || up_step == 4){
        continue;
       }
			if( up_step  == 35 || up_step  == 36 || up_step  == 37 || up_step  == 38){
				continue;
				}
			addEdge(G, i, up_step,1);
			}

		if(down_step < 100){
			if( down_step == 91 || down_step == 92 || down_step == 93 || down_step == 94){
				continue;
				}
			if( down_step == 14 || down_step == 24 || down_step == 34 || down_step == 44){
				continue;
				}
      if( down_step == 54 || down_step == 64 || down_step == 74 || down_step == 84 || down_step == 94){
        continue;
        }
			addEdge(G, i, down_step ,1);
			}

		if(right  / 10 == i / 10){
			if( right  == 44 || right == 45 ||  right == 46 || right == 47 || right == 48 || right == 49){
				continue;
				}
			addEdge(G, i, right,1);
			}

		if((left / 10 == i / 10) && i > 0){
			addEdge(G, i, left,1);
			}

	}

	printGraph(G);

	bfs(G,0,5);
	//print_path(G, 0, 5);
	printf("\n");
  return 0;
}

/*
}
Graphptr g = createGraph(10,Undirected);
  /*addEdge(g, 11, 21, 1);
	addEdge(g, 1, 2, 1);
	addEdge(g, 2, 3, 1);

	addEdge(g, 3, 0, 1);
	addEdge(g, 2, 4, 1);
	addEdge(g, 4, 5, 1);

	addEdge(g, 7, 0, 1);
	addEdge(g, 5, 6, 1);
	addEdge(g, 6, 7, 1);

for(int i=(0,0); i<(0,5);i++) {
  addEdge(g,i,i,1);
}
	printGraph(g);
	bfs(g,0 );
//  printf("\n\n%d\t%d\t%d\t%d\n", g->adjLists[4].distans,g->adjLists[4].pi, g->adjLists[2].distans, g->adjLists[2].pi);

}
*/
