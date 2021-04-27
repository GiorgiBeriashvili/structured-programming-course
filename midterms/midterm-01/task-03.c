#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLUMNS 4

/*
 * ამოცანა 3
 *
3. მოცემულია ცხრილი
 * სახელი, გვარი შუალედური პრეზენტაცია საშინაო
 * დავალება
 *
 * ფინალური
 * ნინო 23 15 12 29
 * გიორგი 20 25 10 28
 * ლიკა 30 16 13 40
 * დავითი 19 20 15 28
 * ცხრილის რიცხვითი მონაცემებისათვის შექმენით ორგანზომილებიანი მასივი, ცხრილის
 * მონაცემების მიხედვით ბიჭების საშუალო შეფასება უფრო მეტია თუ გოგონების.
 * მითითება: გამოთვალეთ გიორგი და დავითის ჯამური შეფასება და გაასაშუალოეთ,
 * ანალოგიურად გამოთვალეთ ნინოს და ლიკას ჯამური შეფასება და გაასაშუალოეთ.
 *
 * შეფასების რუბრიკა:
 *
 * მასივის ორგანიზება მატრიცული სახით ეკრანზე - 2 ქულა
 * ჯამური შეფასებების პოვნა - 3 ქულა
 * უფორ მაღალი შეფასებების მქონე გუნდის (გოგონების ან ბიჭების) დადგენა - 3 ქულა.
 */
int main() {
    int scores[ROWS][COLUMNS] = {
        {23, 15, 12, 29}, // ნინო
        {20, 25, 10, 28}, // გიორგი
        {30, 16, 13, 40}, // ლიკა
        {19, 20, 15, 28}, // დავითი
    };

    printf("Scores:\n");

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            printf("%d\t", scores[row][column]);
        }

        printf("\n");
    }

    int male_sum = 0, female_sum = 0;

    // Calculating sum for females...
    for (int row = 0; row < ROWS; row += 2) {
        for (int column = 0; column < COLUMNS; column++) {
            female_sum += scores[row][column];
        }
    }

    printf("Sum of female scores: %d\n", female_sum);

    // Calculating sum for males...
    for (int row = 1; row < ROWS; row += 2) {
        for (int column = 0; column < COLUMNS; column++) {
            male_sum += scores[row][column];
        }
    }

    printf("Sum of male scores: %d\n", male_sum);

    double female_mean = (double)female_sum / 2;

    printf("Mean of female scores: %f\n", female_mean);

    double male_mean = (double)male_sum / 2;

    printf("Mean of male scores: %f\n", male_mean);

    if (male_mean > female_mean) {
        printf("Males have higher mean score");
    } else if (male_mean < female_mean) {
        printf("Females have higher mean score");
    } else {
        printf("Equal mean scores");
    }

    exit(EXIT_SUCCESS);
}