#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void populate_matrix(int rows, int columns, int matrix[rows][columns]);
void print_matrix(int rows, int columns, int matrix[rows][columns]);
int find_maximum_of_matrix(int rows, int columns, int matrix[rows][columns]);
int find_minimum_of_matrix(int rows, int columns, int matrix[rows][columns]);

/*
 * 2. აუცილებელია შექმნათ ორგანზომილებიანი მასივი 5 x 5. შემდეგ დაწერეთ
 * ფუნქცია, რომელიც შეავსებს მას შემთხვევითი რიცხვებით 30 – დან 60 – მდე.
 * შექმენით კიდევ ორი ფუნქცია, რომლითაც იპოვით ამ ორგანზომილებიანი მასივის
 * მაქსიმალურ და მინიმალურ ელემენტებს.
 */
int main() {
    int matrix[ROWS][COLUMNS];

    srand(time(NULL));

    populate_matrix(ROWS, COLUMNS, matrix);
    print_matrix(ROWS, COLUMNS, matrix);

    int maximum = find_maximum_of_matrix(ROWS, COLUMNS, matrix);
    int minimum = find_minimum_of_matrix(ROWS, COLUMNS, matrix);

    printf("The maximum element of the matrix: %d\n", maximum);
    printf("The minimum element of the matrix: %d\n", minimum);

    exit(EXIT_SUCCESS);
}

void populate_matrix(int rows, int columns, int matrix[rows][columns]) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            matrix[row][column] = rand() % 30 + 30;
        }
    }
}

void print_matrix(int rows, int columns, int matrix[rows][columns]) {
    printf("Printing the contents of the matrix located at address %p:\n",
           matrix);

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            printf("%d ", matrix[row][column]);
        }

        printf("\n");
    }
}

int find_maximum_of_matrix(int rows, int columns, int matrix[rows][columns]) {
    int maximum = matrix[0][0];

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            if (matrix[row][column] > maximum) {
                maximum = matrix[row][column];
            }
        }
    }

    return maximum;
}

int find_minimum_of_matrix(int rows, int columns, int matrix[rows][columns]) {
    int minimum = matrix[0][0];

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            if (matrix[row][column] < minimum) {
                minimum = matrix[row][column];
            }
        }
    }

    return minimum;
}