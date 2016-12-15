#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "fonction.h"

int main(int argc, char *argv[], char *envp[])
{
// lanceur du eXiasaver

    srand(time(NULL)); //Nombre aléatoire généré
    int modechoisi; //Déclaration variable du mode choisi
    modechoisi = choixMode(); //On lance la fonction choixMode
    int imagestatique=0;
    imagestatique = choisirImage();// on choisit une image aleatoirement
    system("clear");
    sauvegardeInfos(modechoisi);
    char command[100];

    if (argc==2 && strcmp(argv[1],"-stat")==0)
    {
        menustat();
    }

    else
    {
        //execution des modes
        modechoisi=1;
        switch (modechoisi)
        {
        case 1:
            //strcpy(command,"(cd statique ; ./statique \n");
            printf("%s",command);
            char buffer[100];
            sprintf(buffer, "(cd statique ; ./statique %d)", imagestatique);
            //strcat(command,"(cd statique ; ./statique");
            //strcat(command,buffer);
            //strcat(command,")");
            //printf("%s",command);
            system(buffer);
            //system("(cd statique ; ./statique)");
            break;

        case 2:
            //execve("\"dynamique//dynamique\"", argv[], NULL);
            break;

        case 3:
            //execve("\"interactif//interactif\"", argv[], NULL);
            break;

        default:
            printf("Erreur\n");
            break;
        }
    }

    system("wait");
    return 0;
}
