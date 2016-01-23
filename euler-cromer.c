/* Program which calculates the angular displacement and angular velocity corresponding with time of a 
physical pendulum and prints them to files for phase space and angular displacement vs time plots.
Euler-Cromer numerical integration method is used for the calculations  */
#include <stdio.h>                                
#include <stdlib.h>                                                                                      
#include <math.h>                          // Included the C numerics library for mathematical functions

#define N 4000                             // Number of steps to perform and size of the arrays
                                           // N*step-size = x-axis time scale
int
main(int argc, char **argv) {
  
  FILE *f1p;                               // File pointer variable
  f1p = fopen("theta_vs_t", "w");          // fopen() function in "write" mode for the file 
  FILE *f2p;              
  f2p = fopen("theta_vs_angular_vel", "w"); 
  
  int i;                                   // Integer for loops
  double const g = 9.8;                    // Constant for gravity
  double h;                                // Step size variable
  double omega[N];                         // Value of dtheta/dt, i.e., angular velocity 
  double theta[N];                         // Value of theta, angle in radians
  double t = 0;                            // Time with initial 0 value increments by step size 
  double F_0;                              // Amplitude of driving force
  double F_W;                              // Angular frequency of driving force
  double l;                                // Length of the pendulum
  double c;                                // Damping constant
  double w_0;                              // Used for definition of g/l

  printf("Please enter the step size: ");  // Prompting user for the variables 
  scanf("%lf", &h);                        // and initial conditions
  printf("Please enter the string length: ");
  scanf("%lf", &l);
  printf("Please enter the damping factor: ");
  scanf("%lf", &c);
  printf("Please enter the amplitude of the driving force: ");
  scanf("%lf", &F_0);
  printf("Please enter the angular frequency of the driving force: ");
  scanf("%lf", &F_W);
  printf("Please enter initial angle: ");  
  scanf("%lf", &theta[0]);
  printf("Please enter initial angular velocity: ");
  scanf("%lf", &omega[0]);
  
  w_0 = g/l;                                     // Defining w_0 shorthand for calculations
  fprintf(f1p,"%lf %lf\n", t, theta[0]);         // Printing initial conditions to files  
  fprintf(f2p,"%lf %lf\n", theta[0], omega[0]);  // Theta vs t and omega vs t plot files
  
  for (i=0; i<N-1; i++) {                        // Loops with N-1 break condition to fit arrays
    t += h;                                      // Incrementing time by step size
    omega[i+1] = omega[i] - w_0*sin(theta[i])*h  // Application of Euler method
      - c*omega[i]*h + F_0*sin(F_W*t)*h;         // diff(omega,t) value multiplied by step size 
    theta[i+1] = theta[i] + omega[i+1]*h;        // Application of Euler-Cromer method
    if (theta[i+1]>M_PI) {                       // Conditions to maintain theta in +/-Pi range
      theta[i+1] -=  2*M_PI;                     // M_PI math.h constant for Pi
    }
    if (theta[i+1]<-M_PI) {
      theta[i+1] +=  2*M_PI;
    }
    fprintf(f1p,"%lf %lf\n", t, theta[i+1]);     // Iterative printing of values to the set of files
    fprintf(f2p,"%lf %lf\n", theta[i+1],  omega[i+1]);
  }
  return 0;
}
