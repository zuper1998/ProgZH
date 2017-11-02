/*
 * mainmodule.c
 *
 *  Created on: 27 Oct 2017
 *      Author: Narcano
 */
#include <stdio.h>
#include "menu.h"

int main (void){
	char **c ;
	int hosz;
	c= (char**) malloc(sizeof(char*));



	beolvaso(c,"re",&hosz);

    freee(c,hosz);



	return 0;
}
