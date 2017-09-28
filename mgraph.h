#ifndef mgraph_h
#define mgraph_h

#define FALSE 0
#define TRUE 1
#define MAX 99

typedef struct m_graph M_GRAPH;

M_GRAPH* m_graph_create(int, int);
void m_graph_free(M_GRAPH*);
void m_graph_print(M_GRAPH*);
void m_graph_multiply_edges(M_GRAPH*, int*);
void m_graph_insert(M_GRAPH*, int, int, float);
int m_graph_checkedge(M_GRAPH*, int, int);
float m_graph_getedge(M_GRAPH*, int, int);
void m_graph_setedge(M_GRAPH*, int, int, float);
void m_graph_adj(M_GRAPH*, int);
void m_graph_remove(M_GRAPH*, int, int);
int m_graph_nvertex(M_GRAPH*);
void m_graph_printtranspose(M_GRAPH*);
void m_graph_printloweredge(M_GRAPH*);
float ** floyd_warshall (M_GRAPH*, int * E);
int center_vertex (float**, int);
int criterio2(M_GRAPH*);

#endif /* mgraph_h */
