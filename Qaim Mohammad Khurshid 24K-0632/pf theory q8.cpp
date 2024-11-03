#include <stdio.h>
#include <stdlib.h>


int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, last_digit;
    while (number > 0) {
        last_digit = number % 10;
        decimal += last_digit * base;
        number /= 10;
        base *= 2;
    }
    return decimal;
}


int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        binary += (number % 2) * base;
        number /= 2;
        base *= 10;
    }
    return binary;
}


void DecimalToHexadecimal(int number) {
    printf("Hexadecimal: %X\n", number);
}


void HexadecimalToDecimal(char hexNumber[]) {
    int decimal;
    sscanf(hexNumber, "%x", &decimal);
    printf("Decimal: %d\n", decimal);
}


void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    printf("Hexadecimal: %X\n", decimal);
}


void HexadecimalToBinary(char hexNumber[]) {
    int decimal;
    sscanf(hexNumber, "%x", &decimal);
    printf("Binary: %d\n", DecimalToBinary(decimal));
}


int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        printf("\nChoose a conversion:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", BinaryToDecimal(number));
                break;
            case 2:
                printf("Enter decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", DecimalToBinary(number));
                break;
            case 3:
                printf("Enter decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;
            case 4:
                printf("Enter hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;
            case 5:
                printf("Enter binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;
            case 6:
                printf("Enter hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

