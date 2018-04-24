#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

double gauss(double x, double s)
{
  double centro = 1.0;

  double pi = 3.14159;
  
  double a = 1/(s*pow(2.0*pi, 0.5));

  double b = -(x-centro)*(x-centro)/(2.0*s*s);

  return exp(b);
}

int main()
{
  double D = 1.0;

  double T = 3.0;

  double dt = 1e-5;

  double dx = pow(D*dt, 0.5);

  double L = 2.0;

  double s = 0.1;

  int nx = (L/dx) + 1;

  int nt = (L/dt) + 1;

  double denominador = 1 + (2.0*dt*D/(dx*dx));

  double numerador = dt*D/(dx*dx);

  int n1 = nx/2;
  

  double* nuevo = new double[nx];

  double* viejo = new double[nx];

  double* original = new double[nx];

  for (int i = 0; i < nx; i++)
    {
      viejo[i] = gauss(i*dx, s);

      original[i] = gauss(i*dx, s);

      if( (i==0) || (i==nx-1) )
	{
	  viejo[i] = 0.0;
	  original[i] = 0.0;
	}
    }

  while(viejo[n1] > 0.5 )
     {
       
      for(int i = 1; i < nx-1; i++)
	{
	  double a  = numerador*(viejo[i+1] + viejo[i-1] - 2.0*viejo[i]);

	  nuevo[i] = a + viejo[i];
	}

      for(int i = 1; i < nx-1; i++)
	{
	  viejo[i] = nuevo[i];
	}
    }

  for(int i = 0; i < nx; i++)
    {
      cout << i*dx << " " << nuevo[i] << " " << original[i] << endl;
    }

  return 0;
}

  
      
