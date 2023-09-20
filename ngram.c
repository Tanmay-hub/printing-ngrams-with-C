#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  // Make sure the user provided an N parameter on the command line
  if (argc != 2) {
    fprintf(stderr, "Usage: %s N (N must be >= 1)\n", argv[0]);
    exit(1);
  }

  // Convert the N parameter to an integer
  int N = atoi(argv[1]);

  // Make sure N is >= 1
  if (N < 1) {
    fprintf(stderr, "Invalid N value %d\n", N);
    exit(1);
  }

  // TODO: read from standard input and print out ngrams until you reach the end of the input

  // an array containing N characters of the input string
  char N_characters[N];

  // Exits if N > number of characters in the input string
  for (int i = 0; i < N; i++) {
    N_characters[i] = fgetc(stdin);
    if (N_characters[i] == EOF) {
      exit(0);
    }
  }

  // prints the first N characters of the input string
  for (int j = 0; j < N; j++) {
    printf("%c", N_characters[j]);
  }
  printf("\n");

  // Loops through the rest of the string and prints the ngrams.
  do {
    for (int k = 0; k < N - 1; k++) {
      N_characters[k] = N_characters[k + 1];
    }
    N_characters[N - 1] = fgetc(stdin);

    if (N_characters[N - 1] == EOF) {
      break;
    }

    for (int l = 0; l < N; l++) {
      printf("%c", N_characters[l]);
    }

    printf("\n");

  } while (1);
  return 0;
}
