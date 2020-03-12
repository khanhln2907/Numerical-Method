#include"main.h"

int main() {
	double x,y;
	vector2D pntVector = { {-2,4}, {-1,1}, {0,0}, {1,1},{2,4} };
	Interpolation function(pntVector);
	Integration Integrator;
	std::vector<double> pntX = { -2,-1,0,1,2 };
	std::vector<double> pntY = { 4,1,0,1,4 };
	double a = 0, b = 25;
	int flag = 1;

	while (1) {
		cout << endl;
		cout << " Please input x: " << endl;
		getchar();
		cin >> x;	

		// Integration
		cout << "Integration: " << Integrator.InterpolarQuadratur(function, a, x) << endl;

		//Extrapolation
		cout << "Lagrange extrapolation: " << function.lagrange(x) << endl;
		cout << "Newton extrapolation: " << function.newton(x) << endl;

		function.getInfo();
	}
}
