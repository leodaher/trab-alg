#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"

/*
  	@desc - função que retorna o vértice resultado para o crtério 1
  	@param M_GRAPH * g - grafo
	@param int * E - vetor de pesos
  	@return int - vértice para o critério 1
*/
int criterio1(M_GRAPH * graph, int * E) {

  int result = center_vertex(floyd_warshall(graph, E), m_graph_nvertex(graph));
  return result;
}

/*
  	@desc - função que retorna o vértice resultado para o crtério 2
  	@param M_GRAPH * g - grafo
  	@return int - vértice para o critério 2
*/
int criterio2(M_GRAPH * graph) {
  int i, maior, imaior;
  int n = m_graph_nvertex(graph);
  float ** matrix = floyd_warshall(graph, NULL);

  maior = 0;
  imaior = 0;

  for(i = 0; i < n; i++) {
    int bc = betweenness_centrality(matrix, n, i);
    if(bc > maior) {
      maior = bc;
      imaior = i;
    }
  }

  return imaior;
}


M_GRAPH * receiveData(int ** E) {
  int N, M, i;
  M_GRAPH * graph;

  // recebe número de vértices e arestas
  scanf("%d %d", &N, &M);

  //recebe número de egressos por cidade
  *E = (int*) malloc(sizeof(int)*N);
  for(i = 0; i < N; i++) {
    scanf("%d", &((*E)[i]));
  }

  // inicializa o grafo
  graph = m_graph_create(N, 0);

  // recebe as distâncias entre cidades e insere no grafo
  for(i = 0; i < M; i++) {
    int id1, id2;
    float d;

    scanf("%d %d %f", &id1, &id2, &d);

    // insere o produto entre a distância e o número de egressos da cidade de origem como peso
    m_graph_insert(graph, id1, id2, d);
  }

  return graph;
}

int main() {
  M_GRAPH * graph;
  int * E;

  graph = receiveData(&E);

  int crit2 = criterio2(graph);
  int crit1 = criterio1(graph, E);
  printf("\nCritério 1: %d", crit1);
  printf("\nCritério 2: %d\n", crit2);

  return 0;
}
