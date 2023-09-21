#ifndef INIZIALIZZARE_PARTITA_H_
#define INIZIALIZZARE_PARTITA_H_
#include "partita.h"

void inizializzare_giocatori (partita *partita_attuale, int * sale);
void inserire_stringa (int dimensione_minima_stringa, int dimensione_massima_stringa, char nome_da_inserire [], int * sale);
int calcolare_lunghezza_stringa (const char stringa []);
void richiedere_stringa (const char file_interfaccia [], int dimensione_minima_stringa, int dimensione_massima_stringa, char nome_da_inserire [], int * sale);

#endif /* INIZIALIZZARE_PARTITA_H_ */
