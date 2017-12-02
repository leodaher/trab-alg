#include <stdio.h>
#include <stdlib.h>
#include "music_db.h"
#include "b_tree.h"

void menu(FILE * data, FILE * index) {
  printf("Escolha a operação a ser realizada:\n\n");
  printf("1. Criar índice\n");
  printf("2. Inserir música\n");
  printf("3. Pesquisar música por ID\n");
  printf("4. Remover música por ID\n");
  printf("5. Mostrar Árvore-B\n");
  printf("6. Fechar o programa\n\n");


  int op;

  do {
    printf("Insira a opção desejada:");
    scanf("%d%*c", &op);

    switch(op) {
      case 1:
        printf("Caso 1\n");
        break;
      case 2:
        inserir_musica(data, index);
        break;
      case 3:
        pesquisar_musica(data, index);
        break;
      case 4:
        remover_musica(data, index);
        break;
      case 5:
        printf("Print B-Tree\n");
        break;
      case 6:
        break;
      default:
        printf("Valor inválido de operação");
        break;
    }
  } while(op != 6);
}

int main() {

  FILE * data = fopen("dados.dat", "a+");
  FILE * index = fopen("arvore.idx", "a+");

  menu(data, index);

  return 0;
}
