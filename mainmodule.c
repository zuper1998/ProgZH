/*
 * mainmodule.c
 *
 *  Created on: 27 Oct 2017
 *      Author: Narcano
 */
#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
#include "struktura.h"
#include "tombman.h"


int main(void) {
	tomb menu;
	tomb karakter;












		karakter.textura = beolvaso("character.txt",	&karakter.hosz);

		menu.textura = beolvaso("menu.txt",			&menu.hosz);

	kiir(karakter.textura, karakter.hosz);
	kiir(menu.textura, menu.hosz);
	/*
	 freee(karakter, khosz);
	 freee(menu, mhosz);
	 */
	return 0;
}
