#include <stdio.h>
#include <stdlib.h>

int multi(int base, int pow);

/*
 * 2. მეორე მაგალითში multi(), ფუნქციიდან პირიქით მოხსენით პოინტერი და ფუნქციას
 * გადაეცით პარამეტრი-მნიშვნელობები.
 */
int main() {
    int x = 34, y = 6;

    x = multi(x, 367);
    y = multi(y, 91);

    printf("%d %d\n", x, y);

    exit(EXIT_SUCCESS);
}

int multi(int base, int power) {
    while (power >= 10) {
        base = base * 10;
        power = power / 10;
    }

    return base;
}