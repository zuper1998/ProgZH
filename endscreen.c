/*
 * endscreen.c
 *
 *  Created on: 1 Dec 2017
 *      Author: Narcano
 */

#include <stdbool.h>
#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
#include "struktura.h"
#include "tombman.h"
#include "jatekmechanika.h"

void endgame() {
	szerkezet endstr;
	endstr.textura = beolvaso("endtext.txt", &endstr.hosz, &endstr.szelesseg);
	kiir(endstr.textura, endstr.hosz);
	freee(endstr);
	fflush(stdout);

	char c;
	char* text[50];
	scanf(" %c", &c);
	karakterlvl += 1;

	switch (c) {
	case 'c':
		strcpy(text, "end1.txt");
		difficulty += 1;


		break;

	case 's':
		strcpy(text, "end2.txt");
		save();

		break;

	case 'e':
		strcpy(text, "end3.txt");
		break;

	default:
		strcpy(text, "end4.txt");

	}

	endstr.textura = beolvaso(text, &endstr.hosz, &endstr.szelesseg);
	kiir(endstr.textura, endstr.hosz);
	freee(endstr);
	fflush(stdout);



	if (c=='c')
		jatek();
}


void save(){
FILE *f= fopen("savegame.txt","w");
fprintf(f,"karakter lvl: ~%d~\n",karakterlvl);
fprintf(f,"Game difficulty: |%d|\n",difficulty);
fclose(f);



}







