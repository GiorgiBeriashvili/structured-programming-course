#include <stdio.h>
#include <stdlib.h>

/*
 * 1. დაწერეთ პროგრამული კოდი, რომელიც წაიკითხავს ორ მთელ რიცხვს. შექმენით
 * მიმთითებლები ამ რიცხვებზე. შეკრიბეთ ეს რიცხვები პოინტერების გამოყენებით
 * გამოიტანეთ ცვლადების მისამართები და მნიშვნელობები.
 */
int main() {
    int a, b, *a_pointer, *b_pointer;

    printf("Enter two decimal integers (a and b): ");
    scanf("%d%d", &a, &b);

    a_pointer = &a;
    b_pointer = &b;

    int sum = *a_pointer + *b_pointer;

    printf("Sum of a and b: %d + %d = %d\n", a, b, sum);

    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", a_pointer);

    printf("Value of b: %d\n", b);
    printf("Address of b: %p\n", b_pointer);

    exit(EXIT_SUCCESS);
}
