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


char** seltol(szerkezet hatter, szerkezet karakter,int merre,int* helyzetsegedlet) {           //0,2 -> ; 1,3 <-
	char** eltolt;
	int SPEEEEEEEEEED = 10;
	int enemspeed = 5;

	switch (merre) {
	case 0:
		eltolt =osszeolvas(hatter,karakter,SPEEEEEEEEEED+(*helyzetsegedlet*SPEEEEEEEEEED),20);
		*helyzetsegedlet= *helyzetsegedlet+1;

		break;
	case 1:
		eltolt = osszeolvas(hatter,karakter,(-1)*SPEEEEEEEEEED+(*helyzetsegedlet*SPEEEEEEEEEED),20);
		*helyzetsegedlet= *helyzetsegedlet-1;

		break;
	case 2:
		eltolt =osszeolvas(hatter,karakter,enemspeed+(*helyzetsegedlet*enemspeed),0);
		*helyzetsegedlet= *helyzetsegedlet+1;

		break;
	case 3:
		eltolt = osszeolvas(hatter,karakter,(-1)*enemspeed+(*helyzetsegedlet*enemspeed),0);
		*helyzetsegedlet= *helyzetsegedlet-1;

		break;
	case 4:
	eltolt = osszeolvas(hatter,karakter,0,20);
			break;
	break;





	default:
		eltolt = osszeolvas(hatter,karakter,0,20);
		break;


	}
	return eltolt;


}

char** osszeolvas(szerkezet hatter, szerkezet karakter,int eltolx,int lenyom) { // elso helyre jon a hatter a masodikra pedig a karakter/hatter elem (ha lesz), a menu elso es also sora serthetetlen az az arra nem irunk
	char ** temp;
	char **t1 = hatter.textura;
	char** t2 =karakter.textura;
	int szelesseg = strlen(hatter.textura[0])+1;


	int k = 0;
	temp = (char **) malloc(hatter.szelesseg * sizeof(char *));
	if (temp == NULL) {       												//arra az esetre ha nem sikerulne memoria foglalni
		return NULL;
	}

	while (k < hatter.hosz) {
			temp[k] = (char*) malloc((strlen(t1[k]) + 1) * sizeof(char));

			strcpy(temp[k], t1[k]);



		k++;
	}

	for (k = 0; k <karakter.hosz; k++) {
		inserter(temp[k+lenyom], t2[k], eltolx, strlen(t1[k]), strlen(t2[k]));          //15 sorral lejjebb rakja
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






