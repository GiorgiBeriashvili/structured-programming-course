#include <stdio.h>
#include <stdlib.h>

/*
 * მრავალსართულიან სახლში სულ N ბინა, P სადარბაზო და Q სართულია. ყოველი
 * სადარბაზოს ყოველ სართულზე ერთნაირი რაოდენობის ბინაა. გამოთვალეთ, რომელ
 * სადარბაზოში და რომელ სართულზე იმყოფება ბინა ნომრით K.
 *
 * შესატანი მონაცემები: ოთხი მთელი რიცხვი - N, P, Q, K.
 *
 * 1 ≤ K ≤ N ≤ 1000, P * Q ≤ N.
 *
 * გამოსატანი მონაცემები: ერთ სტრიქონში ორი მთელი რიცხვი
 *
 * სადარბაზოს ნომერი და სართულის ნომერი, სადაც მოცემული K ნომრის მქონე ბინა
 * იმყოფება.
 *
 * შესატანი მონაცემები
 * N=30 P=2 Q=5 K=27
 *
 * გამოსატანი მონაცემები
 * 2 4
 */
int main() {
    int apartments, entrances, floors, flat, entrance, floor;

    scanf("%d%d%d%d", &apartments, &entrances, &floors, &flat);

    int apartments_per_entrance = apartments / entrances;

    if (flat % apartments_per_entrance == 0) {
        entrance = flat / apartments_per_entrance;
    } else {
        entrance = flat / apartments_per_entrance + 1;
    }

    int complex = flat - (entrance - 1) * apartments_per_entrance;
    int apartments_per_floor = apartments / entrances / floors;

    if ((complex) % apartments_per_floor == 0) {
        floor = complex / apartments_per_floor;
    } else {
        floor = complex / apartments_per_floor + 1;
    }

    printf("%d %d", entrance, floor);

    exit(EXIT_SUCCESS);
}
