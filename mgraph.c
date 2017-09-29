#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"

struct m_graph {
    int dir; // direcionado ou nao
    int n;  // tamanho (num de vertices)
    float** matrix;
};

/*
  @desc - cria grafo utilizando o tamanho e sabendo se é direcionado ou não
  @param int n - tamanho do grafo (número de vértices)
  @param int dir - direcionado ou não
  @return M_GRAPH * - grafo
*/
M_GRAPH* m_graph_create(int n, int dir) {
    M_GRAPH* g = (M_GRAPH*) malloc(sizeof(M_GRAPH));
    int i, j;

    g->n = n;
    g->dir = dir;
    g->matrix = (float **) malloc(sizeof(float *) * n);
    for (i = 0; i < n; i++)
        g->matrix[i] = (float *) malloc(sizeof(float) * n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if(i == j)
              g->matrix[i][j] = 0;
            else
              g->matrix[i][j] = -1; // matrix vazia

    return g;
}

/*
  @desc - insere aresta com peso w entre dois nós
  @param M_GRAPH* g - grafo
  @param int row - nó de origem
  @param int col - nó de destino
  @param float w - peso da aresta
*/
void m_graph_insert(M_GRAPH* g, int row, int col, float w) {
    g->matrix[row][col] = w;
    if (!g->dir) g->matrix[col][row] = w;
}

/*
  @desc - retorna o número de vértices em um grafo
  @param M_GRAPH * g - grafo
  @return int - número de vértices
*/
int m_graph_nvertex(M_GRAPH* g) {
    return g->n;
}

void m_graph_free(M_GRAPH* g) {
    int i;
    for (i = 0; i < g->n; i++) free(g->matrix[i]);
    free(g->matrix);
    free(g);
}

/*
  @desc - aplica o algoritmo de Floyd Warshall no grafo e multiplica cada linha da matriz obtida por um peso
  @param M_GRAPH * g - grafo
  @param int * E - vetor de pesos
  @return float ** - matriz com menores caminhos ponderados
*/
float ** floyd_warshall (M_GRAPH* g, int * E){
    float ** M = g->matrix;
    int n = g->n;
    int i, j, k;
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if(M[i][k] != -1 && M[k][j] != -1) {
                  if (M[i][k] + M[k][j] < M[i][j] || M[i][j] == -1)
                      M[i][j] = M[i][k] + M[k][j];
                }
            }
        }
    }

    if(E != NULL) {
      for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
          M[i][j] *= E[i];
        }
      }
    }

    return M;
}

/*
  @desc - função que retorna o vértice mais central de um grafo a partir da matriz obtida pelo algoritmo de Floyd Warshall
  @param float ** M - matriz obtida pela função floyd_warshall()
  @param int n - tamanho do grafo
  @return int - vértice mais central
*/
int center_vertex (float **M, int n){
    int i, j;

    float *aux = malloc(sizeof(float));
    for (j = 0; j < n; j++){
        int soma = 0;
        for (i = 0; i < n; i++){
            if (M[i][j] == -1)
                soma = -1;
            else
                soma += M[i][j];
        }
        aux[j] = soma;
    }

    int menor = 0;
    for (i = 0; i < n; i++){
        if (aux[i] < aux[menor] || aux[menor] == -1)
            menor = i;

    }
    return menor;
}

/*
  @desc - função que retorna um vetor com a soma das linhas de cada coluna de uma matriz
  @param M_GRAPH * g - grafo
  @param float ** matrix - matriz
  @return float * - vetor da soma das linhas
*/
float * sum_rows(M_GRAPH * graph, float **matrix) {
    int i, j;
    float *aux = malloc(sizeof(float));
    for (j = 0; j < graph->n; j++) {
    float soma = 0;
    int div = 0;
        for (i = 0; i < graph->n; i++) {
            soma += matrix[i][j];
            if (matrix[i][j] > 0)
                div++;
        }
    aux[j] = soma/div;
  }
  return aux;
}
