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

char ** beolvaso(char* sz, int* hosz) { // end of line jel : ~  EOF: !
	FILE *p;
	*hosz = 0;
	char a;
	char **m;
	int sorszam = 0;
	int sorhosz = 0;
	int i = 0;
	int k = 0;
	int hely = 0;

	p = fopen(sz, "r");

	do {
		a = fgetc(p);
		if (a == '~') {
			sorhosz = i;
			sorszam++;
			i = 0;
		}
		i++;
	} while (a != '!');
	fclose(p);

	m = (char **) malloc(sorszam * sizeof(char*));

	p = fopen(sz, "r");
	char str[sorhosz + 2];
	for (k = 0; k <= sorszam + 1; k++) {// a sorok memoria alokacioja es azokba a szoveg bele irasa

		m[k] = (char*) malloc(sorhosz * sizeof(char));

		if (fgets(str, sorhosz, p) != NULL) {

			strcpy(m[hely], str);
			hely++;
		}

	}

	fclose(p);

	*hosz = sorszam;
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
	for (i = 0; i <= h; i++) {
		printf("%s", c[i]);
	}
	printf("\n \n \n");
}

