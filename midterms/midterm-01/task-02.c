#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

/*
 * ამოცანა 2
 *
 * 2. მოცემულია 10 ელემენტიანი მასივი
 * A[20]={3,4,6,7,12,15,3,18,11,24,13,-9,-20,-11,-10,-16,-6]
 * რიცხვს ვუწოდოთ „ჭკვიანი“, თუ ის ტოლია მის მარჯვნივ და მარცხნივ განლაგებული
 * რიცხვების ჯამის. „ჭკვიანი“ დადებითი რიცხვები გადაწერეთ ახალ p_arr მასივში,
 * ხოლო „ჭკვიანი“ უარყოფითი რიცხვები ახალ n_arr მასივში.
 *
 * შეფასების რუბრიკა:
 *
 * „ჭკვიანი“ რიცხვების დადგენის ორგანიზება - 2 ქულა
 * ახალი მასივების შექმნა - 4 ქულა
 */
int main() {
    int A[SIZE] = {
        3, 4, 6, 7, 12, 15, 3, 18, 11, 24, 13, -9, -20, -11, -10, -16, -6,
    };

    int p_arr[SIZE], n_arr[SIZE];

    int p_index = 0, n_index = 0;

    for (int index = 1; index < SIZE - 1; index++) {
        if (A[index] == A[index - 1] + A[index + 1]) {
            if (A[index] > 0) {
                p_arr[p_index] = A[index];

                p_index++;
            } else if (A[index] < 0) {
                n_arr[n_index] = A[index];

                n_index++;
            }
        }
    }

    printf("Positive smart numbers: ");

    for (int index = 0; index < p_index; index++) {
        printf("%d ", p_arr[index]);
    }

    printf("\n");

    printf("Negative smart numbers: ");

    for (int index = 0; index < n_index; index++) {
        printf("%d ", n_arr[index]);
    }

    exit(EXIT_SUCCESS);
}