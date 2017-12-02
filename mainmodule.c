/*
 * mainmodule.c
 *
 *  Created on: 27 Oct 2017
 *      Author: Narcano
 */
#include <stdio.h>
#include "struktura.h"
#include "menu.h"
#include <stdlib.h>
#include "load.h"
#include "tombman.h"
#include "jatekmechanika.h"
#include "endgame.h"

int difficulty =1;
int karakterlvl =1;
int main(void) {

	startscreen();
	load();
	jatek();


	return 0;
}
