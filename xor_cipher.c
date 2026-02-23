#include <stdio.h>
#include <string.h>
void xor_cipher(char *text) {
int len = strlen(text);
char key = 'K';
for (int i = 0; i < len; i++) {
// TODO: Приложете XOR операция върху text[i]
    text[i]=text[i]^key;
}
}
// В main функцията добавете:
int main()
{
char data[] = "Secret";

xor_cipher(data);
printf("Encrypted: %s\n", data); // Внимание: Може да съдържа невидими символи!

xor_cipher(data);
printf("Decrypted: %s\n", data);
}
