#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "igraci.h"
#include "utakmice.h"

extern Igrac* igraci;
extern int brojIgraca;
extern Utakmica utakmice[MAX_UTAKMICA];
extern int brojUtakmica;

typedef enum {
    PREGLED_IGRACA = 1,
    UPIS_IGRACA,
    PREGLED_UTAKMICA,
    UPIS_REZULTATA,
    SORTIRAJ_IGRACE,
    PRETRAZI_PO_PREZIMENU,
    PRETRAZI_PO_POZICIJI,
    IZBRISI_IGRACA,
    AZURIRAJ_POZICIJU,
    IZLAZ
} Opcija;

void prikaziIzbornik() {
    printf("\nIzbornik:\n");
    printf("1. Pregled igraca\n");
    printf("2. Upis novog igraca\n");
    printf("3. Pregled utakmica\n");
    printf("4. Upis rezultata utakmice\n");
    printf("5. Sortiranje igraca po broju dresa\n");
    printf("6. Pretraga igraca po prezimenu\n");
    printf("7. Pretraga igraca po poziciji\n");
    printf("8. Brisanje igraca\n");
    printf("9. Azuriranje pozicije igraca\n");
    printf("10. Izlaz\n");
    printf("Odaberite opciju: ");
}

int main() {
    ucitajIgraceIzDatoteke();
    ucitajUtakmiceIzDatoteke();

    int opcija;

    do {
        prikaziIzbornik();

        // Provjera unosa za opciju
        while (scanf("%d", &opcija) != 1) {
            printf("Greska! Molimo unesite ispravan broj.\n");
            while (getchar() != '\n'); // o?isti ulazni buffer
        }

        switch (opcija) {
        case PREGLED_IGRACA:
            prikaziIgrace();
            break;
        case UPIS_IGRACA:
            upisiIgraca();
            break;
        case PREGLED_UTAKMICA:
            pregledUtakmica();
            break;
        case UPIS_REZULTATA:
            upisRezultata();
            break;
        case SORTIRAJ_IGRACE:
            sortirajIgracePoBrojuDresa(igraci, brojIgraca);
            printf("Igraci su sortirani po broju dresa.\n");
            break;
        case PRETRAZI_PO_PREZIMENU:
            pretraziIgracePoPrezimenu();
            break;
        case PRETRAZI_PO_POZICIJI:
            pretraziIgracePoPoziciji();
            break;
        case IZBRISI_IGRACA:
            izbrisiIgraca();
            break;
        case AZURIRAJ_POZICIJU:
            azurirajPozicijuIgraca();
            break;
        case IZLAZ:
            oslobodiMemoriju();
            printf("Izlaz iz programa.\n");
            break;
        default:
            printf("Nepostojeca opcija. Pokusajte ponovo.\n");
            break;
        }
    } while (opcija != IZLAZ);

    return 0;
}
