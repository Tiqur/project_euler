# Problem

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

$a2 + b2 = c2$

For example, $32 + 42 = 9 + 16 = 25 = 52$.

There exists exactly one Pythagorean triplet for which $a + b + c = 1000$.  
Find the product abc.

# Solution
Use a triple nested for loop and iterate through all possibilities and check if the criteria are met.  It can be slightly optimized by setting the loop's bounds to one another ( which works because of this criteria stated in the problem description:  "a < b < c" ).
```c
#include <stdio.h>


int main(void) {
  const int input = 1000;

  for (int c = 0; c < input; c++)
    for (int b = 0; b < c; b++)
      for (int a = 0; a < b; a++)
        if (a*a + b*b == c*c && a + b + c == input)
          printf("%d * %d * %d = %d\n", a, b, c, a*b*c);

  return 0;
}
```

