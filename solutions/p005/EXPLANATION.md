
# Problem
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

# Naive Solution
The naive solution is to compare every number with every factor.  This results in many unnecessary checks and will be much slower.
```c
int is_divisible_by_all(int factors[], int num) {
  for (int i = 0; factors[i] != 0; i++)
    if (num % factors[i] != 0) return 0;
  return 1;
}

const int input = 20;
int factors[input-1];

// Init factors
for (int i = 0; i <= input; i++)
  factors[i] = i; 

int num = input;
while (!is_divisible_by_all(factors, num)) {
	num++;
}
```

# Optimized Solution
The optimized solution has the same idea, but eliminates all unnecessary comparisons.  First, it will look through the array of potential factors, and simplify it such that there are no complementary factors within it.  ( Example: If it includes 20, then it shouldn't include 5 because since the answer will always be a multiple of 20, we always know that 5 will be a factor, therefore we don't need to check it. )  Another optimization we can do is to increment by the input.  Since we are assuming the problem "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?" is inclusive, then we know that it must be a multiple of the highest possible factor which in this case is 20.
```c
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
```

