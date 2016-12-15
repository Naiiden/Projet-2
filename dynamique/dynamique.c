#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>


char bytes[9][28];
char deuxPoints[28];
int delay = 10;

void my_delay(int i) 
{
        clock_t start,end;
        start=clock();
        while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}



/**
Centre l'image verticalement en fonction de la taille de la console et de l'image
@param int hauteur : hauteur de l'image
**/
void centrerImageVertical(int hauteur) {
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w); //fonction systeme qui récupère la taille de la console
	int n;
	for (n=0; n<(w.ws_row-hauteur)/2; n++){
			printf("\n");
		}
	
}



void centrerImageHorizontal(int largeur) {

	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	int n;
	for (n=0; n<(w.ws_col-largeur)/2; n++){
			putchar(' ');
		}
		
		
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
	
	
	//printf("%s:%s:%s\n",s_heure,s_minute,s_seconde);
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
	
	centrerImageVertical(7);
	
	for(i=0;i<7;i++) {
	
	centrerImageHorizontal(39);
	
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
		//printf("%d",delayy);
        system("clear");
        int valeur = 0;
        afficherHeure();
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("\n");
	centrerImageHorizontal(49);
       printf("Actualisation de l'heure dans %d seconde(s) : ", delay);
		while(valeur < delay)
        {
          printf(".");
        my_delay(1);
					
            		valeur ++;
    	}
		if (valeur =0, valeur <delay, valeur++)
		{
			printf(".");
			my_delay(1);
		}
//	setvbuf(stdout, NULL, _IONLF, 0);
	}
}




int main(int argc, char *argv[]) {
	
	char taille[5];
	
	int ligne = 1;
	int image = 0;
	int nombreCaracteres;
	char caractereLu;
	char cheminFichier[128] = "";
	int i;
	int j;
	
	
	// OUVERTURE DES 2 POINTS
	FILE* deuxPts = NULL;
	FILE* fichier = NULL;
	
	system("clear");
	
	
	/*if (argc==2)
    {
		
		
		strcat(cheminFichier,"images/");
		strcat(cheminFichier,argv[1]);
		strcat(cheminFichier,".pbm");
		//strcat(heureTotal,":");
		//strcat(heureTotal,s_seconde);
		//snprintf(cheminFichier, sizeof cheminFichier, "images/%c.pbm", argv[1]);
		fichier = fopen(cheminFichier, "r+");
	else {
			
	}*/
	
		
	if (argc==2)
    {
		
		delay=atoi(argv[1]); 
    } else {
		delay=10;
	}
					
		
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
		
		for(i=0;i<28;i++){
			printf("%c",bytes[9][i]);
		}
		
		//fclose(fichier);
		ligne = 1;
		
		
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
		
		/*system("/bin/stty raw");
		getchar();
		system("/bin/stty cooked");*/
	//}
	
	system("clear");
	return 0;
}
