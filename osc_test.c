#include <stdio.h>
#include <stdlib.h>                                                                  // Included library for exit() function
#include <math.h> 

//double function_eval(double, double, double);                                      // Function to evaluate the mathematical function when called
//double diff_function_eval(double, double, double);                                 // Function to evaluate the mathematical differentiated function when called

#define N 100

int
main(int argc, char **argv) {
  
  int i;
  double t;
  double h;
  double diff_y;
  double A = 0;
  double B = 20;
  double w_0 = 1;
  
  double y[N];				      

  h = 0.25;
  t = 0;
  y[0] = A;
  printf(" %lf %lf\n", t, y[0]);
  
  for (i=-; i<N-1; i++) {
   
    y[i+1] = y[i] + (h*
  }
    
  
    
    
    





  /* Simple Euler's method
  int i;
  double t;
  double h;
  double diff_y;
  double A = 0;
  double B = 20;
  double w_0 = 1;
  
  h = 0.00025;
  double y[N];
  t = 0;
  y[0] = A;
  printf(" %lf %lf\n", t, y[0]);
  for (i=0; i<N-1; i++) {
    diff_y = -A*sin(w_0 * t)*w_0+B*cos(w_0 * t)*w_0;
    y[i+1] = y[i] + (h*diff_y);
    t += h;
    printf(" %lf %lf\n", t, y[i+1]);
  }
  */
    
    

  
  


  /*
    double i;
    double A, B, k, m, w_0, eom, t;
  
  A = 2;
  B = 3;
  k = 0.5;
  m = 2;
  w_0 = sqrt(k/m);
  
  for (i = 0; i<100; i+= 0.25) {
    t = i;
    eom = A * sin(w_0 * t) + B * cos(w_0 * t);
    printf("%10lf %10lf\n", t, eom);
  }
  */
  
  
  
return 0;
}
