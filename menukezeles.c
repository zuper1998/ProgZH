/*
 * menukezeles.c
 *
 *  Created on: 26 Nov 2017
 *      Author: Narcano
 */
#include "struktura.h"
#include "tombman.h"
#include <string.h>
#include <stdio.h>
#include "menukezeles.h"


void beleir(szerkezet* menu,kari player,kari enemy){
	kiirstat(menu,player,enemy);
	kiirtxt(menu,"Press j ->   b <-   a: attack, and s to use a spell ",10);









}
void kiirstat(szerkezet* menu,kari player,kari enemy ){
	menu->szelesseg = strlen(menu->textura[2]);
	char pstr[50];
	char enestr[50];
	char difflvl[50];
	char dmg[50];
	char karlvl[50];

	sprintf(pstr," %d",player.hp);
	sprintf(enestr," %d",enemy.hp);
	sprintf(difflvl," %d",difficulty);
	sprintf(dmg," %d",player.weapon.sebzes);
	sprintf(karlvl," %d",karakterlvl);


	strcat(pstr,   "  hp");
	strcat(enestr, "  hp");
	strcat(difflvl,": difficultty level");
	strcat(dmg,"  dmg/turn");
	strcat (karlvl, " LVL");

	inserter(menu->textura[3],karlvl,11,strlen(karlvl));
	inserter(menu->textura[4],difflvl,11,strlen(difflvl));
	inserter(menu->textura[5],dmg,11,strlen(dmg));














if (player.hp>=100){
	inserter(menu->textura[2],pstr,10,strlen(pstr));}else if(player.hp>=0){
		pstr[0]='|';

		inserter(menu->textura[2],pstr,11,strlen(pstr));
	}else {
		pstr[0]='|';

				inserter(menu->textura[2],pstr,11,strlen(pstr));



	}
if (enemy.hp>=100){
	inserter(menu->textura[2],enestr,menu->szelesseg-25,strlen(enestr));

}else{
	enestr[0]='0';
	inserter(menu->textura[2],enestr,menu->szelesseg-24,strlen(enestr));

}


}
void kiirtxt(szerkezet* menu, char* str,int sor){
	inserter(menu->textura[sor],str,10,strlen(str));

}
