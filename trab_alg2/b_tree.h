#ifndef B_TREE_H
#define B_TREE_H

typedef struct {
  int id;
  long offset;
} tChave;

typedef struct {
  int contador;
  tChave * chaves;
  int * filhos;
  bool folha;
} pagina;

int get_root(FILE * index);
void inserir_chave(FILE * index, tChave * chave);

#endif
