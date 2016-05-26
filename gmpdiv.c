/* 
   Compile as "gcc -Wall -o program program.c -lgmp" 
   Divides var1 by var2 with arbitrary precision
*/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>   
#include <gmp.h>

void division(int var1, int var2, int digits) {
  mpf_t x;
  mpf_init(x);
  mpf_t y;
  mpf_init(y);
  mpf_set_d(x, var1);
  mpf_set_d(y, var2);
  mpf_div (x, x, y);
  gmp_printf ("%.*Ff\n", digits, x);
}

int
main(int argc, char **argv) {
  division(1,3,10);
  return 0;
}
