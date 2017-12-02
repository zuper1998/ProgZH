/*
 * load.c
 *
 *  Created on: 2 Dec 2017
 *      Author: Narcano
 */

#include <stdio.h>
#include "struktura.h"
#include "menu.h"
#include <stdlib.h>
#include "load.h"
#include "tombman.h"
#include "jatekmechanika.h"

typedef enum olvasALL {
	olvaslvl, olvasdiff, semmi

} olvasALL;

void load() {
	FILE *f = fopen("savegame.txt", "r");
	char lvl[10];
	char diff[10];
	int i = 0, k = 0;
	char c;
	if (f == NULL)
		printf("loadfile_error");

	olvasALL all = semmi;

	while ((c = (char) fgetc(f)) != EOF) {
		switch (all) {
		case semmi:
			switch (c) {
			case '~':
				all = olvaslvl;

				break;

			case '|':
				all = olvasdiff;

				break;
			}

			break;

		case olvaslvl:
			switch (c) {
			case '~':
				all = semmi;

				break;
			default:
				lvl[i] = c;
				i++;
				break;

			}
			break;
		case olvasdiff:
			switch (c) {
			case '|':
				all = semmi;

				break;
			default:
				diff[k] = c;
				k++;
				break;

			}

		}

	}
	diff[k] =0;
	lvl[i] =0;
	fclose(f);

difficulty =	atalakit(diff);
karakterlvl =atalakit(lvl);



}

int atalakit(char* beme){
	int value=0;
	int i=0;
if (beme[0]==0)
	return value;

	value += atalakit(beme+1);


	if (strlen(beme)<2)
	value +=(int)( beme[i]-'0');
	else
		value +=(int)( beme[i]-'0')*10*(strlen(beme)-1);



return value;
}

void startscreen(){
	szerkezet temp;


	temp.textura = beolvaso("start.txt", &temp.hosz,
					&temp.szelesseg);
			kiir(temp.textura, temp.hosz);
			fflush(stdout);
			freee(temp);
int c = getchar();






}




















