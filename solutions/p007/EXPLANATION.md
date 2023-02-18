# Problem

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

# Solution
All I had to do for this one was create a loop check if the number is prime ( if so, increment prime_count ), and break it when the prime_count variable reached it's target.  The only minor optimization I used was in the is_prime function.  Instead of checking all factors, only check up to the square root of the number ( no reason to go beyond that since anything else would not divide in equally ).
```c
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
```

