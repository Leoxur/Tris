#include "funzioni.h"
//Clear screen
void clear_screen(){

    const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
    write (STDOUT_FILENO, CLEAR_SCREE_ANSI, 12);
    }

void draw_map(char mappa[3][3]){

    int i,j;

    printf("\n\t     \e[1;42m..-Drawing Maps-..\e[00m\n");
    for (i=0; i<3; i++ ){
        printf("\e[1;31m\n\t\t-------------\n\t\t| \e[00m");
        for (j=0; j<3; j++){
            if(mappa[i][j]=='\0')
            printf(" %d ", 3*(i)+(j+1));
            else
            printf("\e[1;32m %c\e[00m ", mappa[i][j]);
            }
        printf("\e[1;31m |\e[00m");
    }
    printf("\e[1;31m\n\t\t-------------\n\e[00m");
}


void map_null(char mappa[3][3]){

     int i = 0, j = 0;
     for (i=0; i<3; i++)
        for (j=0; j<3; j++){
            mappa[i][j]= '\0';
        }
}

void insert_player(char mappa[3][3]){

    int ins = 0;
    int r=0, c=0; //righe e colonne
    printf("\n\tFai la tua mossa, inserisci X col tastierino numerico :D\n");
    printf("\t [gioca con il tastierino come fosse la mappa di gioco]\n");
    scanf (" %d", &ins);

            if ( ins > 0 && ins < 10 ){
                ins--;
                c = ins %3;
                ins -= c;
                r = ins /3;
                mappa[r][c]='X';
            } else {
                printf("\nReinserire un valore\n");
                insert_player(mappa);
            }

}

void insert_pc(char mappa[3][3]){

    int r = 0, c = 0;
    int move = 0;//ex turn

    while(move == 0){

        c = rand() % 3;
        r = rand() % 3;
        if( mappa[r][c]!= ('\0') || !('X') ){
            continue;
        } else{
            mappa[r][c] = 'O';
            move = 1;
        }
    }
}

int check_winner(char mappa[3][3]){

    int i, j;
    char buf;
    char buf2 = '\0';

    //Orizzontale
    for( i=0; i<3; i++){
        buf = mappa[i][0];
        for( j=0; j<3; j++){
            if(mappa[i][j] != buf)
            buf= '\0';
        }
        if (buf != '\0'){
            buf2 = buf;
            return buf2;
        }
    }
    //Verticale
    for( i=0; i<3; i++){
        buf = mappa[0][i];
        for( j=0; j<3; j++){
            if(mappa[j][i] != buf)
            buf= '\0';
        }
        if (buf!= '\0'){
            buf2 = buf;
            return buf2;
        }
    }

    //Diagonale Principale
    buf = mappa[0][0];
    for( i=0; i<3; i++){
        if(mappa[i][i] != buf)
        buf= '\0';
    }
    if (buf != '\0')
        buf2 = buf;

    //Diagonale Secondaria
    buf = mappa[0][2];
    for( i=0; i<3; i++){
        if(mappa[i][2-i] != buf)
        buf= '\0';
    }
    if (buf != '\0')
        buf2 = buf;

    return buf2;
}
