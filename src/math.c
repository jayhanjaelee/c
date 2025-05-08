#include "math.h"

int b_is_even(int n) 
{
  return (n & 1) == 1;
}

int b_is_odd(int n) 
{
  return (n & 1) == 0;
}
