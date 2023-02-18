#include <stdio.h>
#include <math.h>


int is_prime(int num) {
  for(int i = 2; i <= sqrt(num); i++)
    if (num % i == 0)
      return 0;
  return 1;
}

int main(void) {
  int input = 10001;
  int prime_count = 1;
  int num = 1;

  // Generate and check primes
  while (prime_count != input) {
    num+=2;
    if (is_prime(num))
      prime_count++;
  }
    
  printf("%d\n", num);


  return 0;
}
