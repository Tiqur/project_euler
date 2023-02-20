#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Return array with primes to x
int* get_primes_to(int upper_bound) {
  int* array = (int*)malloc(sizeof(int)*upper_bound);

  // Init values in array
  for (int i = 2; i < upper_bound; i++)
    array[i] = i;

  // Remove factors
  for (int i = 2; i < sqrt(upper_bound); i++)
    if (array[i] != 0)
      for (int j = i*i; j < upper_bound; j+=i)
        array[j] = 0;

  return array;
}

int main(void) {
  int input = 2000000;
  int* primes = get_primes_to(input);
  unsigned long sum = 0;

  // Add all primes
  for (int i = 0; i < input; i++)
    sum += primes[i];

  printf("%lu\n", sum);

  return 0;
}
