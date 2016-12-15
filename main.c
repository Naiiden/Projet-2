#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "fonction.h"

int main(int argc, char *argv[])
{
// lanceur du eXiasaver

    srand(time(NULL)); //Nombre aléatoire généré
    int modechoisi; //Déclaration variable du mode choisi
    modechoisi = choixMode(); //On lance la fonction choixMode
    system("clear");
    sauvegardeInfos(modechoisi);

    if (argc>=2)
    {
        if (strcmp(argv[1],"-stat")==0)
        {
            menustat();
        }
        else
        {
        }
    }

    else
    {
        // fonction a creer
        //execution des modes
        switch (modechoisi)
        {
        case 1:n
            printf("mode statique choisi\n");
            //chemin
            execv("statique")
            break;

        case 2:
            printf("mode dynamique choisi\n");
            //chemin
            execv
            break;

        case 3:
            printf("mode interactif choisi\n");
            //chemin
            execv
            break;

        default:
            printf("Erreur\n");
            break;
        }
    }

    system("wait");
    return 0;
}
