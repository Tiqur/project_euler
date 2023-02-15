# Problem
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

# Solution
To validate palindromes, I first created two pointers, one at the first and last index of the integer.  Then I compared the two, if they are not equal, then it returns false.  If they are equal, it continues shifting the pointers inwards inwards until it either finds an inequality, or meets in the center ( in which case the number is not a palindrome ).  As for finding the largest, since the range was so small I decided just to brute force it using two nested loops. 

O(n^2)
```c
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
```
