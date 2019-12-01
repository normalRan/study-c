#ifndef GRAPH_H_
#define GRAPH_H_
#define MaxVertexNum 10

typedef int WeightType;

/* Graph */
typedef struct Gnode *PtrToGnode;
struct Gnode {
	int Nv;		/* number of Vertex */
	int Ne;   	/* number of Edge */
	WeightType G[MaxVertexNum][MaxVertexNum];    
 	/* 0 stand for unconnected */
//	DateType dat[MaxVertexNum];  /* story information about Vertex */
};
typedef PtrToGnode MGraph; /* define Graph */

/* Vertex */
typedef int Vertex; 

/* Edge */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex v1;
	Vertex v2;
	WeightType Wight;
};
typedef PtrToENode Edge;

Edge CreatEdge(Vertex v1, Vertex v2, WeightType wight);

/* interface */

/* operation: IntializeGraph */
/* preconditon : G -> Graph */
/* pre condition : crate Graph */
MGraph CreatGraph(int VertexNum);

 
/* operation : assignment */
/* preconditon : Graph has been Intialized */
void BuildGraph(MGraph Graph); 


/* operation: InserVertex for Graph */
/* preconditon : prepare a Vertex and Graph have been Intialized */
void InserVertex(MGraph Graph, Vertex v);


/* operation: InserEdge for Graph */
/* preconditon : prepare an Edge and Graph have benn Intialized */
void InserEdge(MGraph Graph, Edge e);


/* operation: Depth Frist Search */
/* preconditon : G -> Graph */
void DFS(MGraph Graph, Vertex v, int Visited[]);


/* operation: Breadth Frist Search */
/* preconditon : G -> Graph */
void BFS(MGraph Graph, Vertex v);


/* operation: give out the shortest path */
/* preconditon : G -> Graph */
void ShortestPath(MGraph Graph, Vertex v, int Dist[]);














#endif
