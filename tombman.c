/*
 * tombman.c
 *
 *  Created on: 7 Nov 2017
 *      Author: Narcano
 */
#include "tombman.h"
#include "struktura.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void seltol(char* sor, int hova) {
	int y = 0;

	switch (hova) {
	case 0:

		break;
	case 1:

		break;

	}
}

char** osszeolvas(char **t1, char** t2, int h1, int h2, int szel1, int szel2) { // elso helyre jon a hatter a masodikra pedig a karakter/hatter elem (ha lesz), a menu elso es also sora serthetetlen az az arra nem irunk
	char ** temp;
	int k = 0;
	int i = 0;
	temp = (char **) malloc(h1 * sizeof(char *));
	if (temp == NULL) {       //arra az esetre ha nem sikerulne memoria foglalni
		return NULL;
	}

	while (k < h1) {
			temp[k] = (char*) malloc((strlen(t1[k]) + 1) * sizeof(char));

			strcpy(temp[k], t1[k]);



		k++;
	}

	for (k = 0; k < h2; k++) {
		inserter(temp[k], t2[k], 0, strlen(t1[k]), strlen(t2[k]));
	}
	return temp;
}

void inserter(char* t1, char* t2, int eltolas, int szelesseg, int szelbemenet) {

	int i = 0;
	for (i = 0; i <= szelbemenet; i++) {

		if (t2[i] != '\0' && t2[i] != '\r' && t2[i] != '\n' && t2[i]!='~' && t2[i]!='!' ) {
			t1[i] = t2[i];
		}

	}

}

