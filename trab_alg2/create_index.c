void create_index (FILE* fdata, bTree *bt) {
	registro_t reg;
	char tamStr[4];
	int i = 0;
	char c = fgetc(fdata);

	if (c == EOF){
		printf("Termino da leitura\n");
		return;
	}

	while (c != '|'){
		tamStr[i] = c;
		i++;
		c = fgetc(fdata);
	}
	int tam = atoi(tamStr);

	char *str = malloc(tam*sizeof(char));
	fgets(str, tam, fdata);

	char s[] = "|";
	reg.id = atoi(strtok(str, s));
	strcpy(reg.titulo, strtok(NULL, s));
	strcpy(reg.genero, strtok(NULL, s));


	printf("\n    tam = %d\n", tam);
	printf("    id = %d\n    titulo = %s\n    genero = %s\n\n", reg.id, reg.titulo, reg.genero);
	c = fgetc(fdata);

	create_index(fdata, bt);
}
