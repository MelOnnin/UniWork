// важно е да отметна че ще се опитам без да ползвам LLM да го реша това :)
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char caesar_encrypt_char(char p, int k) {
    // TODO: 1. Превърнете p в индекс 0-25 (извадете 'A')
    // TODO: 2. Добавете ключа k
    // TODO: 3. Вземете модул 26
    // TODO: 4. Върнете обратно към ASCII (добавете 'A')
    if (isupper(p)) {
        return ((p - 'A' + k) % 26) + 'A';/*като за начало ми отне прекалено много време 
        да осъзная че всичко което се искаше вече е в този return*/
    }
    //използвах google да видя какво прави "isupper" и видях че има islower :))
    else if (islower(p)) {
        return((p - 'a' + k) % 26) + 'a'; /*отне ми 10 минути да се сетя че ако просто използвам малко "а"
        ще може да се вкарват символи които не са главни :)))*/
    
    }
    return p;
}

char caesar_decrypt_char(char c, int k) {
    if (isupper(c)) {
        // TODO: Реализирайте обратната логика.
        // ВАЖНО: Използвайте (x - k + 26) % 26
        return ((c - 'A' - k + 26) % 26) + 'A'; /*това беше лесно поне формулата е горе буквално
        просто го преписвам но със "-*/
    }
    else if (islower(c)) {
        return ((c - 'a' - k + 26) % 26) + 'a';
    }
    return c;
}

int main() {
    int a;
    char unencrypted[500];/*някой беше забравил как работят char-овете и забрави да декларира[500] 
    и се чудеше защо само една буква взима 3та година software engineer btw*/
    char encrypted[500];
    char decrypted[500];

    printf("What's the sentence you'd like to encrypt:\n");
    fgets(unencrypted, sizeof(unencrypted), stdin);//псувах по адрес на майка защото забравих че fgets съществуваше в продължение на 10 минути

    printf("And by how many letters would you want to shift it with:\n");
    scanf("%d", &a);



    for (int i = 0; i < strlen(unencrypted); i++) {
        encrypted[i] = caesar_encrypt_char(unencrypted[i], a);
    }

    for (int i = 0; i < strlen(unencrypted); i++) {
        decrypted[i] = caesar_decrypt_char(encrypted[i], a);
    }

    printf("Original string: %s", unencrypted);
    printf("Encrypted string: %s", encrypted);
    printf("Decrypted string: %s", decrypted);

    return EXIT_SUCCESS;
}
/*Като цяло май-щеше да е по-добре да си спестя 1ния час нерви за глупости и просто трябваше да ползвам
другаря GPT но поне не научих нищо*/
