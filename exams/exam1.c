/****************************************************************************** Online C Compiler.
Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.*******************************************************************************/#include <stdio.h>
#include <math.h>double rk4(double y0, double x0, double h, double (*fun)(double))
{
double y1;
double k1,k2,k3,k4;
k1 = h*fun(x0 );
k2 = h*fun(x0+h/2.);
k3 = h*fun(x0+h/2.);
k4 = h*fun(x0+h );
y1 = y0 + (k1+2.*k2+2.*k3+k4)/6.;
return y1;
}double fun(double t){
return sin(8*t)+cos(4*t)-4;
}double Euler(double y0, double x0, double dt, double (*fun)(double)){
return y0 + dt*fun(x0);
}int main()
{
double dt=0.1;
double t=2.9;
int N= t/dt;
double y1=0;
double x0=0;
for (int i=0; i<N; i++ )
y1= Euler(y1, i*dt, dt, fun);
printf("%lf \n", y1);
double y_e=0;
dt = 0.0001;
N = t/dt;
for (int i=0; i<N; i++ )
y_e= Euler(y_e, i*dt, dt, fun);
printf("exact %lf \n", y_e);
printf("Euler Error is = %lf \n", (y_e-y1)/y_e);
dt =0.1;
N =t/dt;
y1=0;
for (int i=0; i<N; i++ )
y1= rk4(y1, i*dt, dt, fun);
printf("rk4 is %lf \n", y1);
dt = 0.0001;
N =t/dt;
y_e=0;
for (int i=0; i<N; i++ )
y_e= rk4(y_e, i*dt, dt, fun);
printf("rk4 Error is = %lf \n", (y_e-y1)/y_e);
return 0;
}


