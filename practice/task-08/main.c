#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void printDigit(int number);

/*
 * დაშალეთ ნებისმიერი ნატურალური რიცხვი ციფრების სახით
 * მაგ. 3467
 * გამოიტანეთ integer ტიპის 4 მნიშვნელობა: 3 4 6 7
 */
int main() {
    int number;

    scanf("%d", &number);

    printDigit(number);

    exit(EXIT_SUCCESS);
}

void printDigit(int number) {
    if (number == 0) {
        return;
    }

    int remainder = number % 10;

    printDigit(number / 10);

    printf("%d ", remainder);
}
