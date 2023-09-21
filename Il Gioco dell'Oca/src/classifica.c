#include <stdio.h>
#include "classifica.h"
#include "costanti.h"



int aggiornare_classifica_top_10 (vincitore vincitore_partita) {
    vincitore vincitori [NUMERO_MASSIMO_CLASSIFICATI];
    caricare_classifica (vincitori);
    int posizione_classificato = -1;
    int inserito = FALSO;
    float rateo_vincitore_partita = (float) leggere_lanci_vincitore (vincitore_partita) / (float) leggere_lunghezza_percorso_vincitore (vincitore_partita);
    float rateo_classificato;
    scrivere_punteggio (&vincitore_partita, rateo_vincitore_partita);
    int indice_vincitori = 0;
    while (indice_vincitori < NUMERO_MASSIMO_CLASSIFICATI) {
        if ( leggere_carattere_nome_vincitore (vincitori [indice_vincitori], 0) != FINE_STRINGA ) {
            rateo_classificato = leggere_punteggio (vincitori [indice_vincitori]);
            if ( (rateo_vincitore_partita < rateo_classificato) && (inserito != VERO) ) {
                spostamento_destra_vincitori (vincitori, indice_vincitori, vincitore_partita);
                posizione_classificato = indice_vincitori + 1;
                inserito = VERO;
            }
        } else if (inserito != VERO) {
            vincitori [indice_vincitori] = vincitore_partita;
            posizione_classificato = indice_vincitori + 1;
            inserito = VERO;
        }
        indice_vincitori = indice_vincitori + 1;
    }
    scrivere_classifica (vincitori);
    return posizione_classificato;
}



void spostamento_destra_vincitori (vincitore vincitori[], int posizione_inserimento, vincitore vincitore_partita) {
    int indice_vincitori = NUMERO_MASSIMO_CLASSIFICATI - 1;
    while (indice_vincitori >= posizione_inserimento) {
        vincitori [indice_vincitori] = vincitori [indice_vincitori - 1];
        indice_vincitori = indice_vincitori - 1;
    }
    vincitori [posizione_inserimento] = vincitore_partita;
    return;
}



void caricare_classifica (vincitore vincitori[]) {
    FILE * file_classifica = fopen (FILE_CLASSIFICA_TOP_10, "rb");
    if (file_classifica != NULL) {
        fread (vincitori, sizeof (vincitore), NUMERO_MASSIMO_CLASSIFICATI, file_classifica);
        fclose (file_classifica);
    } 
    else {
        creare_classifica_vuota (vincitori);
        scrivere_classifica (vincitori);
    }
    return;
}



void scrivere_classifica (vincitore elenco_vincitori []) {
    FILE *file_classifica = fopen (FILE_CLASSIFICA_TOP_10, "wb");
    fwrite (elenco_vincitori, sizeof (vincitore), NUMERO_MASSIMO_CLASSIFICATI, file_classifica);
    fclose (file_classifica);
    return;
}



void creare_classifica_vuota (vincitore vincitori []) {
    vincitore vincitore_azzerato;
    scrivere_carattere_nome_vincitore (&vincitore_azzerato, 0, FINE_STRINGA);
    scrivere_pedina_vincitore (&vincitore_azzerato, FINE_STRINGA);
    scrivere_lanci_vincitore (&vincitore_azzerato, 0);
    scrivere_lunghezza_percorso_vincitore (&vincitore_azzerato, 0);
    scrivere_punteggio (&vincitore_azzerato, 0.0);
    int indice_vincitori = 0;
    while (indice_vincitori < NUMERO_MASSIMO_CLASSIFICATI) {
        vincitori [indice_vincitori] = vincitore_azzerato;
        indice_vincitori = indice_vincitori + 1;
    }
}
