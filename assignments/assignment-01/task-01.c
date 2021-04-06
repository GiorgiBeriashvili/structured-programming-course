#include <stdio.h>
#include <stdlib.h>

/*
 * დაადგინეთ შეტანილი წერტილის კოორდინატები, რომელ მეოთხედს მიეკუთვნება.
 * გაითვალისწინეთ მეოთხედების გადანომვრა ხდება საათის მოძრაობის
 * საწინააღმდეგო მიმართულებით.
 * შესატანი მონაცემები - ორი მთელი რიცხვი (x,y) კოორდინატების მნიშვნელობაბი
 * გამოსატანი მნიშვნელობა - ტექსტი ან რიცხვი, რომელიც აღწერს, რომელი
 * მეოთხედია: 1-დან 4-ის ჩათვლით.
 */
int main() {
    int x, y, quadrant = 0;

    scanf("%d%d", &x, &y);

    if (x > 0 && y > 0) {
        quadrant = 1;
    } else if (x < 0 && y > 0) {
        quadrant = 2;
    } else if (x < 0 && y < 0) {
        quadrant = 3;
    } else if (x > 0 && y < 0) {
        quadrant = 4;
    } else if (x == 0 && y > 0) {
        printf("The point lies at positive Y axis.");
    } else if (x == 0 && y < 0) {
        printf("The point lies at negative Y axis.");
    } else if (x > 0 && y == 0) {
        printf("The point lies at positive X axis.");
    } else if (x < 0 && y == 0) {
        printf("The point lies at negative X axis.");
    } else {
        printf("The point lies at origin.");
    }

    if (quadrant != 0) {
        printf("The point is located in the following quadrant: %d", quadrant);
    }

    exit(EXIT_SUCCESS);
}