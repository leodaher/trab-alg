#ifndef lgraph_h
#define lgraph_h

#define FALSE 0
#define TRUE 1
#define MAX 99

typedef struct l_graph L_GRAPH;
typedef struct node NODE;

L_GRAPH* l_graph_create(int, int);
void l_graph_insert(L_GRAPH*, int, int, float);
void l_graph_remove(L_GRAPH*, int, int);
void l_graph_free(L_GRAPH*);
void l_graph_print(L_GRAPH*);
void l_graph_adj(L_GRAPH*, int);
void l_graph_printloweredge(L_GRAPH *);

#endif /* lgraph_h */
