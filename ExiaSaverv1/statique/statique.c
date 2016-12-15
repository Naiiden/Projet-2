#include "statique.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <time.h>

void centrerImageVertical(int largeur, int hauteur)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int n;
    for (n=0; n<(w.ws_row-hauteur)/2; n++)
    {
        printf("\n");
    }

}


void centrerImage(int largeur, int hauteur)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int n;
    for (n=0; n<(w.ws_col-largeur)/2; n++)
    {
        putchar(' ');
    }
}


int choisirImage() {
        int nombre = 0;
        srand(time(NULL));
        nombre = (rand()%(6-1) +1);
        //printf("%d", nombre);
        return nombre;
}
