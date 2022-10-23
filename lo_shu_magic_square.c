#include <stdio.h>
#include <stdbool.h>

bool isMagicSquare(int input[3][3]) {
        for(int i = 0; i < 3; i++) {
        if(i == 0) {
            if(input[i][i] + input[i][i + 1] + input[i][i + 2] != 15 || 
            input[i][i] + input[i + 1][i] + input[i + 2][i] != 15) {
                return false;
            }
        }
        if(i == 1) {
            if(input[i][i - 1] + input[i][i] + input[i][i + 1] != 15 || 
            input[i - 1][i] + input[i][i] + input[i + 1][i] != 15 ||
            input[i - 1][i - 1] + input[i][i] + input[i + 1][i + 1] != 15 ||
            input[i - 1][i + 1] + input[i][i] + input[i + 1][i - 1] != 15) {
                return false;
            }
        }
        if(i == 2) {
            if(input[i][i] + input[i][i - 1] + input[i][i - 2] != 15 || 
            input[i][i] + input[i - 1][i] + input[i - 2][i] != 15) {
                printf("TEST %d\n", input[i][i] + input[i][i + 1] + input[i][i + 2]);
                printf("TEST 2 %d\n", input[i][i] + input[i - 1][i] + input[i - 2][i]);
                return false;
            }
        }
    }
    return true;
}

void printSquare(int input[3][3]) {
    for(int i = 0; i < 3; i++) {
        printf("[");
        for(int j = 0; j < 3; j++) {
            printf("%d", input[i][j]);
            if(j != 3) {
                printf(" ");
            }
        }
        printf("]\n");
    }
}

int main() {

    int validSquare[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};

    int invalidSquare[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("The square: \n");
    printSquare(validSquare);
    if(isMagicSquare(validSquare)) {
        printf("Is a Lo Shu Magic Square\n\n");
    }
    else {
        printf("Is not a Lo Shu Magic Square\n\n");
    }

    printf("The square: \n");
    printSquare(invalidSquare);
    if(isMagicSquare(invalidSquare)) {
        printf("Is a Lo Shu Magic Square\n\n");
    }
    else {
        printf("Is not a Lo Shu Magic Square\n\n");
    }

}