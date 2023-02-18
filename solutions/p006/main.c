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
