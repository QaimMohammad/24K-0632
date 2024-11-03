#include <stdio.h>

int areAnagrams(char word1[], char word2[]) {
    int count[26] = {0};
    int i = 0;

    while (word1[i] != '\0') {
        count[word1[i] - 'a']++;
        i++;
    }

    i = 0;
    while (word2[i] != '\0') {
        count[word2[i] - 'a']--;
        i++;
    }

    for (i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;

    printf("Enter the number of words: ");
    scanf("%d", &n);

    char words[n][10];
    int grouped[n];

    for (int i = 0; i < n; i++) {
        grouped[i] = 0;
    }

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Word %d: ", i + 1);
        scanf("%9s", words[i]);
    }

    printf("\nGrouped Anagrams:\n");
    for (int i = 0; i < n; i++) {
        if (grouped[i] == 1) {
            continue;
        }

        printf("[ %s", words[i]);
        grouped[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (areAnagrams(words[i], words[j])) {
                printf(", %s", words[j]);
                grouped[j] = 1;
            }
        }
        printf(" ]\n");
    }

    return 0;
}

