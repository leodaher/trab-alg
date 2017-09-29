#ifndef mgraph_h
#define mgraph_h

#define FALSE 0
#define TRUE 1
#define MAX 99

typedef struct m_graph M_GRAPH;

// Funções da estrutura do grafo
M_GRAPH* m_graph_create(int, int);
void m_graph_free(M_GRAPH*);
void m_graph_insert(M_GRAPH*, int, int, float);
int m_graph_nvertex(M_GRAPH*);

// Algoritmos utilizados
float ** floyd_warshall(M_GRAPH*, int * E);
int center_vertex(float**, int);
float * sum_rows(M_GRAPH*, float**);

#endif /* mgraph_h */
