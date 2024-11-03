#include <stdio.h>

char grid[5][5] = {
    {'P', ' ', 'I', 'X', ' '},
    {' ', 'X', ' ', ' ', ' '},
    {'I', ' ', 'X', 'X', ' '},
    {' ', ' ', ' ', 'I', 'X'},
    {' ', 'X', ' ', ' ', ' '}
};

void print_grid(char grid[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }
}

int main() {
    int row = 0, col = 0, points = 0, steps = 0, playing = 1;
    char move;

    print_grid(grid);

    while (points < 3 && playing) {
        printf("Enter move (w/a/s/d) or 'q' to quit: ");
        scanf(" %c", &move);

        int new_row = row, new_col = col;

        if (move == 'w' && row > 0) new_row--;
        else if (move == 's' && row < 4) new_row++;
        else if (move == 'a' && col > 0) new_col--;
        else if (move == 'd' && col < 4) new_col++;
        else if (move == 'q') break;
        else {
            printf("Invalid Move\n");
            continue;
        }

        if (grid[new_row][new_col] == 'X') {
            printf("Invalid Move\n");
            continue;
        }

        if (grid[new_row][new_col] == 'I') points++;

        grid[row][col] = ' ';
        grid[new_row][new_col] = 'P';
        row = new_row;
        col = new_col;
        steps++;

        print_grid(grid);

        if (points < 3) {
            printf("Points: %d, Steps: %d\n", points, steps);
        }
    }

    printf("Game End\nTotal steps: %d\n", steps);
    return 0;
}

