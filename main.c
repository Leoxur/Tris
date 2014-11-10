//#include "filetto.h"
#include <stdio.h>
#include <stdlib.h>
#define PLAYER 2
#define PC 1

int main ();
void Draw_map ();  // Creazione griglia tramite matrice
void Map_init ();  // Inizializzo la matrice
void StartGame (); // Disegna la mappa, controlla chi ha vinto e switcha i turni
void pc_winner ();
void player_winner ();
void Insert_player ();
int Insert_rand ();
void EndGame ();
void set_number ();

char mappa[2][2]; // Mappa filetto
int turno;        // 0 = Turno Giocatore | 1 = Turno PC
int lose = -1;    // Indica se la partita è terminata
char *Player_name [] = {"Bobby"}; // printf ("*P %s\n", *P_name);
int choice = 0;

int main (){

    set_number();
    Draw_map();
    // Map_init();
    StartGame();

return 0;
}

// Creazione griglia tramite matrice
void Draw_map (){

    int i=0;
    int j=0;
        for( j=0 ; j<=2 ; j++){
            //system("cls");
            printf("\n\t\t-------------\n");
            printf("\t\t| ");
                for( i=0 ; i<=2 ; i++){
                    mappa[j][i] = 0;
                    printf("%d | ", mappa[j][i]);
                }
        }
    printf("\n\t\t-------------\n");
}

// Inizializzo la matrice
void Map_init (){

    int i=0;
    int j=0;
    for( j=0 ; j<=2 ; j++)
        for( i=0 ; i<=2 ; i++)
           mappa[i][j] = 0;
}

//Disegna la mappa, controlla chi ha vinto e switcha i turni
void StartGame (){

    pc_winner ();
    player_winner ();

  /*  if (turno == 0)
        Insert_player ();
        else if (turno == 1)
            Insert_rand ();*/
}

void player_winner(){

    int i=0;
    int a, b, c;

    //Orizzontale
    for( i=0 ; i<=2 ; i++)
        for (a=0, b=1, c=2; c<2 ; a++, b++, c++){
            if (mappa[i][a]==2 && mappa[i][b]==2 && mappa[i][c]==2){
                printf ("\n\n %s WINNER \n", *Player_name);
                system ("cls");
                EndGame ();
            }
        }

    //Verticale
    for( i=0 ; i<=2 ; i++)
        for (a=0, b=1, c=2; c<2 ; a++, b++, c++){
            if (mappa[a][i]==2 && mappa[b][i]==2 && mappa[b][i]==2){
                printf ("\n\n %s WINNER \n", *Player_name);
                system ("cls");
                EndGame ();
            }
        }

    //Diagonale_Principale
    i=0;
    for (a=0, b=1, c=2; c<2 ; a++, b++, c++){
        if (mappa[i][a]==2 && mappa[i+1][b]==2 && mappa[i+2][c]==2){
            printf ("\n\n %s WINNER \n", *Player_name);
            system ("cls");
            EndGame ();
        }
    }

    //Diagonale_Secondaria
    i=0;
    for (a=2, b=1, c=0; c<2 ; a++, b++, c++){
        if (mappa[i][a]==2 && mappa[i-1][b]==2 && mappa[i-2][c]==2){
            printf ("\n\n %s WINNER \n", *Player_name);
            system ("cls");
            EndGame ();
        }
    }

}


void pc_winner (){

    int i=0;
    int a, b, c;

    //Orizzontale
    for( i=0 ; i<=2 ; i++)
        for (a=0, b=1, c=2; c<2 ; a++, b++, c++){
            if (mappa[i][a]==1 && mappa[i][b]==1 && mappa[i][c]==1){
                printf ("\n\n %s WINNER \n", *Player_name);
                system ("cls");
                EndGame ();
            }
        }

    //Verticale
    for( i=0 ; i<=2 ; i++)
        for (a=0, b=1, c=2; c<2 ; a++, b++, c++){
            if (mappa[a][i]==1 && mappa[b][i]==1 && mappa[b][i]==1){
                printf ("\n\n %s WINNER \n", *Player_name);
                system ("cls");
                EndGame ();
            }
        }

    //Diagonale_Principale
    i=0;
    for (a=0, b=1, c=2; c<2 ; a++, b++, c++){
        if (mappa[i][a]==1 && mappa[i+1][b]==1 && mappa[i+2][c]==1){
            printf ("\n\n %s WINNER \n", *Player_name);
            system ("cls");
            EndGame ();
        }
    }

    //Diagonale_Secondaria
    i=0;
    for (a=2, b=1, c=0; c<2 ; a++, b++, c++){
        if (mappa[i][a]==1 && mappa[i-1][b]==1 && mappa[i-2][c]==1){
            printf ("\n\n %s WINNER \n", *Player_name);
            system ("cls");
            EndGame ();
        }
    }

}

void Insert_player (){

   /* printf("\n\t%s e' il tuo turno", *Player_name);
    do{
        scanf("%d", choice);
        } while (choice < 0 || choice > 8);

    if ( mappa[i][j] = 0)
        mappa[i][j] = 2;
        turno = 1;
        StartGame();*/
}

//Numero casuale tra 0 e 8
int Insert_rand (){

   /* srand(10);
    for( i = 0; i < 10; i++)
    printf("3- Rand is %d\n", rand() % 8 );
    if ( mappa[i][j] = 0)
        mappa[i][j] = 1;
        turno = 0;
        StartGame();

/*    int candidatecount = 0;
	int candidate[9];
	int i;

	for (i = 0; i < 9; i++) {
		if (board->p[i] == MARK_NONE) {
			candidate[candidatecount++] = i;
		}
	}

	if (candidatecount == 0) return -1;

	return candidate[rand()%candidatecount];*/
}
void EndGame(){
    printf("\n\t\tEnd Of Game\n");
}

void set_number (){

    switch (choice){
        case 1: mappa [2][0]= 'O';break;
        case 2: mappa [2][1]= 'O';break;
        case 3: mappa [2][2]= 'O';break;
        case 4: mappa [1][0]= 'O';break;
        case 5: mappa [1][1]= 'O';break;
        case 6: mappa [1][2]= 'O';break;
        case 7: mappa [0][0]= 'O';break;
        case 8: mappa [0][1]= 'O';break;
        case 9: mappa [0][2]= 'O';break;
    }
}
