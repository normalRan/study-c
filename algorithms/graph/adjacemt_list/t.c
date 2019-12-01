#include <stdio.h>
#include <stdlib.h> 
#include "graph.h"

int main(void) {
	MGraph Graph = CreatGraph(6);	
	int i;
/*	for (i=0; i<Graph->Nv; i++) 
		printf("%d\n", Graph->G[i]->vertex); */
	InsertEdge(Graph, 1, 1, 3);	
	InsertEdge(Graph, 1, 1, 0);	
	InsertEdge(Graph, 1, 1, 4);	
	InsertEdge(Graph, 1, 3, 2);
	InsertEdge(Graph, 1, 4, 5);
	
/*	Vertex temp = Graph->G[1];
	while (1) {
		printf("%3d", temp->vertex);	
		if (!temp->next)	
			break;
		else
			temp = temp->next->rear;
	} */  

/*************************************************************
	puts("a[1]");
	printf("rear  : %d\n", Graph->G[1]->next->rear->vertex);
	printf("front : %d\n", Graph->G[1]->next->front->vertex);
	puts("a[3]");
	printf("rear  : %d\n", Graph->G[3]->next->rear->vertex);
	printf("front : %d\n", Graph->G[3]->next->front->vertex);
***************************************************************/

	int Dist[Graph->Nv];
	for (i=0; i<Graph->Nv; i++) 		
		Dist[i] = 0;
	BFS(Graph, Graph->G[1]);

	printf("\n");
	return 0;
}
											/*
											 **   2019.12.1
										    	*/

										
