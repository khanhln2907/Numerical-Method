#include "Integration.h"

Integration::Integration()
{
}

Integration::~Integration()
{
}

double Integration::InterpolarQuadratur(Interpolation& function, double lowerBnd, double upperBnd) {
	// Calculate operating point
	double interval = upperBnd - lowerBnd;
	double size = interval / this->dx;
	double* operatingPts = new double[size + 1];
	operatingPts[0] = lowerBnd;
	double sum = function.lagrange(operatingPts[0]) * dx;
	for (int i = 1; i <= size; i++) {
		operatingPts[i] = operatingPts[i - 1] + this->dx;
		sum += function.lagrange(operatingPts[i]) * dx;
	}
	delete[] operatingPts;
	return sum;
}
// Template and explicit declaration - Example of using Template
// Interpolator Quadratur
// Interpolation function(points2D) --> Integrator.InterpolarQuadratur(function, a, b);
template <typename T> T Integration::InterpolarQuadratur(Interpolation function, T lowerBnd, T upperBnd) {
	// Calculate operating point
	T interval = upperBnd - lowerBnd;
	T size = interval / this->dx;
	T* operatingPts = new T[size+1];
	operatingPts[0] = lowerBnd;
	T sum = function.lagrange(operatingPts[0])*dx;
	for (int i = 1; i <= size; i++) {
		operatingPts[i] = operatingPts[i-1] + this->dx;
		sum += function.lagrange(operatingPts[i]) * dx;
	}
	return sum;
}

template double Integration::InterpolarQuadratur(Interpolation,double, double);


// Trapez Rules
double Integration::SumTrapez(Interpolation function, double lowerBnd, double upperBnd) {
	return lowerBnd;
}
