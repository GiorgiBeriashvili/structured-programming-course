#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __unix__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif

#define SIDES 6
#define ROWS 3
#define COLUMNS 3
#define PLAYER 0
#define COMPUTER 1
#define ROLLERS 2
#define ROUNDS 4

int roll_die(int sides);
void print_die(int side, int sides, int rows, int columns,
               const char dice[sides][rows][columns]);

/*
 * 3. დაწერეთ თამაში, რომელშიც კამათლის სროლა იმიტირებულია კომპიუტერისა და
 * მომხმარებლის მიერ. თამაშში არის 2 კამათელი და თითოეულ მათგანს შეუძლია 1-დან 6
 * ქულის გამოტანა. პროგრამის მიერ გადაწყდეს ვინ იწყებს თამაშს - კომპიუტერი თუ
 * მომხარებელი. თითოეული ისვრის ოთხჯერ . ეკრანზე აჩვენეთ სიმბოლოებით დახატული
 * კამათელი და ქულების ჯამური რაოდენობა. პირველი სროლის შემდეგ აჩვენეთ
 * შუალედური შედეგი - მოთამაშისა და კომპიუტერის მიერ მიღებული ქულების რაოდენობა.
 * დასასრულს, აცნობეთ ვინ მოიგო ყველა სროლის საფუძველზე.
 * კამათელი ეკრანზე გამოიტანეთ დაახლოებით ასეთი სახით:
 * 1- იანი
 *     * * * * * * *
 *     * * * * * * *
 *     * * * * * * *
 *     * * *   * * *
 *     * * * * * * *
 *     * * * * * * *
 *     * * * * * * *
 * 3-იანი
 *       * * * * * *
 *     * * * * * * *
 *     * * * * * * *
 *     * * *   * * *
 *     * * * * * * *
 *     * * * * * * *
 *     * * * * * *
 *
 * და. ა.შ.
 */
int main() {
    const char dice[SIDES][ROWS][COLUMNS] = {
        {
            {' ', ' ', ' '},
            {' ', 'O', ' '},
            {' ', ' ', ' '},
        },
        {
            {' ', ' ', 'O'},
            {' ', ' ', ' '},
            {'O', ' ', ' '},
        },
        {
            {' ', ' ', 'O'},
            {' ', 'O', ' '},
            {'O', ' ', ' '},
        },
        {
            {'O', ' ', 'O'},
            {' ', ' ', ' '},
            {'O', ' ', 'O'},
        },
        {
            {'O', ' ', 'O'},
            {' ', 'O', ' '},
            {'O', ' ', 'O'},
        },
        {
            {'O', ' ', 'O'},
            {'O', ' ', 'O'},
            {'O', ' ', 'O'},
        },
    };

    printf("Initial roll decides who starts the game:\n");

    int initialized = 0;
    int player_score;
    int computer_score;
    int leader;

    while (initialized == 0) {
        player_score = roll_die(SIDES) + roll_die(SIDES);
        computer_score = roll_die(SIDES) + roll_die(SIDES);

        printf("Player (%d/12) - Computer (%d/12)\n", player_score,
               computer_score);

        if (player_score > computer_score) {
            printf("Player shall lead the match.\n");

            initialized = 1;

            leader = PLAYER;
        } else if (player_score < computer_score) {
            printf("Computer shall lead the match.\n");

            initialized = 1;

            leader = COMPUTER;
        } else {
            printf("Draw! Re-initializing...\n");
        }
    }

    int rollers[ROLLERS];

    if (leader == PLAYER) {
        rollers[0] = PLAYER;
        rollers[1] = COMPUTER;
    } else {
        rollers[0] = COMPUTER;
        rollers[1] = PLAYER;
    }

    player_score = 0;
    computer_score = 0;

    printf("\n");

    for (int round = 0; round < ROUNDS; round++) {
        for (int roller = 0; roller < ROLLERS; roller++) {
            int first_roll, second_roll;

            if (rollers[roller] == PLAYER) {
                first_roll = roll_die(SIDES) + 1;

                printf("Player rolled die #1 for %d/6!\n", first_roll);

                print_die(first_roll - 1, SIDES, ROWS, COLUMNS, dice);

                second_roll = roll_die(SIDES) + 1;

                printf("Player rolled die #2 for %d/6!\n", second_roll);

                print_die(second_roll - 1, SIDES, ROWS, COLUMNS, dice);

                player_score += first_roll + second_roll;
            } else {
                first_roll = roll_die(SIDES) + 1;

                printf("Computer rolled die #1 for %d/6!\n", first_roll);

                print_die(first_roll - 1, SIDES, ROWS, COLUMNS, dice);

                second_roll = roll_die(SIDES) + 1;

                printf("Computer rolled die #2 for %d/6!\n", second_roll);

                print_die(second_roll - 1, SIDES, ROWS, COLUMNS, dice);

                computer_score += first_roll + second_roll;
            }
        }

        printf("End of round %d/4!\n", round + 1);

        printf("Player (%d/%d) - Computer (%d/%d)\n", player_score,
               12 * (round + 1), computer_score, 12 * (round + 1));

        printf("\n");
    }

    if (player_score > computer_score) {
        printf("Player has won the game!\n");
    } else if (player_score < computer_score) {
        printf("Computer has won the game!\n");
    } else {
        printf("The game ended in a draw!\n");
    }

    exit(EXIT_SUCCESS);
}

int roll_die(int sides) {
#ifdef __unix__
    sleep(1);
#elif _WIN32
    Sleep(1);
#endif

    srand(time(NULL));

    return rand() % sides;
}

void print_die(int side, int sides, int rows, int columns,
               const char dice[sides][rows][columns]) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            printf("%c ", dice[side][row][column]);
        }

        printf("\n");
    }

    printf("\n");
}