#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igraci.h"

Igrac* igraci = NULL;
int brojIgraca = 0;

void ucitajIgraceIzDatoteke() {
    FILE* file = fopen("igraci.txt", "r");
    if (file == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    fscanf(file, "%d", &brojIgraca);
    igraci = (Igrac*)malloc(brojIgraca * sizeof(Igrac));
    for (int i = 0; i < brojIgraca; i++) {
        fscanf(file, "%d %s %s %s", &igraci[i].brojDresa, igraci[i].ime, igraci[i].prezime, igraci[i].pozicija);
    }
    fclose(file);
}


void prikaziIgrace() {
    if (brojIgraca == 0) {
        printf("Nema igraca u evidenciji.\n");
        return; 
    }
    for (int i = 0; i < brojIgraca; i++) {
        printf("Dres: %d, Ime: %s, Prezime: %s, Pozicija: %s\n", igraci[i].brojDresa, igraci[i].ime, igraci[i].prezime, igraci[i].pozicija);
    }
}
void upisiIgraca() {
    igraci = realloc(igraci, (brojIgraca + 1) * sizeof(Igrac));
    if (!igraci) {
        perror("Greska pri alokaciji memorije");
        return;
    }

    Igrac* noviIgrac = &igraci[brojIgraca];

    printf("Unesite ime: ");
    scanf("%49s", noviIgrac->ime);
    printf("Unesite prezime: ");
    scanf("%49s", noviIgrac->prezime);
    printf("Unesite broj dresa: ");
    while (scanf("%d", &noviIgrac->brojDresa) != 1) {
        printf("Greska! Molimo unesite ispravan broj za broj dresa.\n");
        while (getchar() != '\n');
    }
    printf("Unesite poziciju igraca: ");
    scanf("%29s", noviIgrac->pozicija);
    brojIgraca++;

    FILE* file = fopen("igraci.txt", "wb+");
    if (!file) {
        perror("Greska pri otvaranju datoteke za spremanje igraca");
        return;
    }

    fprintf(file, "%d\n", brojIgraca);
    for (int i = 0; i < brojIgraca; i++) {
        fprintf(file, "%d %s %s %s\n", igraci[i].brojDresa, igraci[i].ime, igraci[i].prezime, igraci[i].pozicija);
    }
    fclose(file);

    printf("Igrac uspjesno dodan i spremljen u datoteku.\n");
}



void sortirajIgracePoBrojuDresa(Igrac* igraci, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (igraci[j].brojDresa > igraci[j + 1].brojDresa) {
                Igrac temp = igraci[j];
                igraci[j] = igraci[j + 1];
                igraci[j + 1] = temp;
            }
        }
    }
}


void pretraziIgracePoPrezimenu() {
    char prezime[50];
    printf("Unesite prezime za pretragu: ");
    scanf("%49s", prezime);
    for (int i = 0; i < brojIgraca; i++) {
        if (strcmp(igraci[i].prezime, prezime) == 0) {
            printf("Dres: %d, Ime: %s, Prezime: %s, Pozicija: %s\n", igraci[i].brojDresa, igraci[i].ime, igraci[i].prezime, igraci[i].pozicija);
        }
    }
}


void pretraziIgracePoPoziciji() {
    char pozicija[30];
    printf("Unesite poziciju za pretragu: ");
    scanf("%29s", pozicija);
    for (int i = 0; i < brojIgraca; i++) {
        if (strcmp(igraci[i].pozicija, pozicija) == 0) {
            printf("Dres: %d, Ime: %s, Prezime: %s, Pozicija: %s\n", igraci[i].brojDresa, igraci[i].ime, igraci[i].prezime, igraci[i].pozicija);
        }
    }
}


void izbrisiIgraca() {
    int dres;
    printf("Unesite broj dresa igraca za brisanje: ");
    while (scanf("%d", &dres) != 1) {
        printf("Greska! Molimo unesite ispravan broj.\n");
        while (getchar() != '\n');
    }

    int index = -1;
    for (int i = 0; i < brojIgraca; i++) {
        if (igraci[i].brojDresa == dres) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < brojIgraca - 1; i++) {
            igraci[i] = igraci[i + 1];
        }
        brojIgraca--;
        igraci = (Igrac*)realloc(igraci, brojIgraca * sizeof(Igrac));
        printf("Igrac obrisan.\n");

        FILE* file = fopen("igraci.txt", "wb+");
        if (!file) {
            perror("Greska pri otvaranju datoteke za spremanje igraca");
            return;
        }

        fprintf(file, "%d\n", brojIgraca);
        for (int i = 0; i < brojIgraca; i++) {
            fprintf(file, "%d %s %s %s\n", igraci[i].brojDresa, igraci[i].ime, igraci[i].prezime, igraci[i].pozicija);
        }
        fclose(file);
    }
    else {
        printf("Igrac nije pronadjen.\n");
    }
}
void azurirajPozicijuIgraca() {
    int dres;
    char novaPozicija[30];

    printf("Unesite broj dresa igraca kojem zelite promijeniti poziciju: ");
    while (scanf("%d", &dres) != 1) {
        printf("Greska! Molimo unesite ispravan broj.\n");
        while (getchar() != '\n');
    }

    printf("Unesite novu poziciju: ");
    scanf("%29s", novaPozicija);

    int index = -1;
    for (int i = 0; i < brojIgraca; i++) {
        if (igraci[i].brojDresa == dres) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        strncpy(igraci[index].pozicija, novaPozicija, sizeof(igraci[index].pozicija) - 1);
        igraci[index].pozicija[sizeof(igraci[index].pozicija) - 1] = '\0';

        FILE* file = fopen("igraci.txt", "wb+");
        if (!file) {
            perror("Greska pri otvaranju datoteke za spremanje igraca");
            return;
        }

        fprintf(file, "%d\n", brojIgraca);
        for (int i = 0; i < brojIgraca; i++) {
            fprintf(file, "%d %s %s %s\n", igraci[i].brojDresa, igraci[i].ime, igraci[i].prezime, igraci[i].pozicija);
        }
        fclose(file);

        printf("Pozicija igraca uspjesno azurirana.\n");
    }
    else {
        printf("Igrac nije pronadjen.\n");
    }
}
void oslobodiMemoriju() {
    free(igraci);
}
