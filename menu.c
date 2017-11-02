    /*
     * menu.c
     *
     *  Created on: 27 Oct 2017
     *      Author: Narcano
     */
    #include <stdio.h>
    #include <stdlib.h>
    #include "menu.h"

    void beolvaso(char ** m, char* sz,int *hosz) {			// end of line jel : ~  EOF: !
        FILE *p;
        char a;
        int sorszam = 0;
        int sorhosz = 0;
        int i,k,hely = 0;

        p = fopen("menu.txt", "r");

        do {
            a = fgetc(p);
            if (a == '~') {
                sorhosz = i;
                sorszam++;
                i = 0;
            }
            i++;
        } while (a != '!');
    fclose(p);
      //  printf("%d %d %d \n", sorszam, sorhosz, i);

        m = (char **) realloc(m,sorszam*sizeof(*m));


        p = fopen("menu.txt","r");
        char str[sorhosz+2];
        for (k=0;k<=sorszam+1;k++){

            m[k] = (char*) malloc(sorhosz * sizeof(char));

            if (fgets(str,sorhosz,p)!=NULL ){

            strcpy(m[hely],str);
            hely++;
        }

            }





    fclose(p);
    for (i=0;i<=sorszam;i++){
        printf("%s",m[i]);

    }



    *hosz = sorszam;

    }

    void freee(char** a, int h){
       int i;
       for (i=0;i<=h;i++){
            free(a[i]);
        }
        free(a);

    }







