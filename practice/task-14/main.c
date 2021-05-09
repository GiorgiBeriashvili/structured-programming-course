#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_A 10
#define SIZE_B 20

void populate_array(int array[], int size);
void print_array(int array[], int size);

/*
 * 1. გამოაცხადეთ ორი სხვადასხვა ზომის მასივი და დაწერეთ ფუნქცია, რომელიც
 * შეავსებს ამ მასივის ელემენტებს მნიშვნელობებით და აჩვენებს ეკრანზე. ფუნქციამ
 * უნდა მიიღოს ორი პარამეტრი - მასივი და მისი ზომა.
 */
int main() {
    int array_a[SIZE_A], array_b[SIZE_B];

    srand(time(NULL));

    populate_array(array_a, SIZE_A);
    print_array(array_a, SIZE_A);

    populate_array(array_b, SIZE_B);
    print_array(array_b, SIZE_B);

    exit(EXIT_SUCCESS);
}

void populate_array(int array[], int size) {
    for (int index = 0; index < size; index++) {
        array[index] = rand();
    }
}

void print_array(int array[], int size) {
    printf("Printing the contents of the array located at address %p: ", array);

    for (int index = 0; index < size; index++) {
        printf("%d ", array[index]);
    }

    printf("\n");
}