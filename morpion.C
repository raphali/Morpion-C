 #include <stdio.h>

char grid[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
int counter=0;
char current_Player = 'X';

/**
 * @brief Displays the grid
 */

void display_grid(){
    printf("   1   2   3 \n");
     for (int i = 0; i < 3; i++) {
         printf("%d  %c | %c | %c \n", i+1, grid[i][0], grid[i][1], grid[i][2]);
         if (i < 2)
             printf("  ---+---+---\n");
     }
}

/**
 * @brief Fill the grid with player choices
 */

void play(){
    int line=0;
    int column=0;
    int valide=0;

    while (!valide)
    {
        printf ("Dans quelle ligne voulez vous mettre le symbole : ");
        if (scanf("%d", &line) != 1) { // If the player has put something other than a number in his answer, the question is asked again
            while (getchar() != '\n');  
            line = 0;   
        }
        printf ("Dans quelle colonne voulez vous mettre le symbole : ");
        if (scanf("%d", &column) != 1) {
            while (getchar() != '\n');  
            column = 0;
        }

        if (line<1 || line>3 || column<1 || column>3)
        {
            printf("Entrez une valeur correcte (entre 1 et 3)\n");
        } else if (grid[line-1][column-1]!=' ')
        {
            printf("Il y a déjà un symbole dans cette case \n");
        } else {
            valide = 1;
        }
        
    }
    grid[line-1][column-1]=current_Player;
    display_grid();
    counter+=1;
}

/**
 * @brief Check if there is a win situation
 */

int check_win() {
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == current_Player && grid[i][1] == current_Player && grid [i][2] == current_Player)
            return 1;
        if (grid[0][i] == current_Player && grid[1][i] == current_Player && grid [2][i] == current_Player)
            return 1;
    }

    if (grid[0][0] == current_Player && grid[1][1] == current_Player && grid [2][2] == current_Player)
            return 1;
    if (grid[0][2] == current_Player && grid[1][1] == current_Player && grid [2][0] == current_Player)
            return 1;

    return 0;

}

/**
 * @brief main function
 */

int main() {

    display_grid();
    while (counter<9)
    {
        play();

        if (check_win())
        {
            printf("Le joueur %c à gagné \n", current_Player);
            return 0;
        }else if (counter==9)
        {
            printf("Match nul\n");
            return 0;
        }

        current_Player = (current_Player=='X') ? 'O' : 'X';
    }
    return 0;
}