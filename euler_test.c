#include <stdio.h>
#include <stdlib.h>                                                                  // Included library for exit() function
#include <math.h> 

//double function_eval(double, double, double);                                      // Function to evaluate the mathematical function when called
//double diff_function_eval(double, double, double);                                 // Function to evaluate the mathematical differentiated function when called

#define N 10000

int
main(int argc, char **argv) {
  
  int i;
  double h;
  double omega[N];
  double theta[N];
  double t;
  
  double w_0;
  double c;
  double F_0, F_W;
  F_0 =  0;
  F_W = 0;
  c = 2;
  w_0 = 20;
  
  h = 0.01;
  
  t = 0;
  omega[0] = 0;
  theta[0] = 10;
  
  
  //  printf("%lf %lf\n", t, theta[0]);
  printf("%lf %lf\n", theta[0], omega[0]);

  double k1, k2;
  double x, y;
  
  for (i=0; i<N-1; i++) {
    t += h;
    k1 = h*(-omega[i]*c-w_0*theta[i]+(F_0*sin(F_W*t)));
    x = theta[i] + (h/2);
    y = omega[i] + (0.5*k1);
    k2 = h*(-y*c-w_0*x+(F_0*sin(F_W*t)));
    omega[i+1] = omega[i] + k2;
    theta[i+1] = theta[i] + (h*omega[i+1]);
    // printf("%lf %lf\n", t, theta[i+1]);
    printf("%lf %lf\n", theta[i+1], omega[i+1]);

  }

  /* driven damped pendulum 
  for (i=0; i<N-1; i++) {
    t += h;
    omega[i+1] = omega[i] + h*(-omega[i]*c-w_0*theta[i]+(F_0*sin(F_W*t))); 
    theta[i+1] = theta[i] + (h*omega[i+1]);
    printf("%lf %lf\n", t, theta[i+1]);
  }
  */
  
  
  /* For damped pendulum
     for (i=0; i<N-1; i++) {
     t += h;
     omega[i+1] = omega[i] + h *(-omega[i]*c-w_0*theta[i]); 
     theta[i+1] = theta[i] + (h*omega[i+1]);
     printf("%lf %lf\n", t, theta[i+1]);
     }
  */
		
  
  /* For undamped pendulum
     for (i=0; i<N-1; i++) {
    t += h;
    omega[i+1] = omega[i] - (h*w_0*theta[i]);
    theta[i+1] = theta[i] + (h*omega[i+1]);
    printf("%lf %lf\n", t, theta[i+1]);
  }
  */
  
  return 0;
  
}
