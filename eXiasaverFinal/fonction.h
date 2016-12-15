#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>

/* structure qui peuvent servir

typedef struct Date Date;
struct Date
{
    int jour;
    int mois;
    int annee;
};

typedef struct Heure Heure;
struct Heure
{
        int heure;
        int minute;
        int seconde;
};

typedef struct lancement lancement;
struct lancement
{
    Date date;
    Heure heure;
    int mondelancer;
    char* donnee[];
};

typedef struct avion avion;
struct avion
{
    int posX;
    int posY;
    char sens;
};

typedef struct image image;
struct image
{
    char image[80][24];
    int posX;
    int posY;
};*/

int choixMode();
int choisirImage();
void sauvegardeInfos(int mode);
void afficherInfo();
void afficherfinInfo();
void trierinfo();
void menustat();
