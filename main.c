#include "funzioni.h"

int main (){

    int counter = 0; //contatore mosse, massimo a 9
    char winner ='\0';
    srand(time(NULL));
    char mappa[3][3];   //Real map

    map_null(mappa);
    draw_map(mappa);
    check_winner(mappa);

    for(counter=0; counter<9 && !(check_winner(mappa)); counter++){

        insert_player(mappa);
        if (check_winner(mappa) != '\0')
            break;
        insert_pc(mappa);
        clear_screen();
        draw_map(mappa);
    }
    draw_map(mappa);
    winner = check_winner(mappa);

    if(winner)
        printf("\n\t\t %c e' il vincitore\n\n\n", check_winner(mappa));
    else {
        draw_map(mappa);
        check_winner(mappa);
        printf("\n\t\t La partita e' patta");
    }

return 0;
}
