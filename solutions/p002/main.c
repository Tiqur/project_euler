#include <stdio.h>

#define UPPER_BOUND 4000000

int main(void) {
  // Init to two since it's not a multiple of 4 ( lower )
  int sum = 2;

  int i = 0;
  int p = 2;

  // Iterate over even numbers in sequence
  while (sum < UPPER_BOUND) {
    sum += 4 * p + i;

    // Cache i for later use in p
    int cache = i;
    i = p;
    p = 4 * p + cache;
  }

  // Print answer
  printf("%d\n", sum);

  return 0;
}
