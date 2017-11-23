/*
 * jatekmechanika.c
 *
 *  Created on: 10 Nov 2017
 *      Author: Narcano
 */

#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
#include "struktura.h"
#include "tombman.h"
#include "jatekmechanika.h"
#include "enemy.h"

void jatek() {
	kari jatekos;
	beolvas(&jatekos);
	getsword(&jatekos);
	char bemenet;
	jatekos.location=0;
	szerkezet menu;
	szerkezet hatter;
	szerkezet kijelzo;
	menu.textura = beolvaso("menu.txt", &menu.hosz, &menu.szelesseg);
	hatter.textura = beolvaso("hatter.txt", &hatter.hosz, &hatter.szelesseg);
//	hatter.textura = enemyai(jatekos.location,&hatter);
	kijelzo.hosz = hatter.hosz;
	kijelzo.textura =seltol(hatter, jatekos.textura,-1,&jatekos.location);



	kiir(kijelzo.textura,kijelzo.hosz);
	kiir(menu.textura,menu.hosz);
	fflush(stdout);


	while (jatekos.hp > 0) {
	//	hatter.textura = enemyai(jatekos.location,&hatter);

		scanf(" %c", &bemenet);
		switch (bemenet) {
		case 'j':
			kijelzo.textura =seltol(hatter, jatekos.textura,0,&jatekos.location);

			break;
		case 'b':
			kijelzo.textura =seltol(hatter, jatekos.textura,1,&jatekos.location);

			break;


		default:
			kijelzo.textura =seltol(hatter, jatekos.textura,-1,&jatekos.location);
			break;
		}



		system("clear");
		kiir(kijelzo.textura,kijelzo.hosz);
		kiir(menu.textura,menu.hosz);


		fflush(stdout);

	}
}

void beolvas(kari* jatekos) {
	jatekos->hp = 100;
	szerkezet karakter;
	karakter.textura = beolvaso("char1.txt", &karakter.hosz,&karakter.szelesseg);
	jatekos->textura = karakter;

}





void getsword(kari* karakter){       //y:44 x:40   nagyobb le   nagyobb jobra
	furakard sword;
	sword.textura.textura= beolvaso("sword1.txt", &sword.textura.hosz,&sword.textura.szelesseg);
	int siker =swordinsert(&karakter->textura.textura,sword,27,37);
	if (siker==0){
			printf("a kard beolvasas nem mukodot");
			return;
	}




}


