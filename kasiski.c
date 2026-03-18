#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000

void cleanText(char *text) {
  int i, j = 0;

  for (i = 0; text[i]; i++) {
    if (isalpha(text[i])) {
      text[j++] = toupper(text[i]);
    }
  }

  text[j] = '\0';
}

void findDivisors(int distance, int freq[]) {
  for (int i = 2; i <= distance; i++) {
    if (distance % i == 0) {
      freq[i]++;
    }
  }
}

int main() {

  char text[MAX];
  int freq[MAX] = {0}, key_decrypt;
  FILE *fptr1;

  fptr1 = fopen("encrypted.txt", "r");
  fgets(text, sizeof(text), fptr1);

  cleanText(text);

  int len = strlen(text);

  printf("\nRepeated Trigrams:\n");

  for (int i = 0; i < len - 2; i++) {

    char trigram[4];
    trigram[0] = text[i];
    trigram[1] = text[i + 1];
    trigram[2] = text[i + 2];
    trigram[3] = '\0';

    for (int j = i + 1; j < len - 2; j++) {

      if (strncmp(trigram, &text[j], 3) == 0) {

        int distance = j - i;

        printf("Found \"%s\": Pos %d & Pos %d -> Distance: %d\n", trigram, i, j,
               distance);

        findDivisors(distance, freq);
      }
    }
  }

  printf("\nPossible key lengths:\n");

  for (int i = 2; i < 20; i++) {
    if (freq[i] > 0) {
      printf("Length %d -> %d times\n", i, freq[i]);
    }
    if (freq[i] > key_decrypt) {
      key_decrypt = freq[i];
    }
    
  }
  printf("%d \n",key_decrypt);
  return 0;
}