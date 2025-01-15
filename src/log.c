#include <stdio.h>
#include <string.h>  

// Function to count the number of lines and occurrences of each month in the log file
void count_lines_and_months() {
    char file[] = "/var/log/apache2/access.log";
    char ch;
    FILE *fichier;
    int nblignes = 0;
    char log_month[4];
    char trashchar[4];
    int month_ptr[12] = {0};
    char *mois[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    fichier = fopen(file, "r");
    if (fichier == NULL) {
        printf("Impossible de l'ouvrir");
        return; 
    }
    else {
        do {
            ch = fgetc(fichier);
            if (ch == '\n'){
                nblignes += 1; // Count the number of lines
            }
            if (ch == '['){
                fgets(trashchar, 4, fichier); // Skip the first 4 characters
                fgets(log_month, 4, fichier); // Read the month
                for (int i = 0; i < 12; i++) {
                    if (!strcmp(log_month, mois[i])) {
                        month_ptr[i] += 1; // Count the occurrences of each month
                    }
                }  
            }
        } while (ch != EOF);
    }
    fclose(fichier);
}

// Function to get the start date from the log file
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
                fgets(startdate, 12, fichier); // Read the start date
            }
        } while(ch != ']');
    }
    fclose(fichier);
}
