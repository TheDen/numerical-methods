/* 
   Compile as "gcc -Wall -o program program.c -lgmp" 
 
*/

#include <stdio.h>
#include <stdlib.h>                                               // library included for qsort, RAND_MAX, rand, srand
#include <math.h>                                                 // include the C numerics library for mathematical functions
#include <gmp.h>
//#include <time.h>                                                 // include C time library for using time() function as seed

void factorial(int, mpz_t);
void product_factorial(int, mpf_t);
void levi_civita(int, int, mpf_t);

int
//main(int argc, char **argv) {
main(int argc, char **argv) {
  
  //  char inputStr[1024];
  //  scanf("%1024s" , inputStr);  
  //  mpz_t  y;
  //  mpz_init (y);
  //  mpz_set_str(y, inputStr, 10);
  //  gmp_printf ("%Zd\n", y);
  /*
    int l;
  for (l=0; l<argc; l++) {
    printf("%s\n", argv[l]);
  }
  */
  

  int n=3;
  int sigfigs = 10;
  int i, j, k;

  //Initialising the array
  mpf_t a[n-1];
  for (i=0; i<=n-1; i++) {
    mpf_init(a[i]);
  }
  
  for (i=0; i<=n-1; i++) {
    mpf_set_d (a[i], i+1);
  }
  
  //Calculating the levi_civita
  for (i=0; i<=n-1; i++) {
    levi_civita(n,i,a[i]);
  }
  gmp_printf ("%.*Ff\n", sigfigs, a[n-1]); //Should be the return of levi_civita
  

  /*
  int l;
  mpf_t cross3, matrix;
  
  mpf_set_d (cross3, 0);
  mpf_init(cross3);
  mpf_set_d (matrix, 1);
  mpf_init(matrix);

  double A[9];
  for (i=0; i<9; i++) {
    A[i] = i+1;
    //   printf("%lf ", A[i]);
  }
  
  
  for (i=1; i<=3; i++) {
    k = 1;
    j = 1;
    for (k=1; j<=3; j++) {
      for (k=1; k<=3; k++) {
	mpf_set_d (a[0], i);
	mpf_set_d (a[1], j);
	mpf_set_d (a[2], k);
	
	//for (l=0; l<=n-1; l++) {
	//  gmp_printf ("%.*Ff", 0, a[l]);
	//}
	//printf(" ");
	//printf("%d%d%d ", i, j, k);

	for (l=0; l<=n-1; l++) {
	  levi_civita(n,l,a[l]);
	}
	mpf_set_d (matrix, A[i]*A[j+3]*A[k+6]);
	mpf_mul (a[n-1], a[n-1], matrix);
	mpf_add (cross3, cross3, a[n-1]);
	//gmp_printf ("%.*Ff\n", sigfigs, cross3); 
	
      }
    }

  }
  gmp_printf ("%.*Ff\n", sigfigs, cross3); 
  */  

  
  //FACTORIAL CALL AND PRINT
  k=0;
  printf("Enter number: ");
  scanf("%d", &k);
  mpz_t r;
  mpz_init(r);
  factorial(k, r);
  gmp_printf ("%d! = %Zd\n", k,  r);
  
  return 0;
}

void levi_civita(int n, int k, mpf_t x) {
  
  int i,j;
  mpf_t b[n-1];
  mpf_init(b[k]);
  mpf_set (b[k], x);
  if (k==n-1){
    mpf_t val3, val2, sub;
    mpf_init(val2);
    mpf_init(val3);
    mpf_set_ui (val3, 1);
    mpf_init(sub);
    for (i=0; i<=n-2; i++) {
      for (j=i+1; j<=n-1; j++) {
	mpf_sub (sub, b[j], b[i]);
	mpf_mul(val3, sub, val3);
      }
    }
    product_factorial(n,val2);
    mpf_mul(val3, val3, val2);
    mpf_set (x, val3);
  }
}


void product_factorial(int n, mpf_t x) {
  
  int i;
  mpf_init(x);
  mpz_t fact;
  mpz_init(fact);
  mpz_t val;
  mpz_init(val);
  mpz_set_str(val, "1", 10);
  mpf_t one;
  mpf_init(one);
  mpf_set_str(one, "1", 10);
    
  for (i=1; i<=n-1; i++) {
  factorial(i,fact);
  mpz_mul(val, fact, val);
  }
  mpf_set_z (x, val);
  mpf_div (x, one, x);
}
  
void factorial(int i, mpz_t x) {
  if (i==0) {
    mpz_set_str(x, "1", 10);
  }
  else if (i<0) {
    i = -i;
    mpz_fac_ui (x, i);
    mpz_neg (x, x);
  }
  else {     
    mpz_fac_ui (x, i);
  }
}

