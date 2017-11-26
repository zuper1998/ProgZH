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


char** enemyai(szerkezet* hatter,kari* enemy,kari* player){      //2 b 3 j 4 m
char **komplethatter;
int mozgas =4;



if  (isnearenought(*player,*enemy)) {
attack(player,*enemy);
mozgas = 4;


}else  {
mozgas = 3;
}






komplethatter = seltol(*hatter, enemy->textura,mozgas,&enemy->location);
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


void attack (kari* player,kari enemy){
	player->hp -=  enemy.weapon.sebzes;

}









