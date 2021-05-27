#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

void print_matrix(int rows, int columns, int dimensions,
                  int matrix[rows][columns]);

/*
 * 2. გადააკეთეთ პროგრამა - საბოლოო შედეგების მატრიცის დასაბეჭდად გამოიყენეთ
 * ფუნქცია, რომელსაც გადასცემთ მატრიცის მისამართს.
 */
int main() {
    int matrix[ROWS][COLUMNS], dimensions;

    printf("Enter the dimensions of the matrix (dimension x dimension): ");
    scanf("%d", &dimensions);

    printf("Fill the matrix with elements:\n");

    for (int row = 0; row < dimensions; row++) {
        for (int column = 0; column < dimensions; column++) {
            printf("Element [%d][%d] = ", row, column);

            scanf("%d", &matrix[row][column]);
        }
    }

    for (int row = 0; row < dimensions; row++) {
        for (int column = 0; column < dimensions - 1; column++) {
            for (int target = column + 1; target < dimensions; target++) {
                if (matrix[row][column] > matrix[row][target]) {
                    int element = matrix[row][column];

                    matrix[row][column] = matrix[row][target];
                    matrix[row][target] = element;
                }
            }
        }
    }

    print_matrix(ROWS, COLUMNS, dimensions, matrix);

    exit(EXIT_SUCCESS);
}

void print_matrix(int rows, int columns, int dimensions,
                  int matrix[rows][columns]) {
    printf("Printing the contents of the matrix located at address %p:\n",
           matrix);

    for (int row = 0; row < dimensions; row++) {
        for (int column = 0; column < dimensions; column++) {
            printf("%d ", matrix[row][column]);
        }

        printf("\n");
    }
}