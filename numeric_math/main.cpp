#include"main.h"
#include"Interpolation.h"
#include"Integration.h"
#include "function.h"
#include "Solver_ODE.h"

double quadrat(double in);
double df(double t, double x);
double f(double t);

int main() {
	double x,y; 
	vector2D pntVector = { {-2,4}, {-1,1}, {0,0}, {1,1},{2,4} };
	// define function handler
	function myFunction(0.001, quadrat);
	// Interpolation Method
	Interpolation function(pntVector);
	Integration Integrator;
	Solver_ODE ode(0.0, 3, 0.001, df);
	std::vector<double> pntX = { -2,-1,0,1,2 };
	std::vector<double> pntY = { 4,1,0,1,4 };
	double a = 0, b = 25;
	int flag = 1;

	while (1) {
		cout << endl;
		cout << "============================" << endl;
		cout << "Please input x: " << endl;
		cin >> x;	

		// Integration
		cout << "Integration: " << Integrator.InterpolarQuadratur(function, a, x) << endl;
		cout << "Simpson Built In: " << myFunction.IntegrateSimpson(a, x) << endl;
		cout << "Trapez Built In: " << myFunction.IntegrateSumTrapez(a, x) << endl;
		cout << "Derivative E Euler: " << myFunction.DerivativeExplicitEuler(x) << endl;
		cout << "Derivative I Euler: " << myFunction.DerivativeImplicitEuler(x) << endl;
		cout << "Modified Euler: " << myFunction.DerivativeModifiedEuler(x) << endl;

		cout << "Numerical Euler E of df at t: " << ode.Euler_Explicit(x) << endl;
		cout << "Numerical Euler I of df at t: " << ode.Euler_Implicit(x) << endl;
		cout << "Solution of df at t: " << f(x) << endl;
		
		////Extrapolation
		//cout << "Lagrange extrapolation: " << function.lagrange(x) << endl;
		//cout << "Newton extrapolation: " << function.newton(x) << endl;

		//function.getInfo();
		getchar();
	}
}

// define function input
double quadrat(double in) {
	return in*in;
}

double df(double t, double x) {
	return (1 - exp(t)) * x / (1 + exp(t));
}

double f(double t){
	return ((12 * exp(t)) / ((1 + exp(t)) * (1 + exp(t))));
}
