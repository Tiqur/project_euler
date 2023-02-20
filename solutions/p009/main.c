#include <stdio.h>


int main(void) {
  const int input = 1000;

  for (int c = 0; c < input; c++)
    for (int b = 0; b < c; b++)
      for (int a = 0; a < b; a++)
        if (a*a + b*b == c*c && a + b + c == input)
          printf("%d * %d * %d = %d\n", a, b, c, a*b*c);

  return 0;
}
