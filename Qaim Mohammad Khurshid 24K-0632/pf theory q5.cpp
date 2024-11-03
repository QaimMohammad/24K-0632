#include <stdio.h>

void printHorizontalHistogram(int values[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printVerticalHistogram(int values[], int count) {
    int max = 0;
    for (int i = 0; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }

    for (int i = max; i > 0; i--) {
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() {
    int count;
    printf("Enter the number of values: ");
    scanf("%d", &count);

    int values[count];
    printf("Enter the values:\n");
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("\nHorizontal Histogram\n");
    printHorizontalHistogram(values, count);

    printf("\nVertical Histogram\n");
    printVerticalHistogram(values, count);

    return 0;
}

