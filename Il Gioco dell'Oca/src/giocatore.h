/*
 * giocatore.h
 *
 */

#ifndef GIOCATORE_H_
#define GIOCATORE_H_

#include "costanti.h"

typedef struct
{
    char nome_giocatore [DIMENSIONE_MASSIMA_NOME_GIOCATORE + 1];
    int posizione_giocatore;
    char pedina_giocatore;
    int lanci_effettuati;
    int autorizzazione;

}giocatore;

void scrivere_carattere_nome_giocatore (giocatore* giocatore_attuale, int posizione, char simbolo);
char leggere_carattere_nome_giocatore (giocatore giocatore_attuale, int posizione);
void scrivere_posizione_giocatore (giocatore* giocatore_attuale, int posizione);
int leggere_posizione_giocatore (giocatore giocatore_attuale);
void scrivere_pedina_giocatore (giocatore* giocatore_attuale, char pedina);
char leggere_pedina_giocatore (giocatore giocatore_attuale);
void scrivere_lanci_effettuati (giocatore* giocatore_attuale, int lanci);
int leggere_lanci_effettuati (giocatore giocatore_attuale);
void scrivere_autorizzazione (giocatore* giocatore_attuale, int autorizzazione_da_inserire);
int leggere_autorizzazione (giocatore giocatore_attuale);
void scrivere_nome_giocatore (giocatore* giocatore_attuale, char nome_da_inserire []);
void leggere_nome_giocatore (giocatore giocatore_attuale, char nome_letto []);

#endif /* GIOCATORE_H_ */
