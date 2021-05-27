/*

*/
#include <stdio.h>
#include <stdlib.h>

void print_array_of_unique_elements(int size, int array[size]);
void print_mode_of_array(int size, int array[size]);

/*
 * 4. შექმენით პოინტერების მასივი და უზრუნველყავით გადასვლა ფუნქციებზე:
 * ფუნქცია - გადაეცემა მასივი, ქმნის ახალ მასივს, რომელშიც, გადატანილია ამ
 * მასივის ელემენტები, თუმცა თუ საწყის მასივში ელემენტების მნიშნელობები
 * მეორდება, ის არ გადადის  მაგ.: 1 4 4 5 6
 *     - მიღებული მასივი 1 5 6
 * ფუნქცია - გადაეცემა მასივი, პოულობს მასივის მოდას - ელემენტი, რომელიც ყველაზე
 * ხშირად გვხვდება:
 *     - მაგ. 3 5 5 5 6 6 7
 *     - შედეგი: 5
 */
int main() {
    void (*array_of_functions[2])(int size, int array[size]) = {
        print_array_of_unique_elements,
        print_mode_of_array,
    };

    printf("Call one the following functions:\n");
    printf("1. Create array of unique elements\n");
    printf("2. Find mode of the array\n");

    int size;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Fill the array with elements:\n");

    for (int index = 0; index < size; index++) {
        printf("Element [%d] = ", index);

        scanf("%d", &array[index]);
    }

    int choice;

    while (choice < 1 || choice > 2) {
        printf("Please select the function index (1-2): ");

        scanf("%d", &choice);
    }

    array_of_functions[choice - 1](size, array);

    exit(EXIT_SUCCESS);
}

void print_array_of_unique_elements(int size, int array[size]) {
    int count;

    int array_of_unique_elements[size];

    int index = 0;

    for (int origin = 0; origin < size; origin++) {
        count = 1;

        for (int target = origin + 1; target < size; target++) {
            if (array[origin] == array[target]) {
                count++;
            }
        }

        if (count == 1) {
            array_of_unique_elements[index] = array[origin];

            index++;
        }
    }

    printf("Printing the contents of the array located at address %p:\n",
           array_of_unique_elements);

    for (int origin = 0; origin < index; origin++) {
        printf("%d ", array_of_unique_elements[origin]);
    }
}

void print_mode_of_array(int size, int array[size]) {
    int mode = 0, maximum_count = 0;

    for (int origin = 0; origin < size; ++origin) {
        int count = 0;

        for (int target = 0; target < size; ++target) {
            if (array[target] == array[origin]) {
                count++;
            }
        }

        if (count > maximum_count) {
            maximum_count = count;

            mode = array[origin];
        }
    }

    if (mode > 1) {
        printf("Mode: %d\n", mode);
    } else {
        printf("Mode not found.");
    }
}