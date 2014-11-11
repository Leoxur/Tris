#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void clear_screen ();
void draw_map ();
void map_null ();
void insert_player ();
void insert_pc ();

char mappa[3][3];   //Real map
int appo_map[3][3]; //Buffermap
int turn = 0;   //0 = Player turn, 1 = Pc turn
int c = 0;
int pc = 0;


int main (){

    int counter = 0; //contatore mosse, massimo a 9
    map_null();
    do{
        switch(turn){
            case 0: {
                    clear_screen();
                    draw_map();
                    insert_player();
                    turn = 1;
                    counter++;
                    }; break;

            case 1: {
                    clear_screen();
                    draw_map();
                    insert_pc();
                    turn = 0;
                    counter++;
                    }; break;

        }
    }while(counter <= 9);
return 0;
}

void insert_player(){

    printf("\nInserire un numero da 1 a 9 col tastierino\n");
    printf("[gioca con il tastierino come fosse la mappa di gioco]\n");
    scanf ("%d", &c);

            if ( c > 0 && c < 10 )
                switch (c){
                    case  1:{ appo_map[2][0]=c;
                                 mappa[2][0]= 'X';}   break;
                    case  2:{ appo_map[2][1]=c;
                                 mappa[2][1]= 'X';}   break;
                    case  3:{ appo_map[2][2]=c;
                                 mappa[2][2]= 'X';}   break;

                    case  4:{ appo_map[1][0]=c;
                                 mappa[1][0]= 'X';}   break;
                    case  5:{ appo_map[1][1]=c;
                                 mappa[1][1]= 'X';}   break;
                    case  6:{ appo_map[1][2]=c;
                                 mappa[1][2]= 'X';}   break;

                    case  7:{ appo_map[0][0]=c;
                                 mappa[0][0]= 'X';}   break;
                    case  8:{ appo_map[0][1]=c;
                                 mappa[0][1]= 'X';}   break;
                    case  9:{ appo_map[0][2]=c;
                                 mappa[0][2]= 'X';}   break;
                }
            else {
            printf("\nReinserire un valore\n");
            insert_player();
            }
        turn = 1;
}

void insert_pc(){

    srand(9);
    pc = rand() %9;
    if ( pc > 0 && c < 10 )
                switch (pc){
                    case  1:{ appo_map[2][0]=pc;
                                 mappa[2][0]= 'O';}   break;
                    case  2:{ appo_map[2][1]=pc;
                                 mappa[2][1]= 'O';}   break;
                    case  3:{ appo_map[2][2]=pc;
                                 mappa[2][2]= 'O';}   break;

                    case  4:{ appo_map[1][0]=pc;
                                 mappa[1][0]= 'O';}   break;
                    case  5:{ appo_map[1][1]=pc;
                                 mappa[1][1]= 'O';}   break;
                    case  6:{ appo_map[1][2]=pc;
                                 mappa[1][2]= 'O';}   break;

                    case  7:{ appo_map[0][0]=pc;
                                 mappa[0][0]= 'O';}   break;
                    case  8:{ appo_map[0][1]=pc;
                                 mappa[0][1]= 'O';}   break;
                    case  9:{ appo_map[0][2]=pc;
                                 mappa[0][2]= 'O';}   break;
                }
            else {
            printf("\nReinserire un valore\n");
            insert_pc();
            }
        turn = 1;
}

void draw_map(){

    printf("\n\t     ..-Drawing Maps-..\n");
    int i = 0, j = 0;
    for (i=0; i<3; i++ ){
        printf("\n\t\t-------------\n\t\t| ");
        for (j=0; j<3; j++){
        /*    if (appo_map[i][j] == 1)
			    printf ("| O ");
			else if (appo_map[i][j] == 2)
                printf("| X ");
            else
				printf (" %c | ", mappa [i][j]);*/
            printf(" %c ", mappa[i][j]);
            }
        printf(" |");
    }
    printf("\n\t\t-------------\n");
}
//Initialising map
void map_null(){

     int i = 0, j = 0;
     for (i=0; i<3; i++)
        for (j=0; j<3; j++){
            mappa[i][j]= ' ';
        }
}
//Clear screen
void clear_screen(){

    const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
    write (STDOUT_FILENO, CLEAR_SCREE_ANSI, 12);
    }
