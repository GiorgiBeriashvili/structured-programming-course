#include <stdio.h>
#include <stdlib.h>

/*
 * ვარჯიშის დაწყებისთანავე, პირველ დღეს მოთხილამურემ 10 კმ გაიარა. ყოველ მეორე
 * დღეს მან გაზარდა გარბენი წინა დღის გარბენის 10% -ით. განსაზღვრეთ:
 * ა) რომელ დღეს გაივლის 20 კმ-ზე მეტს;
 * ბ) რომელ დღეს მთლიანი გარბენი ყველა დღის განმავლობაში გადააჭარბებს 100 კმ-ს.
 */
int main() {
    double distance = 10, total = distance;

    int coefficient = 10, a = 0, b = 0, day = 1, a_completion_day = day,
        b_completion_day = day;

    while (!a || !b) {
        day++;

        distance += distance * coefficient / 100;

        total += distance;

        if (!a && distance > 20) {
            a = 1;

            a_completion_day = day;
        }

        if (!b && total > 100) {
            b = 1;

            b_completion_day = day;
        }
    }

    printf("%d %d", a_completion_day, b_completion_day);

    exit(EXIT_SUCCESS);
}