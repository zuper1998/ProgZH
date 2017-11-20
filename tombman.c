/*
 * tombman.c
 *
 *  Created on: 7 Nov 2017
 *      Author: Narcano
 */
#include "struktura.h"
#include "tombman.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char** seltol(char **t1, char** t2, int h1, int h2,int merre,int* helyzetsegedlet) {           //0 -> ; 1 <-
	char** eltolt;
	int SPEEEEEEEEEED = 10;


	switch (merre) {
	case 0:
		eltolt =osszeolvas(t1,t2,h1,h2,SPEEEEEEEEEED+(*helyzetsegedlet*SPEEEEEEEEEED));
		*helyzetsegedlet= *helyzetsegedlet+1;

		break;
	case 1:
		eltolt = osszeolvas(t1,t2,h1,h2,(-1)*SPEEEEEEEEEED+(*helyzetsegedlet*SPEEEEEEEEEED));
		*helyzetsegedlet= *helyzetsegedlet-1;

		break;
	default:
		eltolt = osszeolvas(t1,t2,h1,h2,0);
		break;


	}
	return eltolt;


}

char** osszeolvas(char **t1, char** t2, int h1, int h2,int eltolx) { // elso helyre jon a hatter a masodikra pedig a karakter/hatter elem (ha lesz), a menu elso es also sora serthetetlen az az arra nem irunk
	char ** temp;
	int k = 0;
	temp = (char **) malloc(h1 * sizeof(char *));
	if (temp == NULL) {       												//arra az esetre ha nem sikerulne memoria foglalni
		return NULL;
	}

	while (k < h1) {
			temp[k] = (char*) malloc((strlen(t1[k]) + 1) * sizeof(char));

			strcpy(temp[k], t1[k]);



		k++;
	}

	for (k = 0; k < h2; k++) {
		inserter(temp[k+3], t2[k], eltolx, strlen(t1[k]), strlen(t2[k]));          //3 sorral lejjebb rakja
	}
	return temp;
}

void inserter(char* t1, char* t2, int eltolas, int szelesseg, int szelbemenet) {

	int i = 0;
	for (i = 0; i <= szelbemenet; i++) {

		if (t2[i] != '\0' && t2[i] != '\r' && t2[i] != '\n' && t2[i]!='~' && t2[i]!='!' &&t2[i]!=' ') {
			t1[i+eltolas] = t2[i];
		}

	}

}

char** elhelyezo(char **t1, char** t2, int h1, int h2,int eltoly,int eltolx) {
	char ** temp;
	int k = 0;
	temp = (char **) malloc(h1 * sizeof(char *));
	if (temp == NULL) {
		return NULL;
	}

	while (k < h1) {
			temp[k] = (char*) malloc((strlen(t1[k]) + 1) * sizeof(char));

			strcpy(temp[k], t1[k]);



		k++;
	}

	for (k = 0; k < h2; k++) {
		inserter(temp[k+eltoly], t2[k], eltolx, strlen(t1[k]), strlen(t2[k]));
	}
	return temp;
}



int swordinsert(char*** t1,furakard sword, int eltoly,int eltolx){
	int k=0,i=0;
	char** t2=sword.textura.textura;
	int lenght = strlen(t2[k]);


	if( strlen(*t1[0]) < strlen(t2[0]) ){
			return 0;
		}
	for(k=0;k<sword.textura.hosz;k++){
		for (i=0;i<lenght-2;i++){
			if (t2[k][i] != ' ')
			(*t1)[k+eltoly][i+eltolx] = t2[k][i];

		}
	}
return 1;
}






