#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

int main(void) {
	MGraph Graph = CreatGraph(4);	
	InserEdge(Graph, CreatEdge(0,1,1));
	InserEdge(Graph, CreatEdge(0,3,1));
	InserEdge(Graph, CreatEdge(1,2,1));
	InserEdge(Graph, CreatEdge(2,3,1));
/*	for (int v=0; v<6; v++) 
		for (int w=0; w<6; w++)
			printf("%d %d %d\n", v, w, Graph->G[v][w]);
			*/
	InserVertex(Graph, 3);
	int Dist[Graph->Nv];
	int i, k;
	for (i=0; i<Graph->Nv; i++)
		Dist[i] = 0;	 
	ShortestPath(Graph, 2, Dist);			
	for  (i=0; i<Graph->Nv; i++) {
		for (k=0; k<Graph->Nv; k++)	
			printf("%2d", Graph->G[i][k]);	
		printf("\n");
	}

	for (i=0; i<Graph->Nv; i++)
		printf("%d\t", Dist[i]);
	printf("\n");

	return 0;
}

/*  
 * 0 1 0 1
 * 1 0 1 0
 * 0 1 0 1
 * 1 0 1 0
 */

										/*
										 **   2019.11.29 22:46
										*/


