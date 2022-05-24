/****
 * The code solves a problem where we know the Velocity at every seconds. We know position at t=0 and
 * Our goal is to find the position at all time.
 * we use lagrange funstion to get interpolation of derivative 
 * We use rk4_using_lagarnage_int for integration in time.
 * 
*******************************************************************************/
#include <stdio.h>
#include <math.h>

double lagrange (double * x, double * y, int n, double xx)
{
    int i, j;
    double yint, ylag;
    yint = 0.0;
    for (i = 0; i <n; i ++)
    {
        ylag = 1.0;
        for (j = 0; j <n; j ++)
        {
            if (i == j)
                continue;
            ylag *= (xx - x [j]) / (x [i] - x [j]);
        }
        yint += y [i] * ylag;
    }
    return yint;
}

double rk4_using_lagarnage_int(double dt, double (*fun)(double *, double* , int, double ), double *x, double *y, int n, double xx )
{
  double y1;
  double k1,k2,k3,k4;
  k1 = dt*fun(x,  y,  n, xx);
  k2 = dt*fun(x,  y,  n,  xx+dt/2.);
  k3 = dt*fun(x,  y,  n, xx+dt/2.);
  k4 = dt*fun(x,  y, n,  xx+dt);
  y1 = (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
  return y1;
}
int main()
{
    double Time[5]={0, 1, 2, 3, 4};
    double Velocity[5]={0, 1, 2, 3, 4};
    
    double Time_start=0; double Time_End=4;
    
    int N = 20; // Number of steps we will make from Time_start to Time_End
    double dt = (Time_End- Time_start)/N; // Time Step Size or Small step in time that we going to take it
    
    double position[20]; // This will store the position values at each time step caculated using RK4 method
    position[0] = 0; /// Putting the initial Condition;
    
    
    // Moving in time using dt as single step.
    
    for(int i =1; i < N; i++)
    {
    position[i] = position[i-1] + dt*rk4_using_lagarnage_int(dt, lagrange, Time, Velocity, 5, i*dt);
        printf("At time T = %lf the caculated position is = %lf  \n", dt*i, position[i] );
    
    }
    
    
    FILE *fp=fopen("data.txt", "w");
    
    for(int i =1; i < N; i++)
    {
    position[i] = position[i-1] + dt*rk4_using_lagarnage_int(dt, lagrange, Time, Velocity, 5, i*dt);
       fprintf(fp, "%lf \t %lf  \n", dt*i, position[i] );
    
    }
    fclose(fp);
    
}
