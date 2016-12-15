#ifndef STATIQUE_H /*ligne de base*/
#define STATIQUE_H /*ligne de base*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>

int choixMode();
void chargerimage();
void sauvegardeInfos(int mode);
int afficherInfo();
void afficherfinInfo();
void menustat();
void creerFork();

#endif // STATIQUE_H
