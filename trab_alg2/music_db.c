#include <stdio.h>
#include <stdlib.h>
#include "music_db.h"
#include "reg.h"

void inserir_musica(FILE * data, FILE * index) {
  tRegistro reg;

  printf("ID da música:");
  scanf("%d%*c", &(reg.id));
  printf("%05d", reg.id);

  printf("Título da música:");
  scanf("%[^\n]%*c", reg.titulo);

  printf("Gênero da música:");
  scanf("%[^\n]%*c", reg.genero);

  insert_reg(data, &reg);
}

void remover_musica(FILE * data, FILE * index) {
  printf("Remover música\n");
}

void pesquisar_musica(FILE * data, FILE * index) {
  printf("Pesquisar música\n");
}
