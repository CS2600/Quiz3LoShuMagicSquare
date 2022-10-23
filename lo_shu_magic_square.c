#include <stdio.h>

int isMagicSquare(int input[3][3]) {
        for(int i = 0; i < 3; i++) {
        if(i == 0) {
            if(input[i][i] + input[i][i + 1] + input[i][i + 2] != 15 || 
            input[i][i] + input[i + 1][i] + input[i + 2][i] != 15) {
                return 1;
            }
        }
        if(i == 1) {
            if(input[i][i - 1] + input[i][i] + input[i][i + 1] != 15 || 
            input[i - 1][i] + input[i][i] + input[i + 1][i] != 15 ||
            input[i - 1][i - 1] + input[i][i] + input[i + 1][i + 1] != 15 ||
            input[i - 1][i + 1] + input[i][i] + input[i + 1][i - 1] != 15) {
                return 1;
            }
        }
        if(i == 2) {
            if(input[i][i] + input[i][i + 1] + input[i][i + 2] != 15 || 
            input[i][i] + input[i - 1][i] + input[i - 2][i] != 15) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {

}