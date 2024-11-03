#include <stdio.h>

void compressWord(char input[], char output[], int *removedCount) {
    int i = 0, j = 0;
    *removedCount = 0;

    while (input[i] != '\0') {
        if (input[i] != input[i + 1]) {
            output[j++] = input[i];
        } else {
            (*removedCount)++;
        }
        i++;
    }
    output[j] = '\0';
}

int main() {
    char words[3][20];
    char compressed[20];
    int totalRemoved = 0;
    int removed;

    printf("Enter 3 words to compress:\n");
    for (int i = 0; i < 3; i++) {
        printf("Word %d: ", i + 1);
        scanf("%19s", words[i]);
    }

    printf("\nCompressed Words:\n");
    for (int i = 0; i < 3; i++) {
        compressWord(words[i], compressed, &removed);
        totalRemoved += removed;
        printf("%s -> %s (Removed: %d)\n", words[i], compressed, removed);
    }

    printf("Total characters removed: %d\n", totalRemoved);
    return 0;
}


