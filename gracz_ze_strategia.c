#include <stdio.h>
#include "gracz_ze_strategia.h"

void strategiczny_ruch(int n, char znak, char tablica[n][n]) {
    int exit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tablica[i][j] == ' ') {
                tablica[i][j] = znak;
                exit = 1;
                break;
            }
        }
        if (exit == 1) {
            break;
        }
    }
}