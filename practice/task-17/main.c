#include <stdio.h>
#include <stdlib.h>

int decimal_to_binary(int decimal);

/*
 * 4. დაწერეთ პროგრამა, რომელიც ფუნქციის გამოყენებით გადაიყვანს ათობით რიცხვს
 * ორობითში.
 */
int main() {
    int decimal;

    printf("Enter a decimal integer: ");
    scanf("%d", &decimal);

    int binary = decimal_to_binary(decimal);

    printf("%d to binary: %d", decimal, binary);

    exit(EXIT_SUCCESS);
}

int decimal_to_binary(int decimal) {
    if (decimal == 0) {
        return 0;
    } else {
        return (decimal % 2 + 10 * (decimal_to_binary(decimal / 2)));
    }
}
