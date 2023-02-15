#include <stdio.h>
#include <math.h>

// Check if palindrome
int is_palindrome(int value) {
  // Create two pointers
  int p2 = 0;
  int len = log10(value) + 1;

  while (1) {
    int p1 = len-p2-1;
    int v1 = (int)(value / pow(10, p1)) % 10;
    int v2 = (int)(value / pow(10, p2)) % 10;

    // If numbers at each pointer do not match, then it is not a palindrome
    if (v1 != v2)
      return 0;

    // Found middle.  If it hasn't returned false by now, then it is a palindrome
    if (p1 == p2 || p1 < p2)
      return 1;

    p2++;
  }
}

int main(void) {
  // Init largest ( start at 0 so that any palindrome created is larger )
  int largest = 0;

  // Iterate through all possible palendromes
  for (int i = 999; i > 0; i--)
    for (int j = 999; j > 0; j--)
      if (is_palindrome(i * j) && i * j > largest)
        largest = i * j;

  printf("Largest palindrome: %d\n", largest);
  return 0;
}
