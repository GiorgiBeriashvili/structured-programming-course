#include <stdio.h>
#include <stdlib.h>

int is_prime(int number);

/*
 * 1. შექმენით მასივი მარტივი რიცხვებისგან, რომელიც მოქცეულია 2-დან n-მდე
 * ინტერვალში. ამოცანა გადაწყვიტეთ ფუნქციის გამოყენებით.
 */
int main() {
    int number;

    do {
        printf("Enter a prime number in range [2; N): ");
        scanf("%d", &number);
    } while (number < 2);

    int array[number];
    int index = 0;

    for (int integer = 2; integer <= number; integer++) {
        if (is_prime(integer) == 1) {
            array[index] = integer;

            index++;
        }
    }

    for (int integer = 0; integer < index; integer++) {
        printf("%d ", array[integer]);
    }

    exit(EXIT_SUCCESS);
}

int is_prime(int number) {
    int is_prime = 1;

    for (int integer = 2; integer < number / 2; integer++) {
        if (number % integer == 0) {
            is_prime = 0;

            break;
        }
    }

    return is_prime;
}