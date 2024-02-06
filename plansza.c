#include <stdio.h>
#include "plansza.h"

void wypisz_plansze(int n, char tablica[n][n]) {
    //funkcja ktora printuje aktualny stan planszy
    for (int j = 0; j < n; j++) {
            printf("----");
        }
    printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            printf(" %c |", tablica[i][j]);
        }
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("----");
        }
        printf("-");
        printf("\n");
    }
    printf("\n");
}

int zwyciezca(int n, char znak, char tablica[n][n]) {
    int k = 0;
    int max = 5;
    int streak = 0;
    if(n < 5){
        max = n;
    }
    //SPRAWDZA OD LEWEJ DO PRAWEJ
    for (int i = 0; i < n; i++) {
        for(int j = 0; j<n; j++) {
            streak = 0; //sprawdza ile znakow z rzedu ma x/o
            k = 0;
            while(tablica[i + k][j] == znak && i + k < n) {
                streak++;
                k++;
            }
            if (streak >= max) { //sprawdza czy streak jest wiekszy lub rowny od potrzebnej ilosci znaku z rzedu
                return 1;
            }
        }
    }
    //SPRAWDZA OD GORY DO DOLU
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            streak = 0; //sprawdza ile znakow z rzedu ma x/o
            k = 0;
            while(tablica[i][j + k] == znak && j + k < n) {
                streak++;
                k++;
            }
            if (streak >= max) { //sprawdza czy streak jest wiekszy lub rowny od potrzebnej ilosci znaku z rzedu
                return 1;
            }
        }
    }
    //SPRAWDZA OD LEWEJ GORY DO PRAWEGO DOLU
    for (int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            streak = 0;
            k = 0;
            while(tablica[i + k][j + k] == znak && j + k < n && i + k < n){
                streak++;
                k++;
            }
            if (streak >= max){ //sprawdza czy streak jest wiekszy lub rowny od potrzebnej ilosci znaku z rzedu
                return 1;
            }
        }
    }
    //SPRAWDZA OD LEWEGO DOLU DO PRAWEJ GORY
    for (int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            streak = 0;
            k = 0;
            while(tablica[i + k][j - k] == znak && j - k < n && i + k < n){
                streak++;
                k++;
                if ((j - k) < 0) {
                    break;
                }
            }
            if (streak >= max){ //sprawdza czy streak jest wiekszy lub rowny od potrzebnej ilosci znaku z rzedu
                return 1;
            }
        }
    }
    return 0;
}    