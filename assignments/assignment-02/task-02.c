#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void populate_array(int array[], int size);
void print_longest_incrementing_sequence_length(int array[], int size);

/*
 * 2. მოცემულია N(20) მასივი, შეავსეთ მასივი შემთხვევითი რიცხვებით (20:70)
 * დიაპაზონში. განსაზღვრეთ მოცემულ მასივში მიმდევრობით განლაგებულ მნიშვნელობებში
 * ზრდადობით დალაგებული რიცხვების მაქსიმალური სიგრძე. დაბეჭდეთ საწყისი და
 * საბოლოო ინდექსი.
 */
int main() {
    int N[SIZE];

    srand(time(NULL));

    populate_array(N, SIZE);
    print_longest_incrementing_sequence_length(N, SIZE);

    exit(EXIT_SUCCESS);
}

void populate_array(int array[], int size) {
    for (int index = 0; index < size; index++) {
        array[index] = rand() % 50 + 20;

        printf("%d ", array[index]);
    }

    printf("\n");
}

void print_longest_incrementing_sequence_length(int array[], int size) {
    int start = 0;
    int end = 0;
    int distance = 0;
    int previous_distance = 0;

    for (int index = 0; index < size - 1; index++) {
        if (array[index] < array[index + 1]) {
            distance++;
        } else {
            if (distance >= previous_distance) {
                previous_distance = distance;

                start = index - distance;
                end = index;
            }

            distance = 0;
        }
    }

    printf("Start: %d\n", start);
    printf("End: %d\n", end);
}