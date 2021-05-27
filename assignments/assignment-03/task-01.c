#include <stdio.h>
#include <stdlib.h>

float median(int *a, int *b);

/*
 * 1. გადაწერეთ პირველი მაგალითი ისე, რომ გამოიყენოთ პოინტერი;
 */
int main() {
    int a = 18, b = 35;
    int *a_pointer = &a, *b_pointer = &b;

    float result;

    printf("%10.1f\n", median(a_pointer, b_pointer));

    a = 121, b = 346;
    result = median(a_pointer, b_pointer);

    printf("%10.1f\n", result);

    a = 1032, b = 1896;
    result = median(a_pointer, b_pointer);

    printf("%10.1f\n", result);

    exit(EXIT_SUCCESS);
}

float median(int *a, int *b) {
    float result;

    result = (float)(*a + *b) / 2;

    return result;
}