#include <stdio.h>

int findOptimalMove(int N) {
    if (N % 5 == 0) {
        return -1;  
    }
    return N % 5;  
}

int main() {
    int N;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);

    int result = findOptimalMove(N);

    if (result == -1) {
        printf("It's impossible for A to guarantee a win.\n");
    } else {
        printf("A should pick %d matchstick(s) on his first turn to guarantee a win.\n", result);
    }

    return 0;
}

