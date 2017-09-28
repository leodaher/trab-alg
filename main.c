#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"

int criterio1(M_GRAPH * graph, int * E) {
  int result = 0;

  return result;
}

int criterio2(M_GRAPH * graph) {
  int result = 0;

  return result;
}

void receiveData(M_GRAPH * graph, int * E) {
  int N, M, i;

  // recebe número de vértices e arestas
  scanf("%d %d", &N, &M);

  //recebe número de egressos por cidade
  E = (int*) malloc(sizeof(int)*N);
  for(i = 0; i < N; i++) {
    scanf("%d", &(E[i]));
  }

  // inicializa o grafo
  graph = m_graph_create(N, 1);

  // recebe as distâncias entre cidades e insere no grafo
  for(i = 0; i < M; i++) {
    int id1, id2;
    float d;

    scanf("%d %d %f", &id1, &id2, &d);

    // insere o produto entre a distância e o número de egressos da cidade de origem como peso
    m_graph_insert(graph, id1, id2, d);
  }
}

int main() {
  M_GRAPH * graph;
  int * E;

  receiveData(graph, E);
}
