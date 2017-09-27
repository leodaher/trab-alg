#include <stdio.h>
#include <stdlib.h>
#include "lgraph.h"

struct node {
    int adj;
    int weight;
    NODE *next;
};

struct l_graph {
    int dir;
    int n;
    NODE** list;
};

L_GRAPH* l_graph_create(int n, int dir) {
    L_GRAPH* g = (L_GRAPH*) malloc(sizeof(L_GRAPH));
    int i;
    
    g->n = n;
    g->dir = dir;
    g->list = (NODE**) malloc(sizeof(NODE*) * n);
    for (i = 0; i < n; i++) {
        g->list[i] = (NODE*) malloc(sizeof(NODE));
        g->list[i]->adj = -1;
        g->list[i]->weight = -1;
        g->list[i]->next = NULL;
    }
    
    return g;
}

void l_graph_insert_help(L_GRAPH* g, int orig, int dest, int w) {
    NODE *aux = g->list[orig];
    NODE *auxb = g->list[orig]->next;
    
    while (auxb != NULL && auxb->adj < dest) { // percorre a lista
        aux = auxb;
        auxb = auxb->next;
    }
    
    
    if (auxb == NULL) { // lista vazia
        aux->next = (NODE*) malloc(sizeof(NODE));
        aux->next->adj = dest;
        aux->next->weight = w;
        aux->next->next = NULL;
    }
    
    else if (auxb->adj == dest) { // novo peso atribuido
        auxb->weight = w;
    }
    
    else {
        aux->next = (NODE*) malloc(sizeof(NODE));
        aux->next->adj = dest;
        aux->next->weight = w;
        aux->next->next = auxb;
    }
}

void l_graph_insert(L_GRAPH* g, int orig, int dest, int w) {
    l_graph_insert_help(g,orig,dest,w);
    if (!g->dir) l_graph_insert_help(g,dest,orig,w);
}

void l_graph_remove_help(L_GRAPH* g, int orig, int dest) {
    NODE *aux = g->list[orig];
    NODE *auxb = g->list[orig]->next;
    
    while (auxb != NULL && auxb->adj != dest) { // percorre ate achar
        aux = auxb;
        auxb = auxb->next;
    }
    
    if (auxb != NULL) {
        aux->next = auxb->next;
        auxb->next = NULL;
        free(auxb);
    }
}


void l_graph_remove(L_GRAPH* g, int orig, int dest) {
    l_graph_remove_help(g,orig,dest);
    if (!g->dir) l_graph_remove_help(g,dest,orig);
}


void l_graph_free(L_GRAPH* g) {
    NODE *aux;
    int i;
    
    for (i = 0; i < g->n; i++) { // remove as arestas antes
        aux = g->list[i]->next;
        while (aux != NULL) {
            l_graph_remove_help(g,i,aux->adj);
            aux = g->list[i]->next;
        }
    }
    
    for (i = 0; i < g->n; i++) free(g->list[i]);
    free(g->list);
    free(g);
}

void l_graph_print(L_GRAPH* g) {
    NODE* aux;
    int i;
    
    for (i = 0; i < g->n; i++) {
        aux = g->list[i]->next;
        printf("%d. ", i);
        while (aux != NULL) {
            printf("%d(%d) ", aux->adj, aux->weight);
            aux = aux->next;
        }
        printf("\n");
    }
}

void l_graph_adj(L_GRAPH* g, int v) {
    NODE* aux = g->list[v]->next; // adjacentes ao vertice v
    
    while (aux != NULL) {
        printf("%d ", aux->adj);
        aux = aux->next;
    } printf("\n");
}

void l_graph_printloweredge(L_GRAPH *g) {
    NODE *aux;
    int i, lower = MAX, row, col;
    
    for (i = 0; i < g->n; i++) {
        aux = g->list[i]->next;
        while (aux != NULL) {
            if (aux->weight < lower) { // acha a aresta com menor peso
                lower = aux->weight;
                row = i;
                col = aux->adj;
            }
            aux = aux->next;
        }
    }
    
    if (!g->dir) { // printa a aresta com menor peso corretamente
        if (row <= col) {
            printf("%d %d\n", row, col);
        } else printf("%d %d\n", col, row);
    } else printf("%d %d\n", row, col);
}
