#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

/*
 * 1. მოცემულია ერთგანზომილებიანი მასივი. იპოვეთ მასივის იმ ელემენტების ჯამი,
 * რომელიც მოთავსებულია იმ ელემენტებს შორია, რომელთა მნიშნელობები 0-ია
 * (პირველ ნულებს შორის).
 *
 * მაგ. 3 5 0 4 6 7 0 9
 * უნდა იპოვოს 4+6+7
 * 3 0 4 5 0 5 8 0
 * უნდა იპოვოს 4+5
 */
int main() {
    int array[SIZE] = {3, 5, 0, 4, 6, 7, 0, 9};

    int start = 0, end = 0, sum = 0;

    for (int index = 0; index < SIZE; index++) {
        if (array[index] == 0) {
            start = 1;
        }

        if (start && array[index + 1] == 0) {
            end = 1;

            break;
        }

        if (start && index != SIZE - 1) {
            sum += array[index + 1];
        }
    }

    if (end) {
        printf("Sum: %d", sum);
    } else {
        printf("Unsupported sequence of numbers.");
    }

    exit(EXIT_SUCCESS);
}