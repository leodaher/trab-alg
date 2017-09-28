#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"

struct m_graph {
    int dir; // direcionado ou nao
    int n;  // tamanho (num de vertices)
    int** matrix;
};

M_GRAPH* m_graph_create(int n, int dir) {
    M_GRAPH* g = (M_GRAPH*) malloc(sizeof(M_GRAPH));
    int i, j;
    
    g->n = n;
    g->dir = dir;
    g->matrix = (int **) malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
        g->matrix[i] = (int *) malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g->matrix[i][j] = -1; // matrix vazia
    
    return g;
}

void m_graph_insert(M_GRAPH* g, int row, int col, int w) {
    g->matrix[row][col] = w;
    if (!g->dir) g->matrix[col][row] = w;
}

int m_graph_checkedge(M_GRAPH* g, int row, int col) {
    if (g->matrix[row][col] < 0) return 0;
    return 1; // aresta existe no grafo
}

void m_graph_adj(M_GRAPH* g, int v) {
    int i;
    
    for (i = 0; i < g->n; i++) {
        if (g->matrix[v][i] >= 0)
            printf("%d ", i); // vertices adjacentes
    }
    printf("\n");
}

void m_graph_remove(M_GRAPH* g, int row, int col) {
    g->matrix[row][col] = -1;
    if (!g->dir) g->matrix[col][row] = -1;
}

int m_graph_nvertex(M_GRAPH* g) {
    return g->n;
}

void m_graph_print(M_GRAPH* g) {
    int i, j;
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            if (g->matrix[i][j] < 0) printf(". ");
            else printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

M_GRAPH* m_graph_transpose(M_GRAPH* g) {
    M_GRAPH* t = m_graph_create(g->n,g->dir);
    int i, j;
    
    for (i = 0; i < t->n; i++)
        for (j = 0; j < t->n; j++)
            t->matrix[j][i] = g->matrix[i][j]; // transposicao
    
    return t;
}

void m_graph_printtranspose(M_GRAPH* g) {
    M_GRAPH* t = m_graph_create(g->n,g->dir);
    int i, j;
    
    for (i = 0; i < t->n; i++)
        for (j = 0; j < t->n; j++)
            t->matrix[j][i] = g->matrix[i][j]; // transposicao
    
    m_graph_print(t);
    m_graph_free(t);
}

void m_graph_printloweredge(M_GRAPH* g) {
    int i, j, row, col, lower = MAX;
    
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            if (g->matrix[i][j] < lower && g->matrix[i][j] >= 0) {
                lower = g->matrix[i][j];
                row = i; col = j;
            }
        }
    }
    
    if (!g->dir) { // printa a aresta com menor peso corretamente
        if (row <= col) {
            printf("%d %d\n", row, col);
        } else printf("%d %d\n", col, row);
    } else printf("%d %d\n", row, col);
}

void m_graph_free(M_GRAPH* g) {
    int i;
    for (i = 0; i < g->n; i++) free(g->matrix[i]);
    free(g->matrix);
    free(g);
}
