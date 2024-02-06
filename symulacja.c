#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include "plansza.h"
#include "gracz_ze_strategia.h"
#include "gracz_losowy.h"
//gcc -Wextra -Werror -o symulacja symulacja.c plansza.c gracz_ze_strategia.c gracz_losowy.c
int main(int argc, char *argv[])
{
    int n = 4;
    char x;
    char strategia, losowy; //strategia - znak gracza grajacego strategicznie || losowy - znak gracza grajacego losowo
    if (argc > 2) {
        printf("Wprowadz poprawna liczbę argumentow");
        return 1;
    }
    if (argc > 1) {
        n = atoi(argv[1]);
        if (n <= 1 || n > 40) {
            printf("Wprowadz poprawny argument");
            return 1;
        }
    }
    char plansza[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            plansza[i][j] = ' ';
        }
    }
    wypisz_plansze(n, plansza);
    srand(time(NULL));
    int ruch = rand() % 2;
    if (ruch == 0) {
        losowy = 'X';
        strategia = 'O';
    } else {
        strategia = 'X';
        losowy = 'O';
    }
    int max_ruchow = pow(n, 2);
    if (losowy == 'X') {  //ZACZYNA GRACZ LOSOWY
        printf("----ZACZYNA GRACZ LOSOWY----\n");
        while (max_ruchow >= 1) {
            x = getchar();
            losowy_ruch(n, losowy, plansza);
            wypisz_plansze(n, plansza);
            if (zwyciezca(n, losowy, plansza) == 1) {
                printf("ZWYCIEZA GRACZ LOSOWY!");
                return 0;
            }
            max_ruchow--;
            if (max_ruchow == 0) {
                break;
            }
            x = getchar();
            strategiczny_ruch(n, strategia, plansza);
            wypisz_plansze(n, plansza);
            if (zwyciezca(n, strategia, plansza) == 1) {
                printf("ZWYCIEZA GRACZ ZE STRATEGIA!");
                return 0;
            }
            max_ruchow--;
        }
    } else {  //ZACZYNA GRACZ ZE STRATEGIA
        printf("----ZACZYNA GRACZ ZE STRATEGIA----\n");
        while (max_ruchow >= 1) {
            x = getchar();
            strategiczny_ruch(n, strategia, plansza);
            wypisz_plansze(n, plansza);
            if (zwyciezca(n, strategia, plansza) == 1) {
                printf("ZWYCIEZA GRACZ ZE STRATEGIA!");
                return 0;
            }
            max_ruchow--;
            if (max_ruchow == 0) {
                break;
            }
            x = getchar();
            losowy_ruch(n, losowy, plansza);
            wypisz_plansze(n, plansza);
            if (zwyciezca(n, losowy, plansza) == 1) {
                printf("ZWYCIEZA GRACZ LOSOWY!");
                return 0;
            }
            max_ruchow--;
        }
    }
    printf("Gra zakończyła się remisem");
    return 0;
}