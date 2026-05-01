#include <stdio.h>
#include <string.h>
#include <crypt.h>

void dictionary_attack(const char *target_hash, const char *dict_file) {
    FILE *file = fopen(dict_file, "r");
    if (!file) {
        printf("Грешка при отваряне на речника!\n");
        return;
    }

    char word[256];
    printf("--- Започва Dictionary Attack ---\n");

    while (fgets(word, sizeof(word), file)) {
        word[strcspn(word, "\n")] = 0; 
        
        char *computed_hash = crypt(word, target_hash);
        
        if (strcmp(computed_hash, target_hash) == 0) {
            printf("[УСПЕХ] Паролата е намерена в речника: %s\n", word);
            fclose(file);
            return;
        }
    }
    printf("[НЕУСПЕХ] Паролата не е в речника.\n");
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Употреба: %s '<хеш>' '<речник>'\n", argv[0]);
        return 1;
    }
    dictionary_attack(argv[1], argv[2]);
    return 0;
}
