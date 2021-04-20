#include <stdio.h>
#include <stdlib.h>

/*
 * ამოცანა 1
 *
 * დაწერეთ პროგრამა, რომელიც უზრუნველყოფს კლავიატურიდან რამდენიმე რიცხვის
 * შეტანას, თუ შეტანილი რიცხვი იქნება ორნიშნა, პროგრამამ უნდა შეაბრუნოს ეს
 * რიცხვი და დაბეჭდოს როგორც საწყისი, ასევე შებრუნებული რიცხვი. მონაცემების
 * შეტანა დასრულდეს, თუ შებრუნებული რიცხვების რაოდენობა გახდება 5-ზე მეტი.
 *
 * შეფასების რუბრიკა:
 *
 * მონაცემების შეტანის ციკლური ორგანიზება - 2ქულა
 * ორნიშნა რიცხვის შებრუნება - 2 ქულა
 * ციკლიდან გამოსვლის ორგანიზება და შედეგის მიღება - 2 ქულა.
 */
int main() {
    int number, inversed_count = 0;
    double inversed_number;

    while (inversed_count <= 5) {
        printf("Enter an integer: ");
        scanf("%d", &number);

        int digit_count = 0, origin = number;

        while (origin != 0) {
            digit_count++;

            origin /= 10;
        }

        if (digit_count == 2) {
            inversed_number = 1 / (double)number;

            printf("Origin: %d\n", number);
            printf("Inversed: %f\n", inversed_number);

            inversed_count++;
        }
    }

    exit(EXIT_SUCCESS);
}