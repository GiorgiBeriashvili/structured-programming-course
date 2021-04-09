#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLUMNS 4

/*
 * 2. მოცემულია ორგანზომილებიანი მასივი (4X4), თუ პირველი სვეტის ელემენტების
 * საშუალო მეტია მეორე სვეტის ელემენტების საშუალოზე, მაშინ შეუცვალეთ ადგილები
 * პირველი სვეტის და მეორეს სვეტის ელემენტებს.
 */
int main() {
    int matrix[ROWS][COLUMNS];

    printf("Matrix:\n");

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            matrix[row][column] = rand() % 25;

            printf("%d\t", matrix[row][column]);
        }

        printf("\n");
    }

    const int COLUMN_INTERVAL = 2;
    double column_averages[COLUMN_INTERVAL];

    for (int column = 0; column < COLUMN_INTERVAL; column++) {
        for (int row = 0; row < ROWS; row++) {
            column_averages[column] += matrix[row][column];
        }

        column_averages[column] = (double)(column_averages[column] / ROWS);
    }

    if (column_averages[0] > column_averages[1]) {
        for (int row = 0; row < ROWS; row++) {
            int origin = matrix[row][0];

            matrix[row][0] = matrix[row][1];
            matrix[row][1] = origin;
        }

        printf("\nAltered matrix:\n");

        for (int row = 0; row < ROWS; row++) {
            for (int column = 0; column < COLUMNS; column++) {
                printf("%d\t", matrix[row][column]);
            }

            printf("\n");
        }
    }

    exit(EXIT_SUCCESS);
}