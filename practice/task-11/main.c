#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLUMNS 4

/*
 * 3. მოცემულია ორგანზომილებიანი მასივი (4X4), იპოვეთ თთეოული სვეტის უარყოფითი
 * ელემენტების რაოდენობა და ჩაწერეთ ერთგანზომილებიან მასივში.
 */
int main() {
    int matrix[ROWS][COLUMNS];
    int array[COLUMNS];

    printf("Matrix:\n");

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            matrix[row][column] = rand() % 20 - 10;

            printf("%d\t", matrix[row][column]);
        }

        printf("\n");
    }

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            if (matrix[row][column] < 0) {
                array[column]++;
            }
        }
    }

    printf("\nNegative numeric value count per column:\n");

    for (int index = 0; index < COLUMNS; index++) {
        printf("%d\t", array[index]);
    }

    exit(EXIT_SUCCESS);
}