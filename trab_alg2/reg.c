#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "music_db.h"

void insert_reg(FILE * data, tRegistro * reg) {
  int length = 5+strlen(reg->titulo)+strlen(reg->genero)+4;
  fprintf(data, "%05d|%05d|%s|%s|", length, reg->id, reg->titulo, reg->genero);
}
