#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>

int choixMode()//Choix du mode
{
    int mode;
    mode = rand()%(4-1) +1; //Entre 1 et 3 ( l'intervalle est [1,3[ )
    return mode; //On renvoi la valeur du mode chosii (1, 2 ou 3) au main
}


int choisirImage()
{
    int nombre = 0;
    srand(time(NULL));
    nombre = (rand()%(6-1) +1);
    //printf("%d", nombre);
    return nombre;
}

void sauvegardeInfos (int mode) // fonction pour sauvegarder les infos dans un fichier texte
{
    const char* NomMois[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"}; // afficher le numéro des mois a la place du nom
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime); // permet de capturer l'horloge de l'os
    timeinfo = localtime (&rawtime); // permet d'ecrire sans avoir le nombre de seconde depuis le 01/01/1900

    FILE *ft=NULL; //permet de controler les flux d 'information de fopen et fclose
    ft = fopen("stat.txt","a"); // ouvre le fichier texte ou le creer

    fprintf(ft,"%02u/%s/%04u", timeinfo->tm_mday, NomMois[timeinfo->tm_mon], 1900 + timeinfo->tm_year);
    fprintf(ft," %02u:%02u:%02u;", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    fprintf(ft,"%d;",mode);
    //fprintf(ft,"%d",);
    fprintf(ft,"\n");
    fclose(ft);
}


void afficherInfo() // afficher les info dans la console
{
// cette fonction affiche le fichier statitique
    system("cat stat.txt");
}

void afficherfinInfo()
{
// cette fonction affiche les derniere ligne du fichier statitique
    system("tail stat.txt");
}

void trierinfo()
{

// cette fonction affiche combien de fois tous les mode ont etait lancer
    int modestatique=0, modedynamique=0, modeinteractif=0;
    char modelu;
    FILE* ft=NULL;
    char chaine[22];
    ft = fopen("stat.txt","r");
    while(fgets(chaine,22,ft) != NULL)// On lit ligne par ligne
    {
        printf("%s",chaine);
        modelu = chaine[20];
        if (modelu=='1')
        {
            modestatique++;
        }
        else if (modelu=='2')
        {
            modedynamique++;
        }
        else if (modelu=='3')
        {
            modeinteractif++;
        }
    }
    printf("Le mode statique a etait lancer %d fois\n", modestatique/2);
    printf("Le mode dynamique a etait lancer %d fois\n", modedynamique/2);
    printf("Le mode interactif a etait lancer %d fois\n", modeinteractif/2);

    fclose(ft);
}

void menustat()
{
    char menu='0';
    char choixmenustat;
    while (menu=='0')
    {
        choixmenustat = '0';
        printf("\n\n\n   Bienvenue dans le menu statistique du eXiasaver");
        printf("\n Pour lire le log en entier taper 1");
        printf("\n Pour lire les dix dernieres lignes du log taper 2");
        printf("\n Pour trier les infos qui se trouve dans le log taper 3");
        printf("\n Que voulez-vous faire ? :");
        fflush(stdin);
        scanf(" %c",&choixmenustat);

        if (choixmenustat=='1')
        {
            afficherInfo();
        }

        else if (choixmenustat=='2')
        {
            afficherfinInfo();
        }

        else if (choixmenustat=='3')
        {
            trierinfo();
        }

        else
        {
            printf ("Vous avec inserer un mauvais caractere\n");
        }

        menu=0;
        printf("\n Pour revenir au menu principal tapper 0, sinon tapper quelque chose d'autre pour quitter le programme :");
        fflush(stdin);
        scanf(" %c",&menu);
    }
}

