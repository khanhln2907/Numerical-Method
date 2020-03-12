#include"main.h"
#include"Interpolation.h"
#include"Integration.h"
#include "function.h"

double quadrat(double in);

int main() {
	double x,y; 
	vector2D pntVector = { {-2,4}, {-1,1}, {0,0}, {1,1},{2,4} };
	// define function handler
	function myFunction(0.001, quadrat);
	// Interpolation Method
	Interpolation function(pntVector);
	Integration Integrator;
	std::vector<double> pntX = { -2,-1,0,1,2 };
	std::vector<double> pntY = { 4,1,0,1,4 };
	double a = 0, b = 25;
	int flag = 1;

	cout << myFunction.out(5) << endl;
	while (1) {
		cout << endl;
		cout << " Please input x: " << endl;
		getchar();
		cin >> x;	

		// Integration
		cout << "Integration: " << Integrator.InterpolarQuadratur(function, a, x) << endl;
		cout << "Integration Built In: " << myFunction.integralInterpolarQuadratur(a, x) << endl;


		////Extrapolation
		//cout << "Lagrange extrapolation: " << function.lagrange(x) << endl;
		//cout << "Newton extrapolation: " << function.newton(x) << endl;

		//function.getInfo();
	}
}

// define function input
double quadrat(double in) {
	return in*in;
}
