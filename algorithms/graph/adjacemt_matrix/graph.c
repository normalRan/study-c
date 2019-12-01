#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct Qnode *PtrToQnode;
struct Qnode {
	Vertex v[MaxVertexNum];	
	int size;	
};
typedef PtrToQnode Queue;

static Queue CreatQueue(void);
static int QueueIsEmpty(Queue Q);
static void Enqueue(Queue Q, Vertex v);
static Vertex Dequeue(Queue Q);

/* interface fanc */

MGraph CreatGraph(int VertexNum) {
	Vertex v, w;
	MGraph Graph = (MGraph)malloc(sizeof(struct Gnode));	
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (v=0; v<VertexNum; v++) 
		for (w=0; w<VertexNum; w++)
			Graph->G[v][w] = 0;
	return Graph;
}

Edge CreatEdge(Vertex v1, Vertex v2, WeightType wight) {
	Edge e = (Edge)malloc(sizeof(struct ENode));
	e->v1 = v1;
	e->v2 = v2;
	e->Wight = wight;
}

void BuildGraph(MGraph Graph) {
	Edge e;	
	for (e->v1=0; e->v1<Graph->Nv-1; e->v1++)
		for (e->v2=e->v1+1; e->v2<Graph->Nv; e->v2++) {
			scanf("%d", &e->Wight);		
			InserEdge(Graph, e);
		}
}

void InserVertex(MGraph Graph, Vertex v) {
	if (Graph->Nv == MaxVertexNum)	
		/* error : Graph is already full */
		return;
	Vertex w;
	Graph->Nv++;
	for (w=0; w<Graph->Nv; w++)	
		Graph->G[Graph->Nv][w] = 0;
	for (w=0; w<Graph->Nv; w++)	
		Graph->G[w][Graph->Nv] = 0;
}

void InserEdge(MGraph Graph, Edge e) {
	Graph->G[e->v1][e->v2] = e->Wight;
	Graph->G[e->v2][e->v1] = e->Wight;
	Graph->Ne++;
}

void DFS(MGraph Graph, Vertex v, int Visited[]) {
	if (Visited[v]) return;	
	Visited[v] = 1;
	Vertex w;
	for (w=0; w<Graph->Nv; w++) {
		if (!Visited[w])	
		 	Visited[w] = 1;
			DFS(Graph, w, Visited);
	}
}

void BFS(MGraph Graph, Vertex v) {
	int Visited[Graph->Nv];
	int i;
	for (i=0; i<Graph->Nv; i++)
		Visited[i] = 0;
	Visited[v] = 1;
	Queue Q = CreatQueue();
	Enqueue(Q, v);
	while(!QueueIsEmpty(Q)) {
		Vertex w = Dequeue(Q);			
		Vertex q;
		for (q=0; q<Graph->Nv; q++) {
			if (!Visited[q] && Graph->G[w][q]) {
				Visited[q] = 1;
				Enqueue(Q,q);
			}
		}
	}
}

void ShortestPath(MGraph Graph, Vertex v, int Dist[]) {
	int Visited[Graph->Nv];
	int i;
	for (i=0; i<Graph->Nv; i++)
		Visited[i] = 0;
	Visited[v] = 1;
	Queue Q = CreatQueue();
	Enqueue(Q, v);
	int cnt = 1;
	while(!QueueIsEmpty(Q)) {
		Vertex w = Dequeue(Q);			
		Vertex q;
		for (q=0; q<Graph->Nv; q++) {
			if (!Visited[q] && Graph->G[w][q]) {
				Visited[q] = 1;
				Enqueue(Q,q);
				Dist[q] = cnt;
			}
		}
		cnt++;
	}
	free(Q);
}


/* static fanc */

static Queue CreatQueue(void) {
	Queue q = (Queue)malloc(sizeof(struct Qnode));
	int i;
	for (i=0; i<MaxVertexNum; i++) 
		q->v[i] = -1;
	q->size = 0;
	return q;
}

static int QueueIsEmpty(Queue Q) {
 	return Q->size == 0;
}

static void Enqueue(Queue Q, Vertex v) {
	Q->v[Q->size++] = v;
}

static Vertex Dequeue(Queue Q) {
	if (!QueueIsEmpty(Q))
	return Q->v[--Q->size];
}


