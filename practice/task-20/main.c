#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void print_programming_credits();
void print_history_credits();
void print_mathematics_credits();
void print_language_credits();

/*
 * 3. დაწერეთ პროგრამა, გამოიყენეთ პოინტერების მასივი, რომლის ელემენტებია:
 * დაპროგრამება, ისტორია, მათემატიკა, უცხოენა
 * პოინტერების მასივის ელემენტის ამორჩევის მიხედვით შესრულდეს შესაბამისი
 * ფუნქციები, რომელიც გამოიტანს ეკრანზე საგნის კრედიტების რაოდენობას.
 *
 * დაპროგარმება - 5 კრედიტი
 * ისტორია - 3 კრედირი
 * მათემატიკა - 6 კრედიტი
 * უცხო ენა - 5 კრედიტი
 */
int main() {
    void (*array[SIZE])(void) = {
        print_programming_credits,
        print_history_credits,
        print_mathematics_credits,
        print_language_credits,
    };

    printf("Browse credits for the following subjects:\n");
    printf("1. Programming\n");
    printf("2. History\n");
    printf("3. Mathematics\n");
    printf("4. Language\n");

    int choice;

    while (choice < 1 || choice > 4) {
        printf("Please select the subject index (1-4): ");

        scanf("%d", &choice);
    }

    (*array[choice - 1])();

    exit(EXIT_SUCCESS);
}

void print_programming_credits() { printf("Programming - 5 credits"); }
void print_history_credits() { printf("History - 3 credits"); }
void print_mathematics_credits() { printf("Mathematics - 6 credits"); }
void print_language_credits() { printf("Language - 5 credits"); }