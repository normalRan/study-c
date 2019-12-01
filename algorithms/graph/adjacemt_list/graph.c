#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct QNode *PtrToQNode;
struct QNode {
	int size;	
	Vertex v[MaxVertexNum];
};
typedef PtrToQNode Queue;

static Queue CreatQueue(void);
static void Enqueue(Queue q, Vertex v); 
static Vertex Dequeue(Queue q);
static int QueueIsEmpty(Queue q);

/* implementation */

MGraph CreatGraph(int VertexNum) {
	MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	int i;
	for (i=0; i<VertexNum; i++) 
		Graph->G[i] = CreatVertex(i);		
	return Graph;
}

Vertex CreatVertex(int v) {
	Vertex w = (Vertex)malloc(sizeof(struct VNode));
	w->vertex = v;	
	w->next = NULL;
	return w;
}

Edge CreatEdge(WeightType wight) {
	Edge e = (Edge)malloc(sizeof(struct ENode));
	e->front = NULL;
	e->rear  = NULL;
	e->weight = wight;
	return e;
}

void InsertVertex(MGraph Graph) {
	Graph->G[Graph->Nv++] = CreatVertex(Graph->Nv-1);
} 

void InsertEdge(MGraph Graph, WeightType weight, int v1, int v2) {

	Vertex v = Graph->G[v1];
	Vertex w = Graph->G[v2];
	Edge e1 = CreatEdge(weight);
	e1->rear = CreatVertex(v2); 
	Edge e2 = CreatEdge(weight);
	e2->rear = CreatVertex(v1);
	Graph->Ne += 2;	
	
	if (!v->next) {			
		v->next = e1;
		e1->front = v;
	}
	else {
		e1->rear->next = v->next;
		v->next->front = e1->rear;	
		v->next = e1;
		e1->front = v;
	}
	if (!w->next) {
		w->next = e2;
		e2->front = w;
	}
	else {
		e2->rear->next = v->next;
		w->next->front = e2->rear;
		w->next = e2;
		e2->front = w;
	}		
}


void DFS(MGraph Graph, Vertex v, int Visited[]) {
	Visited[v->vertex] = 1;
	if (!v->next) return;
	Vertex w = Graph->G[v->vertex];
	while (w->next) {
		w = w->next->rear;	
		if (!Visited[w->vertex]) 
			DFS(Graph, w, Visited);
	}
}


void BFS(MGraph Graph, Vertex v) {
	int Visited[Graph->Nv];	
	int i;
	for (i=0; i<Graph->Nv; i++)
		Visited[i] = 0;
	Visited[v->vertex] = 1;
	Queue q = CreatQueue();
	Enqueue(q, v);
	while (!QueueIsEmpty(q)) {
		Vertex w = Dequeue(q);
		while (1) {
			if (!Visited[w->vertex]) {
				Visited[w->vertex] = 1;
				Enqueue(q, Graph->G[w->vertex]);
			}
			if (w->next == NULL) 
				break;
			else
				w = w->next->rear;
		}	
	}
	for (i=0; i<Graph->Nv; i++)
		printf("%3d", Visited[i]);
	free(q);
}

/* static fanc */


static Queue CreatQueue(void) {
	Queue q = (Queue)malloc(sizeof(struct QNode));
	q->size = 0;
	int i;
	for (i=0; i<MaxVertexNum; i++)	
		q->v[i] = NULL;
	return q;
}

static void Enqueue(Queue q, Vertex v) {
	q->v[q->size++] = v;
}

static Vertex Dequeue(Queue q) {
	if (QueueIsEmpty(q))
		return NULL;
	else
		return q->v[--q->size];
}

static int QueueIsEmpty(Queue q) {
	if (q->size == 0)
		return 1;
	else
		return 0;
}

