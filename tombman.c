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

char ** jeltolo(tomb* t) {
int k;
int szel = t->szelesseg;


for (k=0;k<t->hosz;k++){
t->textura[k] = realloc(t->textura[k],(szel+1)*sizeof(char));
}




	return t;
}

void seltol(char* sor, int hova){
    int y=0


    switch (hova){
    case 0:
        for(y=0;sor[y]!='\n';y++;){
            if (sor[y]=='\n'){
                for (;y>=0;y--){
                    if(y==0){
                        sor[y] = '\t';

                        break;
                    }
                    sor[y] = sor[y-1];

                }
            }
        }

        break;
    case 1:



        break;

}
}


char** osszeolvas(char **t1, char** t2, int h1, int h2) { // elso helyre jon a hatter a masodikra pedig a karakter/hatter elem (ha lesz), a menu elso es also sora serthetetlen az az arra nem irunk
	char ** temp;
	int k;
	temp = (char **) malloc(h1 * sizeof(char *));
	if (temp == NULL) {       //arra az esetre ha nem sikerulne memoria foglalni
		return NULL;
	}

	for (k = 0; k < h1; k++) {

		temp[k] = (char*) malloc((strlen(t1[k]) + 1) * sizeof(char));
		strcpy(temp[k], t1[k]);

	}

	for (k = 0; k < h2; k++) {
		strcpy(temp[k + (h1 - h2)], t2[k]);
	}

	return temp;
}
