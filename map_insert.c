#include <stdio.h>
#include <stdlib.h>

void draw_map ();
void map_null ();
void insert_player ();

char mappa[2][2];   //Real map
int appo_map[2][2]; //Buffermap
int turn = 0;   //0 = Player turn, 1 = Pc turn



int main (){

    int counter = 0; //contatore mosse, massimo a 9
    map_null();
    draw_map();
    do{
        switch(turn){
            case 0: {draw_map();
                    insert_player();
                    turn = 0;
                    counter++;
                    }; break;

            case 1: {//insert_pc();
                    draw_map();
                    turn = 0;
                    counter++;
                    }; break;

        }
    }while(counter < 9);
}

void insert_player(){

    int c = 0;
    printf("Inserire un numero da 1 a 9 col tastierino \n(gioca con il tastierino come fosse la mappa di gioco)\n");
    scanf ("%d", &c);
    int i = 0, j = 0;
    for (i=0; i<3; i++ )
        for (j=0; j<3; j++)
            do{
            switch (c){
                case  1:{ appo_map[2][0]=1;
                             mappa[2][0]= 'X';}   break;
                case  2:{ appo_map[2][1]=1;
                             mappa[2][1]= 'X';}   break;
                case  3:{ appo_map[2][2]=1;
                             mappa[2][2]= 'X';}   break;

                case  4:{ appo_map[1][0]=1;
                             mappa[1][0]= 'X';}   break;
                case  5:{ appo_map[1][1]=1;
                             mappa[1][1]= 'X';}   break;
                case  6:{ appo_map[1][2]=1;
                             mappa[1][2]= 'X';}   break;

                case  7:{ appo_map[0][0]=1;
                             mappa[0][0]= 'X';}   break;
                case  8:{ appo_map[0][1]=1;
                             mappa[0][1]= 'X';}   break;
                case  9:{ appo_map[0][2]=1;
                             mappa[0][2]= 'X';}   break;
            }
            c= 0;
            }while ( c<0 || c>9);
            turn = 1;
}

void draw_map(){
printf("In function draw_map");
     int i = 0, j = 0;
    for (i=0; i<3; i++ ){
        printf("\n\t\t-------------\n");
        printf("\t\t| ");
        for (j=0; j<3; j++){
            /*if (appo_map[i][j] == 1)
			    printf ("| O ");
			else if (appo_map[i][j] == 2)
                printf("| X ");
            else
				printf (" %c | ", mappa [i][j]);
            printf(" %c ", mappa[i][j]);*/
            }printf(" |");
    }
        printf("\n\t\t-------------\n");
}



void map_null(){

     int i = 0, j = 0;
     for (i=0; i<3; i++)
        for (j=0; j<3; j++){
            mappa[i][j]= ' ';
            //printf(" %c\n ", mappa[i][j]);
        }
}

