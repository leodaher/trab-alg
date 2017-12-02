#ifndef MUSIC_DB_H
#define MUSIC_DB_H

typedef struct {
  int id;
  char titulo[30];
  char genero[20];
} tRegistro;

void inserir_musica(FILE * data, FILE * index);
void remover_musica(FILE * data, FILE * index);
void pesquisar_musica(FILE * data, FILE * index);

#endif
