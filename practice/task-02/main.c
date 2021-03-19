#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * მოცემულია სამნიშნა რიცხვი. გამოთვალეთ მისი გაყოფის
 * ნაშთები საკუთარ ციფრებზე. არცერთი ციფრი არ არის 0-ის
 * ტოლი.
 *
 * შესატანი მონაცემები: ერთადერთ სტრიქონში ერთი სამნიშნა
 * რიცხვი.
 *
 * გამოსატანი მონაცემები: სამი მთელი რიცხვი - მოცემული
 * რიცხვის გაყოფის ნაშთი მისსავე ასეულების, ათეულები და
 * ერთეულების თანრიგში მდგომ რიცხვებზე შესაბამისი
 * თანმიმდევრობით.
 *
 * შესატანი მონაცემები
 * 754
 *
 * გამოსატანი მონაცემები
 * 5 4 2
 */
int main() {
    int a;

    printf("Enter a three-digit integer: ");

    scanf("%d", &a);

    printf("Result:");

    for (int index = 0, power, remainder; index < 3; index++) {
        power = (int)pow(10, (3 - index - 1));
        remainder = a % (a / power % 10);

        printf(" %d", remainder);
    }

    exit(EXIT_SUCCESS);
}
