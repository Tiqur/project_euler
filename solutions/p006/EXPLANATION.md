# Problem

The sum of the squares of the first ten natural numbers is,

$1^2+2^2+...+10^2=385$

The square of the sum of the first ten natural numbers is,

$(1+2+...+10)^2=3025$

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
$3025-385=2640.$

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

# Solution
This one was really straightforward.  Just create two variables one for the square of the sum, one for the sum of the squares, calculate their respective values, then subtract them to find the difference.  For (much) larger inputs, you might have to create a custom library to represent very large integers as strings ( to avoid overflows ).

```c
#include <stdio.h>

int main(void) {
  const int input = 100;
  unsigned int sum_of_squares = 0;
  unsigned int square_of_sum = 0;

  // Get sum of squares
  for (int i = 0; i <= input; i++)
    sum_of_squares += i*i;

  // Get sum
  for (int i = 0; i <= input; i++)
    square_of_sum += i;

  // Square it
  square_of_sum*=square_of_sum;

  printf("Answer: %d\n", square_of_sum - sum_of_squares);

  return 0;
}
```
