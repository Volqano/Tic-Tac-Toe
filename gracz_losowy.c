#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "gracz_losowy.h"

void losowy_ruch(int n, char znak, char tablica[n][n]) {
    int ruch1, ruch2;
    srand(time(NULL));
    while (1) {
        ruch1 = rand() % n;
        ruch2 = rand() % n;
        if (tablica[ruch1][ruch2] == ' ') {
            tablica[ruch1][ruch2] = znak;
            break;
        }
    }
    tablica[ruch1][ruch2] = znak;
}