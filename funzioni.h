#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED

    /* Librerie */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    /* Prototipi */
void clear_screen ();
void map_null (char mappa[3][3]);
void draw_map (char mappa[3][3]);
void insert_player (char mappa[3][3]);
void insert_pc (char mappa[3][3]);
int check_winner(char mappa[3][3]);

//Variabili globali
int turn;

#endif // FUNZIONI_H_INCLUDED
