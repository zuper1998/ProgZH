/*
 * jatekmechanika.c
 *
 *  Created on: 10 Nov 2017
 *      Author: Narcano
 */




#if defined POSIX
  #define CLEARSCR system ( "clear" )
#elif defined MSDOS || defined WIN32
  #define CLEARSCR system ( "cls" )
#endif






#include <stdbool.h>
#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
#include "struktura.h"
#include "tombman.h"
#include "jatekmechanika.h"
#include "enemy.h"
#include "menukezeles.h"

void jatek() {
	kari jatekos;												//inicializalas
	kari enemy;
	beolvas(&jatekos);
	getsword(&jatekos);
	char bemenet;
	jatekos.location = 0;
	szerkezet menu;
	szerkezet hatter;
	szerkezet kijelzo1;
	szerkezet kijelzo2;
	szerkezet kijelzo_vegleg;
	int move = -1;

	menu.textura = beolvaso("menu.txt", &menu.hosz, &menu.szelesseg);//beolvasas
	hatter.textura = beolvaso("hatter.txt", &hatter.hosz, &hatter.szelesseg);
	weaponize(&enemy);
	enemy.location = (strlen(hatter.textura[0])
			- (strlen(enemy.textura.textura[0])) - 50);
	kijelzo2.textura = enemyai(&hatter, &enemy, &jatekos);
	kijelzo1.textura = seltol(hatter, jatekos.textura, -1, &jatekos.location);
	kijelzo_vegleg.hosz = hatter.hosz;
	kijelzo1.hosz = hatter.hosz;
	kijelzo2.hosz = hatter.hosz;

	kijelzo_vegleg.textura = osszeolvas(kijelzo1, kijelzo2, 0, 0);
	beleir(&menu, jatekos, enemy);

	kiir(kijelzo_vegleg.textura, kijelzo_vegleg.hosz);
	kiir(menu.textura, menu.hosz);
	fflush(stdout);

	while (jatekos.hp > 0) {										//jatekmenet

		scanf(" %c", &bemenet);
		switch (bemenet) {
		case 'j':
			if (isnearenought(jatekos, enemy)) {
				kiirtxt(&menu, "you are too close :/", 13);
				move = -1;
			} else {
				move = 0;
			}
			break;
		case 'b':
			move = 1;

			break;
		case 'a':
			move = -1;
			if (isnearenought(jatekos, enemy)) {
				attack(&enemy, jatekos);
			} else {

				kiirtxt(&menu, "you are not close enought :/", 12);

			}

			break;
		case 's':
			kiirtxt(&menu, "Whooosh~", 9);
			spell(&enemy);


			break;

		case 'k':
			enemy.hp = -1;

			break;
		default:
			move = -1;
			break;
		}
		kijelzo1.textura = seltol(hatter, jatekos.textura, move,
				&jatekos.location);
		kijelzo2.textura = enemyai(&hatter, &enemy, &jatekos);
		system("CLEARSCR");
		kijelzo_vegleg.textura = osszeolvas(kijelzo1, kijelzo2, 0, 0);
		beleir(&menu, jatekos, enemy);
		kiir(kijelzo_vegleg.textura, kijelzo_vegleg.hosz);
		kiir(menu.textura, menu.hosz);

		fflush(stdout);

		menu.textura = beolvaso("menu.txt", &menu.hosz, &menu.szelesseg);
		if (enemy.hp < 0) {
			kiirtxt(&menu, "You won!", 9);
			break;
		}
		beleir(&menu, jatekos, enemy);

	}

	freee(menu);
	freee(hatter);
	freee(kijelzo1);
	freee(kijelzo2);
	freee(kijelzo_vegleg);
	freee(jatekos.textura);
	freee(enemy.textura);

	if (jatekos.hp < 0) {
		szerkezet endstr;
		endstr.textura = beolvaso("gitgud.txt", &endstr.hosz,
				&endstr.szelesseg);
		kiir(endstr.textura, endstr.hosz);
		freee(endstr);

		FILE *f = fopen("savegame.txt", "w");
		fprintf(f, "karakter lvl: ~%d~\n", 1);
		fprintf(f, "Game difficulty: |%d|\n", 1);
		fprintf(f, "Git Gud~");

		fclose(f);

	} else {

		endgame();
	}
}

void beolvas(kari* jatekos) {
	jatekos->hp = 100 * karakterlvl;
	szerkezet karakter;
	karakter.textura = beolvaso("char1.txt", &karakter.hosz,
			&karakter.szelesseg);
	jatekos->textura = karakter;

}

void getsword(kari* karakter) {       //y:44 x:40   nagyobb le   nagyobb jobra
	furakard sword;
	switch (karakter->swordlvl) {
	int siker;

case 1:

	sword.textura.textura = beolvaso("sword1.txt", &sword.textura.hosz,
			&sword.textura.szelesseg);
	siker = swordinsert(&karakter->textura.textura, sword, 27, 37);
	karakter->weapon.sebzes = 10 + 3 * karakterlvl;

	break;
default:
	sword.textura.textura = beolvaso("sword1.txt", &sword.textura.hosz,
			&sword.textura.szelesseg);
	siker = swordinsert(&karakter->textura.textura, sword, 27, 37);
	karakter->weapon.sebzes = 10 + 3 * karakterlvl;
	if (siker == 0) {
		printf("a kard beolvasas nem mukodot");
		return;
	}
	}
}

bool isnearenought(kari player, kari enemy) {
	bool isnear = true;
	if (enemy.location - player.location > 66) {
		isnear = false;
	}

	return isnear;
}

