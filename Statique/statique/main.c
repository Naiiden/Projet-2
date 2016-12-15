#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <time.h>

#include "statique.h"

int main(int argc, char *argv[]) {
    // INIT
    int ligne = 1;
    int image = 0;
    int nombreCaracteres;
    char caractereLu;
    int imageSize = 0;
    int tailleImage = 0;
    int largeurImage = 0;
    int hauteurImage = 0;

    char separateur[1] = " ";
    char * pch;


    char taille[10];

    //int bytes[1996] = {0}; //tableau qui contiendra tous les bytes des images (0 et 1)
    int i= 0;
    int j =0;// i -> compteur de tour, j -> retour a la ligne
    FILE* fichier = NULL;

    int nbLine = 0;
    char cheminFichier[128] = "";

    image = choisirImage();

    snprintf(cheminFichier, sizeof cheminFichier, "images/%d.pbm", image);
    fichier = fopen(cheminFichier, "r+");


    // CODE
    system("clear");
    //fichier = fopen("mecsimpson.pbm","r+"); //ouverture de l'image

    if (fichier != NULL) { //Si l'image est bien ouverte


    int c;
    while((c=fgetc(fichier)) != EOF){ //On compte le nombre de caractère que contient le fichier pour savoir sa taille en octet
        imageSize++;
    }


    rewind(fichier);

    int bytes[imageSize]; //tableau avec la taille du fichier
    memset(bytes,'\0',imageSize); // mettre toutes les cases du tableau à NULLE




    while(ligne < 3 && caractereLu != EOF){ //On passe les 2 premières lignes (ne nous interressent pas) ligne<3
            caractereLu = fgetc(fichier);
            if(caractereLu=='\n') {
                ligne++;
            }
    }

    fgets(taille, 10, fichier);


    //sprintf("%s",taille);

    pch = strtok (taille," ");
    while (pch != NULL)
    {
      //printf ("valeur x :-%s-\n",pch);
     sscanf(pch, "%d", &largeurImage);
     pch = strtok (NULL, " ");
     //printf ("valeur y : -%s-\n",pch);
    sscanf(pch, "%d", &hauteurImage);
     break;
    }

    rewind(fichier);
    ligne = 1;

        while(ligne < 4 && caractereLu != EOF){ //On passe les 3 premières lignes (ne nous interressent pas) ligne<4
            caractereLu = fgetc(fichier);

            if (caractereLu == '\n'){
                ligne++;
            }
        }

        for (i = 0; i < imageSize; i++) { // Boucle qui va parcourir tous les bytes de l'image et les stocker dans le tableau bytes
            bytes[i] = fgetc(fichier);

            if(bytes[i] == '\n') { //On annule un retour à la ligne du fichier s'il y en a un
                i=i-1;

            }
        }


        centrerImageVertical(largeurImage, hauteurImage);
        centrerImage(largeurImage, hauteurImage);

        for (i = 0; i < imageSize+1; i++){ //Boucle qui va afficher tous les 0 et 1 dans la console


            if (j == largeurImage) { //Au bout de 80, il y a un retour à la ligne dans la console (pour garder le format 80x24)
                printf("\n"); //retour a la ligne
                j = 0;
                nbLine++;
                centrerImage(largeurImage, hauteurImage);
            }

            // hack pour eviter le decalage de caracteres vers la droite :)
            /*if(!((nbLine >= 7 && j <= 1) || (nbLine >= 14 && j <= 2) || (nbLine >= 21 && j <= 3))){
                if (bytes[i] != '\0'){
                    if (bytes[i] == '0' && j != 0){ //Si le bit est un 0, on affiche un espace
                        printf(" ");
                    }
                    if (bytes[i] == '1'){ //Si le bit est un 1 on affiche un carré rempli
                        printf("\xe2\x96\x96");
                    }
                }
            }*/


                    if (bytes[i] == '0'){ //Si le bit est un 0, on affiche un espace
                        printf(" ");
                    }
                    if (bytes[i] == '1'){ //Si le bit est un 1 on affiche un carré rempli
                        printf("\xe2\x96\x96");
                    }



            j++;
        }
        fclose(fichier); //On ferme le fichier
        printf("\n");

    system("/bin/stty raw");
        getchar();
        system("/bin/stty cooked");
    }

    system("clear");
    return 0;
}
