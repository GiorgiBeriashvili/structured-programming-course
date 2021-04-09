#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLUMNS 10

/*
 * 4. A და B უნივერსიტეტებმა გადაწყვიტეს მოაწყონ შეჯიბრი პროგრამირებაში.
 * თითოეულმა უნივერსიტეტმა შეჯიბრზე გამოიყვანა 10 სტუდენტი, რომელთა
 * ნამუშევრები შეფასდა ქულებით 0-დან 100-მდე. უნივერსიტეტის საბოლოო
 * შედეგად ითვლება 10 მონაწილიდან საუკეთესო 3-ის შედეგი. დაწერეთ
 * პროგრამა, რომელიც გამოითვლის საბოლოო შედეგს თითოეული
 * უნივერსიტეტისათვის.
 * შესატანი მონაცემები: პირველ 10 სტრიქონში - A უნივერსიტეტის
 * სტუდენტთა შედეგები. მომდევნო 10 სტრიქონში - B უნივერსიტეტის
 * სტუდენტთა შედეგები.
 * გამოსატანი მონაცემები: ერთადერთ სტრიქონში ორი მთელი რიცხვი - ჯერ A
 * უნივერსიტეტის შედეგი, შემდეგ B უნივერსიტეტის შედეგი.
 */
int main() {
    int matrix[ROWS][COLUMNS];

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            if (row == 0) {
                printf("Score of A-%d: ", column + 1);
            } else {
                printf("Score of B-%d: ", column + 1);
            }

            scanf("%d", &matrix[row][column]);
        }

        printf("\n");
    }

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            for (int index = 0; index < COLUMNS - column - 1; index++) {
                if (matrix[row][index] > matrix[row][index + 1]) {
                    int origin = matrix[row][index];

                    matrix[row][index] = matrix[row][index + 1];
                    matrix[row][index + 1] = origin;
                }
            }
        }
    }

    int scores[ROWS];

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < 3; column++) {
            scores[row] += matrix[row][COLUMNS - column - 1];
        }
    }

    printf("%d %d", scores[0], scores[1]);

    exit(EXIT_SUCCESS);
}