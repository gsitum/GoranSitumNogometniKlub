#ifndef UTAKMICE_H
#define UTAKMICE_H

#define MAX_UTAKMICA 100

typedef struct {
    int id;
    char tim1[50];
    char tim2[50];
    int rezultat1;
    int rezultat2;
} Utakmica;

extern Utakmica utakmice[MAX_UTAKMICA];
extern int brojUtakmica;

void ucitajUtakmiceIzDatoteke();
void pregledUtakmica();
void upisRezultata();
void spremiUtakmiceUDatoteku();

#endif
