#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "utakmice.h"

Utakmica utakmice[MAX_UTAKMICA];
int brojUtakmica = 0;

void ucitajUtakmiceIzDatoteke() {
    FILE* file = fopen("utakmice.txt", "r");
    if (file == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    fscanf(file, "%d", &brojUtakmica);
    for (int i = 0; i < brojUtakmica; i++) {
        fscanf(file, "%d %s %s %d %d", &utakmice[i].id, utakmice[i].tim1, utakmice[i].tim2, &utakmice[i].rezultat1, &utakmice[i].rezultat2);
    }
    fclose(file);
}

void pregledUtakmica() {
    for (int i = 0; i < brojUtakmica; i++) {
        printf("ID: %d, Tim1: %s, Tim2: %s, Rezultat: %d-%d\n", utakmice[i].id, utakmice[i].tim1, utakmice[i].tim2, utakmice[i].rezultat1, utakmice[i].rezultat2);
    }
}

void upisRezultata() {
    if (brojUtakmica >= MAX_UTAKMICA) {
        printf("Dosegnut maksimalan broj utakmica.\n");
        return;
    }

    Utakmica novaUtakmica;
    printf("Unesite ID utakmice: ");
    while (scanf("%d", &novaUtakmica.id) != 1) {
        printf("Greska! Molimo unesite ispravan broj za ID.\n");
        while (getchar() != '\n');
    }
    printf("Unesite ime prvog tima: ");
    scanf("%49s", novaUtakmica.tim1);
    printf("Unesite ime drugog tima: ");
    scanf("%49s", novaUtakmica.tim2);
    printf("Unesite rezultat prvog tima: ");
    while (scanf("%d", &novaUtakmica.rezultat1) != 1) {
        printf("Greska! Molimo unesite ispravan broj za rezultat prvog tima.\n");
        while (getchar() != '\n');
    }
    printf("Unesite rezultat drugog tima: ");
    while (scanf("%d", &novaUtakmica.rezultat2) != 1) {
        printf("Greska! Molimo unesite ispravan broj za rezultat drugog tima.\n");
        while (getchar() != '\n');
    }

    utakmice[brojUtakmica++] = novaUtakmica;
    spremiUtakmiceUDatoteku();
    printf("Utakmica uspjesno dodana i spremljena u datoteku.\n");
}

void spremiUtakmiceUDatoteku() {
    FILE* file = fopen("utakmice.txt", "wb+");
    if (!file) {
        perror("Greska pri otvaranju datoteke za spremanje utakmica");
        return;
    }

    fprintf(file, "%d\n", brojUtakmica);
    for (int i = 0; i < brojUtakmica; i++) {
        fprintf(file, "%d %s %s %d %d\n", utakmice[i].id, utakmice[i].tim1, utakmice[i].tim2, utakmice[i].rezultat1, utakmice[i].rezultat2);
    }
    fclose(file);
}
