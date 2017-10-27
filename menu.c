/*
 * menu.c
 *
 *  Created on: 27 Oct 2017
 *      Author: Narcano
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void beolvaso(char ** m, char* sz) {			// end of line jel : ~  EOF: !
	FILE *p;
	char a;
	int sorszam = 0;
	int sorhosz = 0;
	int i,k = 0;

	p = fopen("menu.txt", "r");

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
	//printf("%d %d %d", sorszam, sorhosz, i);

	m = (char **) realloc(m,sorszam*sizeof(*m));


	p = fopen("menu.txt", "r");

	for (k=0;k<=sorszam+3;k++){
		m[k] = (char*) malloc(sorhosz * sizeof(char));
		fgets(m[k],sorhosz,p);
	}
for (i=0;i<=sorszam;i++){
	printf("%s",m[i]);

}





}

