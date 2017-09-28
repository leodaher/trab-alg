#include <stdio.h>
#include <stdlib.h>
#include "lgraph.h"

LGRAPH * receiveData() {
  int N, M, i;
  int * E;
  LGRAPH * graph;

  // recebe número de vértices e arestas
  scanf("%d %d", &N, &M);

  //recebe número de egressos por cidade
  E = (int*) malloc(sizeof(int)*N);
  for(i = 0; i < N; i++) {
    scanf("%d", &(E[i]));
  }

  // inicializa o grafo
  graph = l_graph_create(N, 1);

  // recebe as distâncias entre cidades e insere no grafo
  for(i = 0; i < M; i++) {
    int id1, id2;
    int d;

    scanf("%d %d %f", &id1, &id2, &d);

    l_graph_insert(graph, id1, id2, d);
  }

  return graph;
}

int main() {
  LGRAPH * graph = receiveData();
}
