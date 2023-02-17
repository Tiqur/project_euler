#include <stdio.h>
#include <stdlib.h>

int is_divisible_by_all(int factors[], int num) {
  for (int i = 0; factors[i] != 0; i++)
    if (num % factors[i] != 0) return 0;
  return 1;
}

int main(void) {
  const int input = 20;
  int factors[input-1];

  // Init factors
  for (int i = 0; i <= input; i++)
    factors[i] = i; 

  // Remove factors that don't matter
  // ( 5 doesn't matter if input is 20 because the answer will always
  // be a multiple of 20, and 20 is divisiable by 5 )
  for (int i = input; i > 0; i--)
    for (int j = i; j > 0; j--)
      if (input % i == 0 && i % j == 0)
        factors[j] = 0;

  // Shift elements down so that there are no 0's between  
  for (int i = 0; i < input; i++) {
    if (factors[i] == 0) {
      for (int j = i+1; j < input; j++) {
        if (factors[j] != 0) {
          factors[i] = factors[j];
          factors[j] = 0;
          break;
        }
      }
    }
  }

  // Iterate and increment by input until critera is met 
  int num = input;
  for (; !is_divisible_by_all(factors, num); num+=input);
  printf("%d\n", num);

  return 0;
}
