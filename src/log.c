#include <stdio.h>
#include <string.h>  

void loglecture(int *month_ptr){

    char mois[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    char log_month[4];
    char trashchar[4];
    char file[] = "/var/log/apache2/access.log";
    int nblignes = 0;  
    FILE *fichier;
    char ch;

    fichier = fopen(file, "r");
    if (fichier == NULL) {
        printf("Impossible de l'ouvrir");
        return; 
    }
    else {
        do {
            ch = fgetc(fichier);
            if (ch == '\n'){
                nblignes += 1;
            }
            if (ch == '['){
                fgets(trashchar, 4, fichier);
                fgets(log_month, 4, fichier);
                for (int i = 0; i < 12; i++) {
                    if (!strcmp(log_month, mois[i])) {
                        month_ptr[i] += 1;
                    }
                }  
            }
        } while (ch != EOF);

    }
    fclose(fichier);
}

void startdate(char *startdate){
    char file[] = "/var/log/apache2/access.log";
    char ch;
    FILE *fichier;
    fichier = fopen(file, "r");
    if (fichier == NULL) {
        printf("Impossible de l'ouvrir");
        return; 
    }
    else {
        do {
            ch = fgetc(fichier);
            if (ch == '['){
                fgets(startdate, 12, fichier);
            }
        } while(ch != ']');
    }
    fclose(fichier);
}

