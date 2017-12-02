/*
 * enemy.h
 *
 *  Created on: 20 Nov 2017
 *      Author: Narcano
 */

#ifndef ENEMY_H_
#define ENEMY_H_

char** enemyai(szerkezet*,kari*,kari*);
void weaponize(kari* );
void attack(kari* target,kari attacker);
void spell(kari* enemy);

#endif /* ENEMY_H_ */
