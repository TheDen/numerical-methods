/* 
   Program which calculates plot points for the weierstrass_function at an arbitrary range and increment level
*/
#include <stdio.h>
#include <stdlib.h>                                                              
#include <math.h>

int
main(int argc, char **argv) {
  
  FILE *fp;                               
  fp = fopen("weierstrass_function_plot", "w");        
  
  long double x=0;  // x and y values  
  long double y=0;  //
  
  long double a;    // 0<a<1 condition must be met
  long double b;    // b must be a positive odd integer and [ab > 1+(3/2)Pi]

  a = 0.5;
  b = 15;
  
  long double n;
  long double x_i;
  long double x_f;
  long double h;
  x_i = -2;         // initial x-value
  x_f = 2;          // final x-value
  h = 0.00001;       // step-size
  
  int n_max = 260;  // max n-summation
  
  printf("Calculating %.0lf points...\n", ceil(((x_f-x_i)/h)));
  
  for (x=x_i; x<=x_f; x+= h) {
    for (n=0; n<n_max; n++) {
      y += pow(a,n)*cos(pow(b,n)*M_PI*x);
      if (isnan(y)) {
	printf("Error: NaN\n");
	exit(EXIT_FAILURE);
      }           
    }
    fprintf(fp,"%Lf %Lf\n", x, y);
    y = 0;    
  }
  
  return 0;
}
