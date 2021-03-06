/*
 * struktura.h
 *
 *  Created on: 7 Nov 2017
 *      Author: Narcano
 */

#ifndef STRUKTURA_H_
#define STRUKTURA_H_

typedef struct tomb{
	char** textura;
	int hosz;
    int szelesseg;

}szerkezet;
typedef struct fegyverek{
	int sebzes;
	szerkezet textura;
	struct fegyverek *kovszint;
}furakard;
typedef struct karakteradatok{
	szerkezet textura;
	int hp;
	furakard weapon;
	int location;
	int swordlvl;
}kari;




typedef struct armor{
	int def;

	struct armor *kovszint;
}armor;

extern int difficulty;
extern int karakterlvl;
extern kari GlobalKar;
extern armor Globalvedelem;
extern furakard GlobalWeapon;
extern szerkezet GlobalStuct;


#endif /* STRUKTURA_H_ */
