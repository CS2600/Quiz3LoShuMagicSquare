#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef int square[3][3];

bool isMagicSquare(square *input) {
        for(int i = 0; i < 3; i++) {
        if(i == 0) {
            if((*input)[i][i] + (*input)[i][i + 1] + (*input)[i][i + 2] != 15 || 
            (*input)[i][i] + (*input)[i + 1][i] + (*input)[i + 2][i] != 15) {
                return false;
            }
        }
        if(i == 1) {
            if((*input)[i][i - 1] + (*input)[i][i] + (*input)[i][i + 1] != 15 || 
            (*input)[i - 1][i] + (*input)[i][i] + (*input)[i + 1][i] != 15 ||
            (*input)[i - 1][i - 1] + (*input)[i][i] + (*input)[i + 1][i + 1] != 15 ||
            (*input)[i - 1][i + 1] + (*input)[i][i] + (*input)[i + 1][i - 1] != 15) {
                return false;
            }
        }
        if(i == 2) {
            if((*input)[i][i] + (*input)[i][i - 1] + (*input)[i][i - 2] != 15 || 
            (*input)[i][i] + (*input)[i - 1][i] + (*input)[i - 2][i] != 15) {
                printf("TEST %d\n", (*input)[i][i] + (*input)[i][i + 1] + (*input)[i][i + 2]);
                printf("TEST 2 %d\n", (*input)[i][i] + (*input)[i - 1][i] + (*input)[i - 2][i]);
                return false;
            }
        }
    }
    return true;
} //End isMagicSquare

void printSquare(square *input) {
    for(int i = 0; i < 3; i++) {
        printf("[");
        for(int j = 0; j < 3; j++) {
            printf("%d", (*input)[i][j]);
            if(j != 2) {
                printf(" ");
            }
        }
        printf("]\n");
    }
} //End printSquare

int main() {

    square validSquare = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    square invalidSquare = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    square *ptrToValidSquare = &validSquare;
    square *ptrToInvalidalidSquare = &invalidSquare;

    //Testing valid square
    printf("The square: \n");
    printSquare(ptrToValidSquare);
    if(isMagicSquare(ptrToValidSquare)) {
        printf("Is a Lo Shu Magic Square\n\n");
    }
    else {
        printf("Is not a Lo Shu Magic Square\n\n");
    }

    //Testing invalid square
    printf("The square: \n");
    printSquare(ptrToInvalidalidSquare);
    if(isMagicSquare(ptrToInvalidalidSquare)) {
        printf("Is a Lo Shu Magic Square\n\n");
    }
    else {
        printf("Is not a Lo Shu Magic Square\n\n");
    }

    int numTries = 0;
    bool squareFound = false;
    square *randomSquare = malloc(9 * sizeof(int));

    time_t t;
    srand((unsigned)time(&t));

    while(!squareFound) {
        int temp[9];
        int random;
        bool repeat;

        for(int i = 0; i < 9; i++) {
            do{
                random = (rand() % 9) + 1;
                repeat = false;

                for(int j = 0; j < i; j++) {
                    if(random == temp[j])
                        repeat = true;
                }

            } while(repeat);
            temp[i] = random;
        }

        int counter = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                (*randomSquare)[i][j] = temp[counter];
                counter++;
            }
        }
        numTries++;
        if(isMagicSquare(randomSquare)) break;
    }

    printf("Total number of squares generated: %d\n", numTries);
    printSquare(randomSquare);
    

} //End main