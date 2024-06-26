#define _CRT_SECURE_NO_WARNINGS
#ifndef IGRACI_H
#define IGRACI_H

#define MAX_IGRACA 100

typedef struct {
    int brojDresa;
    char ime[50];
    char prezime[50];
    char pozicija[30];
} Igrac;

extern Igrac* igraci;
extern int brojIgraca;

void ucitajIgraceIzDatoteke();
void prikaziIgrace();
void upisiIgraca();
void sortirajIgracePoBrojuDresa(Igrac* igraci, int n);
void pretraziIgracePoPrezimenu();
void pretraziIgracePoPoziciji();
void izbrisiIgraca();
void oslobodiMemoriju();
void azurirajIgraca();
#endif
