#include "struktura.h"
#include "endscreen.h"
#include <stdio.h>



void endscreen(int* dificulty,kari* player){





printf("LEVEL UP! press (c)ountinue, (s)ave, or (e)nd \n");
char c;
scanf(" %c",&c);
player->lvl +=1;



switch (c){
    case'c':
        printf("Then lets had back to combat");
        *dificulty+=1;


        break;


   case 's':
        printf("game saved");
        break;


   case 'e':
        printf("Well, still better then death");
        break;

   default:
    printf("i cant understand that, goodbye then");

}
}




