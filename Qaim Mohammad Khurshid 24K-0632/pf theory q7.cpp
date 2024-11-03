#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 6
#define COLS 5

void fill_grid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 'A' + (rand() % 26);
        }
    }
}

void print_grid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }
}

int search_word(char grid[ROWS][COLS], char *word) {
    int word_len = strlen(word);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - word_len; j++) {
            if (strncmp(&grid[i][j], word, word_len) == 0) {
                return 1;
            }
        }
    }

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j <= ROWS - word_len; j++) {
            int match = 1;
            for (int k = 0; k < word_len; k++) {
                if (grid[j + k][i] != word[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char grid[ROWS][COLS];
    char word[10];

    fill_grid(grid);
    print_grid(grid);

    while (1) {
        printf("Enter a word to search or 'quit' to exit: ");
        scanf("%9s", word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        if (search_word(grid, word)) {
            printf("%s Found\n", word);
        } else {
            printf("Try Again\n");
        }
    }

    return 0;
}

