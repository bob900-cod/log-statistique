#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/libgraphique.h"
#include "log.h"

void versiongraphic(){
    int mois_connections[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    char mois[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char start_date[16] = "";
    startdate(start_date);
    const int WIDTH = 700;
    const int HEIGHT = 600;
    const int RECT_WIDTH = 40;
    const int CONPIX = 20;
    const int RECT_SPACING = 10;
    const int RECT_BORDER = 1;
    char taux_con[6];
    float taux_con_float = 0;
    float total_con = 0.0;
    char total_con_str[64];
    int touche;
    int rect_height;
    Couleur bg = fabrique_couleur(202,52,52);
    Couleur rect_color = fabrique_couleur(0,0,0);
    Point coin;

    loglecture(mois_connections);
    ouvrir_fenetre(WIDTH, HEIGHT);
    coin.x = 0;
    coin.y = 0;
    dessiner_rectangle(coin, WIDTH, HEIGHT, bg);
    for (int i = 0; i < 12; i++) {
	total_con += mois_connections[i];
    }
    for (int i = 0; i < 12; i++) {
    	taux_con_float = (mois_connections[i]/total_con) * 100.0;
    	sprintf(taux_con, "%.1f", taux_con_float);
	rect_height = taux_con_float*CONPIX;
        coin.x = i*(RECT_WIDTH+RECT_SPACING) + 55;
	coin.y = HEIGHT - 50 - rect_height;
        dessiner_rectangle(coin, RECT_WIDTH, rect_height, rect_color);
	coin.x += RECT_BORDER;
	coin.y += RECT_BORDER;
	dessiner_rectangle(coin, RECT_WIDTH-(RECT_BORDER*2), rect_height-(RECT_BORDER*2), bg);
	coin.x += 10;
	coin.y = HEIGHT - 40;
	afficher_texte(mois[i], 12, coin, rect_color);
	coin.x -= 3;
	coin.y -= (rect_height + 28);
	afficher_texte(taux_con, 12, coin, rect_color);
    }
    coin.x = 50;
    coin.y = 50;
    sprintf(total_con_str, "Depuis le %s, nous avons enregistre %0.f connexions.",start_date, total_con);
    afficher_texte(total_con_str, 18, coin, rect_color);
    actualiser();
    while (touche != SDLK_ESCAPE){
        touche = attendre_touche();
    }
    fermer_fenetre();
}

void versiontexte(){
    int mois_connections[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    float totcon = 0.0;
    char mois[12][12] = {"   Janvier", "   Fevrier", "      Mars", "     Avril", "       Mai", "      Juin", "   Juillet", "      Aout", " Septembre", "   Octobre", "  Novembre", "  Decembre"};
    char start_date[16] = "";
    startdate(start_date);
    float taux;
    loglecture(mois_connections);

    for(int i = 0; i < 12; i++){
        totcon += mois_connections[i];
    }

    printf("Depuis le %s on a enregistre %.0f connexions.\n", start_date, totcon);

    for(int i = 0; i < 12; i++){
        taux = mois_connections[i]*100/totcon;
        printf("%s : %.1f%%\n", mois[i], taux);
    }
    printf("\n");
}

void site(){
    int mois_connections[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    float height;
    float totcon = 0.0;
    float taux;
    int spacetop;
    char start_date[16] = "";
    startdate(start_date);
    loglecture(mois_connections);
    for(int i = 0; i < 12; i++){
        totcon += mois_connections[i];
    }
    printf("Content-type: text/html\n\n");
    printf("<!DOCTYPE html\n");
    printf("<head>\n<title>Statistiques serveur apache2 en pourcentage </title>\n</head>");
    printf("<body style=\"background-color: #ca3434; color:white;font-family:'Arial', 'sans-serif'\">\n");
    printf("Depuis le %s on a enregistr&eacute; %.0f connexions.<br/>\n", start_date, totcon);
    printf("<div style=\"display:flex;margin-top: 50px;\">\n");
    for(int i = 0; i < 12; i++){
        taux = mois_connections[i]*100/totcon;
        height = taux*10;
        spacetop = 200-height;
        if(height >= 25){
            printf("    <div style=\"margin-left:10px; margin-top:%d; height:%.0fpx; width: 30px; background-color:white; border:1px solid white;text-align: center; padding-top: 5px; position: relative;\">\n", spacetop, (height-5));
            printf("        <div style=\"position: absolute; top: -20px; left: 50%%; transform: translateX(-50%%);\">%.1f</div>\n", taux); 
            printf("    </div>\n");
        } else {
            printf("    <div style=\"margin-left:10px; margin-top:%d; height:%.0fpx; width: 30px; background-color:white; border: 1px solid white\">\n", spacetop, height);
            printf("        <div style=\"position: absolute; top: -20px; left: 50%%; transform: translateX(-50%%);\">%.1f</div>\n", taux);  
            printf("    </div>\n");
        }
    }
    printf("</div>\n");
    printf("    </html>\n</body>\n\n");   
}

int main(int argc, char *argv[]){
    if(argc >= 2){
        if(strcmp("-txt", argv[1]) == 0){
            versiontexte();
        } else if(strcmp("-gr", argv[1]) == 0){
            versiongraphic();
        }
    } else {
        site();
    }
    return EXIT_SUCCESS;
}

