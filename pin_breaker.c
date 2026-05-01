#include <stdio.h>
#include <string.h>
#include <crypt.h> // Задължително!

void crack_pin(const char *target_hash) {
    char guess[5]; // 4 цифри + '\0'
    
    printf("--- Започва PIN Brute-Force ---\n");
    
    for (int i = 0; i <= 9999; i++) {

        sprintf(guess, "%04d", i);
        
        char *computed_hash = crypt(guess, target_hash);

        if (strcmp(computed_hash, target_hash) == 0) {
            printf("[УСПЕХ] Паролата е: %s\n", guess);
            return;
        }
    }
    printf("[НЕУСПЕХ] Паролата не е 4-цифрен ПИН.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Употреба: %s '<хеш>'\n", argv[0]);
        return 1;
    }
    crack_pin(argv[1]);
    return 0;
}
