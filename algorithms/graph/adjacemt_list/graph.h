#ifndef GRAPH_H_
#define GRAPH_H_
#define MaxVertexNum 10

typedef int WeightType;
typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;
typedef struct VNode *PtrToVNode;
typedef PtrToVNode Vertex;

struct VNode {
	int vertex;
	Edge next;
};

struct ENode {
	WeightType weight;	
	Vertex front; 
	Vertex rear;
};

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	Vertex G[MaxVertexNum];
};
typedef PtrToGNode MGraph;

/* interface func */

/* operation : Creat graph										 */
/* preconditon : have a pointer of graph						 */
/* post condition : return a graph								 */
MGraph CreatGraph(int VertexNum);


/* operation : creat vertex										 */
/* preconditon : have a pointer of vertex						 */
/* post condition : return a vertex								 */
Vertex CreatVertex(int v);


/* operation : creat edge										 */
/* preconditon : have a pointer of edge							 */
/* post condition : return an edge								 */
Edge CreatEdge(int v);


/* operation : Insert Vertex									 */
/* preconditon : graph has been created as well as vertex        */
/* post condition : finsh insert                                 */
void InsertVertex(MGraph Graph);


/* operation : Insert Edge                                       */
/* preconditon : graph has been created as well as edge          */
/* post condition : finsh insert                                 */
void InsertEdge(MGraph Graph, WeightType weight, int v1, int v2);


/* operation : Depth first search                                 */
/* preconditon : graph has been created as well as vertex         */
/* post condition : finsh search                                  */
void DFS(MGraph Graph, Vertex v, int Visited[]);


/* operation : Breadth first search                               */
/* preconditon : graph has been created as well as vertex         */
/* post condition : fill the array with the distance              */
void BFS(MGraph Graph, Vertex v);


#endif
