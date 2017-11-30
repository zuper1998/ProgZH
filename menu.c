/*
 * menu.c
 *
 *  Created on: 27 Oct 2017
 *      Author: Narcano
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>
int mygetline(char **lineptr, size_t *n, FILE *stream){

*lineptr = malloc(sizeof(char)*500);
char* i = fgets(*lineptr, 500, stream);

*lineptr = realloc(*lineptr,sizeof(char)*(strlen(*lineptr)+1));

*n=strlen(*lineptr);



return (i == NULL)?-1:0;


}

char ** beolvaso(char* sz, int* hosz, int *szel) { // end of line jel : ~  EOF: !
	FILE *p;
	*hosz = 0;

	char** m;
	int sorhosz = 0;
	int i = 0;
	int k = 0;


	p = fopen(sz, "r");
	m = (char **) malloc(1 * sizeof(char*));

	while (i!=-1) {

		m = (char **) realloc(m,(k+1) * sizeof(char*));
		m[k]=NULL;
		i =mygetline(&m[k],&sorhosz,p);


		k++;

	}

	fclose(p);


	*szel = sorhosz;
	*hosz = k;
	return m;
}

void freee(char** a, int h) {
	int i;
	for (i = 0; i <= h; i++) {
		free(a[i]);
	}

	free(a);
}

void kiir(char** c, int h) {
	int i = 0;
	for (i = 0; i < h; i++) {
		printf("%s", c[i]);
	}
	printf("\n \n \n");
}





