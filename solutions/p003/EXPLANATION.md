
# Problem
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

# Naive Solution
The naive way to do this would be to iterate over all possible numbers and individually check if they are both prime and a factor of the input.  This can be optimized a bit by setting the condition in the for loop to "i < sqrt(input)" and by setting i's default value as 3 and increment by 2.  This way you never check even numbers ( which can never be prime apart from 2 ) and you are only checking integers that are possible factors.

O(N^(3/2))
```c
  long input = 600851475143;
  long largest_prime = 0;
 
  for (long i = 2; i < input; i++) {
    if (input % i == 0 && is_prime(i))
	    largest_prime = i;
  }
	
	printf("The largest prime factor is %d", largest_prime);
```
# Optimized Solution
I used the Sieve of Eratosthenes to efficiently generate all primes between 2 and the square root of the input.  This way no checks go to waste.  Then I iterated backwards through the primes and stopped the loop on the first instance of a prime factor ( guaranteed to the largest so no need to continue iterating ).

O(N log log N)
```c
// Implement function to get primes up to x
Vector get_primes_to(int upper_bound) {
  int* all_nums = (int*)malloc(upper_bound*sizeof(int));
  Vector primes = CreateVector();

  // Init numbers
  for (int i = 2; i < upper_bound; i++)
    all_nums[i] = i;

  // Implement Sieve of Eratosthenes
  for (int i = 2; i < sqrt(upper_bound); i++)
    if (all_nums[i] != 0)
      for (int j = i*i; j < upper_bound; j+=i)
        all_nums[j] = 0;

  // Append primes to vec
  for (int i = 0; i < upper_bound; i++)
    if (all_nums[i] != 0)
      VectorPushPack(&primes, all_nums[i]);

  return primes;
}

int main(void) {
  long input = 600851475143;
  int upper_bound = round(sqrt(input));
  Vector primes = get_primes_to(upper_bound);

  // Check prime factors
  for (int i = primes.size-1; i > 0; i--) {
    if (input % VectorGet(&primes, i) == 0) {
      printf("The largest prime factor is: %d\n", VectorGet(&primes, i));
      break;
    }
  }

  return 0;
}
```
> I used my own Vector implementation with only the required functions
