#include <stdio.h>
#include <stdlib.h>



typedef enum {Undirected = 0, Directed} Edgeptr;

typedef struct node  //adjListNode
{
    int vertex;
    int edgeweight;
    struct node* next;
}Node;

typedef Node *Nodeptr;

typedef struct adjList
{
  int distans;
  int pi;
  struct node *head;
}Adjlist;

typedef Adjlist *Adjlistptr;


typedef struct graph //graph
{
    int totalVertices;
    int totalEdges;
    Edgeptr TypeOfGraph;
    struct adjList *adjLists;
    int cycle;
}Graph;
typedef Graph *Graphptr;






Nodeptr createNode(int v, int weight);
Graphptr createGraph(int vertices, Edgeptr typeofgraph);
void addEdge(Graphptr graph, unsigned int src, unsigned int dest, int weight);
int hasEdge(Graphptr graph, unsigned int src, unsigned int dest);
void addNodeToList(Adjlistptr list, Nodeptr node);
Nodeptr add_neighbors(Nodeptr y, int v);
void printGraph(Graphptr graph);
int getNumVertices(Graphptr G);
int getNumEdges(Graphptr G);




Nodeptr createNode(int v, int weight)
{
    Nodeptr newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    newNode->edgeweight=weight;
    return newNode;
}


Graphptr createGraph(int vertices, Edgeptr typeofgraph)
{
    int i;

    Graphptr graph = malloc(sizeof(Graph));
    graph->totalVertices = vertices;
    graph->totalEdges=0;
    graph->TypeOfGraph=typeofgraph;

    graph->adjLists = malloc( sizeof(Node) *vertices);

    graph->totalVertices=vertices;
    for (i = 0; i < vertices; i++){
        graph->adjLists[i].head= NULL;
      //  graph->adjLists[i].totalMembers= 0;
      }
    return graph;
}


void addNodeToList(Adjlistptr list, Nodeptr node) {
	node->next = list->head;
	list->head = node;
//	list->totalMembers++;
}



int getNumVertices(Graphptr G){
  return G->totalVertices;
}



int hasEdge(Graphptr graph, unsigned int src, unsigned int dest) {
	Nodeptr srcVertexPtr = graph->adjLists[src].head;

	while(srcVertexPtr != NULL) {
		if(srcVertexPtr->vertex == dest)
			return 1;
		srcVertexPtr = srcVertexPtr->next;
	}

	return 0;
}

void addEdge(Graphptr graph, unsigned int src, unsigned int dest, int weight) {
	if(src >= graph->totalVertices || dest >= graph->totalVertices)
		return;

	if(hasEdge(graph, src, dest))
		return;

	Nodeptr newNode = createNode(dest, weight);

	addNodeToList(&(graph->adjLists[src]), newNode);
	graph->totalEdges++;

	if(graph->TypeOfGraph == Undirected) {
		newNode = createNode(src, weight);

		addNodeToList(&(graph->adjLists[dest]), newNode);
		graph->totalEdges++;
	}
}

int getNumEdges(Graphptr G){
  return G->totalEdges;
}


Nodeptr add_neighbors(Nodeptr y, int v)
{
  int weight;
	Nodeptr x = createNode(v,1);
	x->next = y;
	y = x;
return y;
}

Nodeptr getinneighbors(Graphptr G, int v)
{
  Nodeptr temp = NULL;
  Nodeptr y = NULL;// =malloc(sizeof(Node));

	for( int i= 0; i < G->totalVertices; i++){
	//	if(i != v){
			temp = G->adjLists[i].head;
			while(temp != NULL){
				if(temp->vertex == v){
				 y=add_neighbors(y,i);
					break;
					}
				temp = temp->next;
			}
	//	}
	}
return y;

}


Nodeptr getoutneighbors(Graphptr G, int v)
{

	Nodeptr y = malloc(sizeof(Node));

	for( int i= 0; i < G->totalVertices; i++){
		if(i == v){
			Nodeptr temp = G->adjLists[i].head;
			while(temp->next != NULL){
					y = add_neighbors(y,i);
				temp = temp->next;
			}
		}
	}

	return y;

}
void printGraph(Graphptr graph)
{
    int i;
    for (i = 0; i < graph->totalVertices; i++)
    {
        printf("\n Adjacency list of vertex %d\n ", i);
        Nodeptr temp = graph->adjLists[i].head;
        while (temp !=NULL)
        {
            printf("->%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

}
