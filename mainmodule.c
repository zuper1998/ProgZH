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
	tomb hatter;










		karakter.textura = beolvaso("character.txt",	&karakter.hosz,&karakter.szelesseg);

		menu.textura = beolvaso("menu.txt",			&menu.hosz,&menu.szelesseg);

		hatter.textura = beolvaso("hatter.txt" ,     &hatter.hosz,&hatter.szelesseg);

		hatter.textura = osszeolvas(hatter.textura,karakter.textura,hatter.hosz,karakter.hosz,hatter.szelesseg,karakter.szelesseg);


/*
	kiir(karakter.textura, karakter.hosz);
	kiir(menu.textura, menu.hosz);
	kiir(hatter.textura,hatter.hosz);
	*/
	kiir(hatter.textura,hatter.hosz);



/*
	 freee(karakter.textura, karakter.hosz );
	 freee(menu.textura,karakter.hosz );
*/
	return 0;
}
