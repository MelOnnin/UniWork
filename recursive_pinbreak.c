#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
const int charset_len = 36;
int is_found = 0;
long long iterations = 0;

void generate_recursive(char *current_guess, int position, int max_length, const char *target_hash) {
    if (is_found) return;

    if (position > 0) {
        current_guess[position] = '\0';
        iterations++;
        printf("[%lld] Пробваме: %-10s\r", iterations, current_guess);
        fflush(stdout);
        char *computed = crypt(current_guess, target_hash);
        if (strcmp(computed, target_hash) == 0) {
            printf("\n[УСПЕХ] Паролата е разбита: %s (след %lld итерации)\n", current_guess, iterations);
            is_found = 1;
            return;
        }
    }

    if (position == max_length) return;

    for (int i = 0; i < charset_len; i++) {
        current_guess[position] = charset[i];
        generate_recursive(current_guess, position + 1, max_length, target_hash);
    }
}

int main(void) {
    const char *target_hash = "abmHCWm63JSbA";

    char buffer[9];

    printf("Търсим паролата...\n");
    generate_recursive(buffer, 0, 4, target_hash);

    if (!is_found) {
        printf("Паролата не е намерена в зададените граници.\n");
    }
    return 0;
}
