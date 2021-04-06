#include <stdio.h>
#include <stdlib.h>

/*
 * დაადგინეთ ნატურალური რიცხვის ციფრების რაოდენობა
 */
int main() {
    int number, digits = 0;

    scanf("%d", &number);

    while (number != 0) {
        number /= 10;

        digits++;
    }

    printf("%d", digits);

    exit(EXIT_SUCCESS);
}