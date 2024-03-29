#include <stdio.h>

#define INPUT 1000
#define A 3
#define B 5


int main(void) {
  // The problem states that it wants the sum of all multiples of a and b UNDER INPUT.  So subtracting one will accomplish this.
  int x = INPUT-1;
  
  // Just to be explicit 
  int first_term_a = A;
  int first_term_b = B;

  // Get the max multiple of a and b below x
  // Ingeger division is intentional.  We do NOT want floating point numbers. 
  int last_term_a = (x/first_term_a)*first_term_a;
  int last_term_b = (x/first_term_b)*first_term_b;

  // Get length of each progression (integer division is intentional)
  int progression_len_a = x/first_term_a;
  int progression_len_b = x/first_term_b;

  // Get the arithmetic series (sum) of each progression
  int series_a = ((first_term_a + last_term_a)/2*progression_len_a);
  int series_b = ((first_term_b + last_term_b)/2)*progression_len_b;

  // Total sum of ALL multiples of first_term_a and first_term_b that are less than INPUT
  int total_sum = series_a + series_b;

  // Since the above sum includes overlapping multiples, we have to account for that and subtract it:
  // Least common multiple
  int lcm = first_term_a*first_term_b;

  // X divided by LCM
  int x_lcm_diff = x/lcm;

  // Greatest common factor
  int gcf = x_lcm_diff * lcm;

  // Combine LCM and GCF
  int d = lcm + gcf;

  // number to subtract to account for overlapping multiples
  int mul_sub = d*x_lcm_diff/2;

  printf("ANS: %d\n", total_sum-mul_sub);
  return 0;
}
