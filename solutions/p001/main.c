#include <stdio.h>

#define UPPER_BOUND 1000


int main(void) {
  unsigned int sum = 0;

  for (int i = 0; i < UPPER_BOUND; i+=3)
    sum += i;

  for (int i = 0; i < UPPER_BOUND; i+=5)
    if (i % 3 != 0)
      sum += i;

  printf("%d\n", sum);
  return 0;
}
