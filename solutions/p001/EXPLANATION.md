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

An alternative, more efficient solution, would be using two for loops that increment by 3 and 5 respectively ( the two chosen factors ).  This approach is significantly faster when there is a larger upper_bound.

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

# Optimized solution
This approach stems from a purely mathmatical standpoint. At first glance we can tell that the numbers we need to sum form an arithmetic series where the first term is A or B and the last term is the greatest multiple of A or B **under** x (the input).  

If the input is 50
```
3:
3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48

5:
5, 10, 15, 20, 25, 30, 35, 40, 45
```
The method focuses on calculating the sum of arithmetic series for both sets A and B. After finding the individual sums, they are combined to determine the overall result.  

To accomplish this, we first need to get the first and last terms of each series:
1. The first term is easy, it's just A or B.
```c
// Just to be explicit 
int first_term_a = A;
int first_term_b = B;
```

2. The 2nd term is the highest multiple of A or B under the input.  We can get that by dividing the input-1 (We subtract 1 because the problem specifies the multiples must be under the input) by A and B, rounding the quotient down to the whole number, then multiplying _that_ by their A and B counterparts respectively.
```c
// Get the max multiple of a and b below x
// Ingeger division is intentional.  We do NOT want floating point numbers. 
int last_term_a = (x/first_term_a)*first_term_a;
int last_term_b = (x/first_term_b)*first_term_b;
```

3. Now that we have the highest and lowest terms of each series, we can find their sums.  To do this we can plug it into this equation:
(n = length of series)
$$S = \[ \frac{a_1+a_n}{2} \]\cdot n$$
```c
// Get the sum of each series
int series_sum_a = ((first_term_a + last_term_a)/2*series_len_a);
int series_sum_b = ((first_term_b + last_term_b)/2)*series_len_b;
```

4. Finally, we add the two sums together.
```c
// Total sum of first_term_aLL multiples of first_term_a and first_term_b that are less than INPUT
int total_sum = series_sum_a + series_sum_b;
```
This almost works, but it doesn't account for _overlapping_ multiples.  To address this, we can determine the least common multiple of A and B, and then subtract each multiple of that common multiple from the total sum.
```c
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
```

Our final answer:
```c
printf("ANS: %d\n", total_sum-mul_sub);
```
