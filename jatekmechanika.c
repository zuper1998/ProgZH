/*
 * jatekmechanika.c
 *
 *  Created on: 10 Nov 2017
 *      Author: Narcano
 */

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
	kari jatekos;
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
	menu.textura = beolvaso("menu.txt", &menu.hosz, &menu.szelesseg);
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

	while (jatekos.hp > 0) {

		scanf(" %c", &bemenet);
		switch (bemenet) {
		case 'j':
			if (isnearenought(jatekos, enemy)) {
				kiirtxt(&menu, "you are too close :/", 20);
			} else {
				kijelzo1.textura = seltol(hatter, jatekos.textura, 0,
						&jatekos.location);
			}
			break;
		case 'b':
			kijelzo1.textura = seltol(hatter, jatekos.textura, 1,
					&jatekos.location);

			break;
		case 'a':

			if (isnearenought(jatekos, enemy)) {
				attack(&enemy, jatekos);
			} else {

				kiirtxt(&menu, "you are not close enought :/", 15);

			}

			break;

		default:
			kijelzo1.textura = seltol(hatter, jatekos.textura, -1,
					&jatekos.location);
			break;
		}

		kijelzo2.textura = enemyai(&hatter, &enemy, &jatekos);
		system("clear");
		kijelzo_vegleg.textura = osszeolvas(kijelzo1, kijelzo2, 0, 0);

		kiir(kijelzo_vegleg.textura, kijelzo_vegleg.hosz);
		kiir(menu.textura, menu.hosz);

		beleir(&menu, jatekos, enemy);

		fflush(stdout);

	}
}

void beolvas(kari* jatekos) {
	jatekos->hp = 100;
	szerkezet karakter;
	karakter.textura = beolvaso("char1.txt", &karakter.hosz,
			&karakter.szelesseg);
	jatekos->textura = karakter;

}

void getsword(kari* karakter) {       //y:44 x:40   nagyobb le   nagyobb jobra
	furakard sword;
	sword.textura.textura = beolvaso("sword1.txt", &sword.textura.hosz,
			&sword.textura.szelesseg);
	int siker = swordinsert(&karakter->textura.textura, sword, 27, 37);
	if (siker == 0) {
		printf("a kard beolvasas nem mukodot");
		return;
	}

}

bool isnearenought(kari player, kari enemy) {
	bool isnear = true;
	if (enemy.location - player.location > 75) {
		isnear = false;
	}

	return isnear;
}

