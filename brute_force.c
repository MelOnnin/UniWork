#include <ctype.h>
#include <stdio.h>
#include <string.h>
FILE* fptr;

char caesar_decrypt_char(char c, int k) {
    if (isupper(c)) {
        return ((c - 'A' - k + 26) % 26) + 'A';
    }
    else if (islower(c)) {
        return ((c - 'a' - k + 26) % 26) + 'a';
    }
    return c;
}
int main()
{
    char encrypted[500];
    char decrypted[500];
    fptr=fopen("encrypted.txt","r");
    fgets(encrypted, sizeof(encrypted), fptr);
    for(int a=0;a<25;a++)
    {
        for (int i = 0; i < strlen(encrypted); i++) 
        {
            decrypted[i] = caesar_decrypt_char(encrypted[i], a);
        }
        printf("Decrypted string: %s \n", decrypted);
    }
      /*this took less time than I expected it was actually really easy to just copy paste what I wrote for the previous
      assignment and repeat it in the loop 25 times since I didn't know the key*/
      //maybe I can have it be filtered through a list of words and that's how it gives me the one that's actually readable
}