#include <stdio.h>
#include <stdlib.h>

/*
 * არითმეტიკის დავალების შესრულებისას ბუბას უნდა გადაემრავლებინა
 * ორი ორნიშნა რიცხვი. მათი ჩანაწერი ციფრების მიხედვით იყო: xy და ac.
 * ბუბას შეეშალა და ერთმანეთზე გადაამრავლა ორი რიცხვი ციფრებით: xc
 * და ay. ცხადია მის მიერ მიღებული პასუხი არ დაემთხვა
 * სახელმძღვანელოში მითითებულ პასუხს. დაწერეთ პროგრამა, რომელიც
 * გამოთვლის რა პასუხი ეწერა სახელმძღვანელოში.
 *
 * შესატანი მონაცემები: ერთ სტრიქონში ორი ორნიშნა რიცხვი, რომელთა
 * ჩანაწერი ციფრების მიხედვით წარმოადგენს xc და ay. არცერთი ციფრი 0
 * არ არის.
 *
 * გამოსატანი მონაცემები: სახელმძღვანელოში მითითებული პასუხი.
 *
 * შესატანი მონაცემები
 * 27 45
 *
 * გამოსატანი მონაცემები
 * 1175
 */
int main() {
    int a, b, c;

    printf("Enter two two-digit integers: ");

    scanf("%d%d", &a, &b);

    c = (a / 10 * 10 + b % 10) * (b / 10 * 10 + a % 10);

    printf("Result: %d", c);

    exit(EXIT_SUCCESS);
}