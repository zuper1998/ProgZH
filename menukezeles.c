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
	kiirhp(menu,player,enemy);
	kiirtxt(menu,"Nyomd meg j ->   b <-   a: tamadas ",10);









}
void kiirhp(szerkezet* menu,kari player,kari enemy ){
	menu->szelesseg = strlen(menu->textura[2]);
	char* pstr=malloc(3*sizeof(char));
	char* enestr=malloc(3*sizeof(char));
	sprintf(pstr,"%d",player.hp);
	sprintf(enestr,"%d",enemy.hp);


	inserter(menu->textura[2],pstr,10,strlen(pstr));
	inserter(menu->textura[2],enestr,menu->szelesseg-25,strlen(enestr));



}
void kiirtxt(szerkezet* menu, char* str,int sor){
	inserter(menu->textura[sor],str,sor,strlen(str));

}
