/*
 * enemy.c
 *
 *  Created on: 20 Nov 2017
 *      Author: Narcano
 */
#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
#include "struktura.h"
#include "tombman.h"
#include "jatekmechanika.h"
#include <string.h>
#include "enemy.h"


char** enemyai(int player_loc, szerkezet* hatter){
kari enemy;
char **komplethatter;
enemy.location = (strlen(hatter->textura[0])-strlen(enemy.textura.textura[0]));

weaponize(&enemy);

komplethatter = seltol(*hatter, enemy.textura,-1,&enemy.location);










return komplethatter;
}


void weaponize(kari* enemy){
	szerkezet enemyszerk;
	furakard enemkard;
	enemkard.sebzes=5;
	enemyszerk.textura = beolvaso("enemy1.txt", &enemyszerk.hosz, &enemyszerk.szelesseg);

	enemy->hp=50;
	enemy->textura = enemyszerk;
	enemy->weapon = enemkard;





}
