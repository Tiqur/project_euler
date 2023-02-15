#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Implement Vector
typedef struct Vector {
  int* array;
  int size;
  int capacity;
} Vector;

Vector CreateVector() {
  Vector vec;
  vec.array = (int*)malloc(8*sizeof(int));
  vec.size = 0;
  vec.capacity = 8;
  return vec;
};

void VectorIncreaseCapacity(Vector* vec) {
  int *new_arr = (int*)malloc(2*vec->capacity*sizeof(int));

  for (int i = 0; i < vec->size; i++)
    new_arr[i] = vec->array[i];

  free(vec->array);
  vec->capacity*=2;
  vec->array = new_arr;
}

void VectorPushPack(Vector* vec, int value) {
  if (vec->size == vec->capacity)
    VectorIncreaseCapacity(vec);

  vec->array[vec->size] = value;
  vec->size++;
}

int VectorGet(Vector* vec, unsigned int index) {
  return vec->array[index];
}

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
