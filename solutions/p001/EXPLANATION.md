# Problem:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.  


# Naive Solution:
Using a single for loop iterating one by one would be wasteful since it would also check numbers that have no relation to the factors whatsoever.

O(n)
```c
  for (int i = 0; i < UPPER_BOUND; i++)
    if (i % 5 == 0 || i % 3 == 0)
      sum += i;
```
> This method would also unnecessarily check prime numbers

# Optimized Solution
Instead, I opted for using two for loops that increment by 3 and 5 respectively ( the two chosen factors ).  This approach is significantly faster when there is a larger upper_bound.

O(n)
```c
  for (int i = 0; i < UPPER_BOUND; i+=3)
    sum += i;

  for (int i = 0; i < UPPER_BOUND; i+=5)
    if (i % 3 != 0)
      sum += i;
```
> The "if (i % 3 != 0)" is required  to ensure that duplicates are not included in the sum.

Alternatively, if this was required to be dynamic ( lots of factors ), I would probably use a HashSet and two loops ( nested ).  The outer for the array of factors, and the inner to add each multiple below the upper bound to the HashSet.  Finally I would have another loop ( not nested ) to calculate the sum of all elements in the HashSet.
