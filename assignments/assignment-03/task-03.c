#include <stdio.h>
#include <stdlib.h>

void origin();
void target();

/*
 * 3. მოიფიქრეთ პროგრამა. რომელშიც ძირითადი ფუნქციიდან ხდება სხვა ფუნქციის
 * გამოძახება, ხოლო ეს უკანასკნელი ფუნქცია იძახებდეს ასევე კიდევ ერთ ფუნქციას.
 */
int main() {
    origin();

    exit(EXIT_SUCCESS);
}

void origin() { target(); }
void target() { printf("Called from origin."); };