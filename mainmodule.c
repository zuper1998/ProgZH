/*
 * mainmodule.c
 *
 *  Created on: 27 Oct 2017
 *      Author: Narcano
 */
#include <stdio.h>
#include "menu.h"
#include <stdlib.h>

int main(void) {
	char **menu;
	char **karakter;
	int khosz = 0;
	int mhosz = 0;

	menu = (char**) malloc(sizeof(char*));
	karakter = (char**) malloc(sizeof(char*));

		beolvaso(karakter,	"character.txt",	&khosz);

		beolvaso(menu,		"menu.txt",			&mhosz);

	kiir(karakter, khosz);
	kiir(karakter, mhosz);
	/*
	 freee(karakter, khosz);
	 freee(menu, mhosz);
	 */
	return 0;
}
