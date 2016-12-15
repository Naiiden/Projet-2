#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>


char bytes[9][28];
char deuxPoints[28];

void my_delay(int i) //fonction pour faire une pause de x secondes
{
        clock_t start,end;
        start=clock();
        while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}

int recuperationHeure()
{
    /*int heure;
    int minute;*/

    // On lit l'heure courante
    time_t now = time(NULL);

    //On la convertit en heure local
    struct tm tm_now = *localtime(&now);

    //On creer une chaine HH:MM
    char s_heure[sizeof "HH"];
    char s_minute[sizeof "MM"];
    char s_seconde[sizeof "SS"];

    //strftime(s_now, sizeof s_now, "%H:%M", &tm_now);

    strftime(s_heure, sizeof s_heure, "%H", &tm_now);
    strftime(s_minute, sizeof s_minute, "%M", &tm_now);
    strftime(s_seconde, sizeof s_seconde, "%S", &tm_now);

    printf("Il est actuellement %s h:", s_heure);
    printf("%s m:", s_minute);
    printf("%s s\n", s_seconde);

    //On affiche le resultat
    //printf("%s\n", s_now);

}





int afficherHeure() {
	
	
	time_t now = time(NULL);

    //On la convertit en heure local
    struct tm tm_now = *localtime(&now);

    //On creer une chaine HH:MM
    char s_heure[sizeof "HH"];
    char s_minute[sizeof "MM"];
    char s_seconde[sizeof "SS"];

    //strftime(s_now, sizeof s_now, "%H:%M", &tm_now);

    strftime(s_heure, sizeof s_heure, "%H", &tm_now);
    strftime(s_minute, sizeof s_minute, "%M", &tm_now);
    strftime(s_seconde, sizeof s_seconde, "%S", &tm_now);
	
	
	printf("%s:%s:%s\n",s_heure,s_minute,s_seconde);
	char heureTotal[8];
	char caractere;
	int i, j, k, depart;
	depart=0;
	
	int chiffre=0;
	strcat(heureTotal,s_heure);
	strcat(heureTotal,":");
	strcat(heureTotal,s_minute);
	strcat(heureTotal,":");
	strcat(heureTotal,s_seconde);
	
	for(i=0;i<7;i++) {
		for(j=0;j<8;j++) {
			
			
			if (heureTotal[chiffre]==':') {
				for(k=0;k<4;k++) {
					
					caractere = deuxPoints[k+depart];
					
					if (caractere=='0') {
						printf(" ");
					}
					if (caractere=='1') {
						printf("\xe2\x96\x86");
					}
				}
			}
			else {
				for(k=0;k<4;k++) {
					caractere = bytes[heureTotal[chiffre] - '0'][k+depart];
					
					if (caractere=='0') {
						printf(" ");
					}
					if (caractere=='1') {
						printf("\xe2\x96\x86");
					}
				}
				
			
			}
			chiffre++;
			printf(" ");
		
		}
		printf("\n");
		chiffre=0;
		depart = depart+4;
	}
}



int compteur()

{   while(1)
	{
        system("clear");
        int valeur = 0;
        afficherHeure();
	setvbuf(stdout, NULL, _IONBF, 0);
        printf("Actualisation de l'heure dans quelques secondes : ");
		while(valeur < 10)
        	{
            		printf(".");
            		valeur ++;
            		my_delay(1);
    		}
		/* if (valeur =0, valeur < 10, valeur++)
		{
			printf(".");
			my_delay(1);
		}*/
//	setvbuf(stdout, NULL, _IONLF, 0);
	}
}


void centrerImageVertical(int largeur, int hauteur) {
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	int n;
	for (n=0; n<(w.ws_row-hauteur)/2; n++){
			printf("\n");
		}
	
}
void centrerImage(int largeur, int hauteur) {

	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	int n;
	for (n=0; n<(w.ws_col-largeur)/2; n++){
			putchar(' ');
		}
		
		
}

int main(int argc, char *argv[]) {
	
	char taille[5];
	
	int ligne = 1;
	int image = 0;
	int nombreCaracteres;
	char caractereLu;
	char cheminFichier[128] = "";
	int imageSize = 0;
	char separateur[1] = " ";
	char * pch;
	int i;
	int j;
	
	
	// OUVERTURE DES 2 POINTS
	FILE* deuxPts = NULL;
	FILE* fichier = NULL;
	
	system("clear");
	
	
	
	
		
		
					
		
		for (i=0; i<10; i++) {
		
			snprintf(cheminFichier, sizeof cheminFichier, "heure/%d.pbm", i);
			fichier = fopen(cheminFichier, "r+");
			
			
			if (fichier != NULL) {
					
					
				while(ligne < 4 && caractereLu != EOF){		//On passe les 3 premières lignes (ne nous interressent pas) ligne<4
					
					caractereLu = fgetc(fichier);
					if (caractereLu == '\n'){
						ligne++;
					}
				}
				
					
				for (j=0; j<28; j++) {
						
						bytes[i][j] = fgetc(fichier);
						
						if(bytes[i][j] == '\n') { //On annule un retour à la ligne du fichier s'il y en a un
							j=j-1;
						}
						if(bytes[i][j] == ' ') { //On annule un retour à la ligne du fichier s'il y en a un
							j=j-1;
						}
					}
					
					
				}
				
			ligne = 1;
			rewind(fichier);
			fclose(fichier);
			
		}
		

		
		deuxPts = fopen("heure/2pts.pbm", "r+");
	if (deuxPts != NULL) {
					
					
				while(ligne < 4 && caractereLu != EOF){		//On passe les 3 premières lignes (ne nous interressent pas) ligne<4
					
					caractereLu = fgetc(deuxPts);
					if (caractereLu == '\n'){
						ligne++;
					}
				}
				
						
				for (i=0; i<28; i++) {
						deuxPoints[i] = fgetc(deuxPts);
						if(deuxPoints[i] == '\n') { //On annule un retour à la ligne du fichier s'il y en a un
							i=i-1;
						}
						if(deuxPoints[i] == ' ') { //On annule un retour à la ligne du fichier s'il y en a un
							i=i-1;
						}
					}
					
						
				 //On ferme le fichier
					//printf("salut %c\n", bytes[i][j]);
				}
			
			rewind(deuxPts);
			fclose(deuxPts);
			ligne=1;
		
		
		
			
		//afficherHeure();
		compteur();
		
	system("/bin/stty raw");
		getchar();
		system("/bin/stty cooked");
	//}
	
	system("clear");
	return 0;
}
