#include "Integration.h"

Integration::Integration()
{
}

Integration::~Integration()
{
}

void Integration::setDt(double dt)
{
	this->dt = dt;
}

// Interpoator Integration
double Integration::InterpolarQuadratur(Interpolation& function, double lowerBnd, double upperBnd) {
	// Calculate operating point
	double interval = upperBnd - lowerBnd;
	double size = interval / this->dt;
	double* operatingPts = new double[size + 1];
	operatingPts[0] = lowerBnd;
	double sum = function.lagrange(operatingPts[0]) * this->dt;
	for (int i = 1; i <= size; i++) {
		operatingPts[i] = operatingPts[i - 1] + this->dt;
		sum += function.lagrange(operatingPts[i]) * this->dt;
	}
	delete[] operatingPts;
	return sum;
}

// Trapezoidal
double Integration::Trapezoidal(fPtr function, double lowerBnd, double upperBnd) {
	double size = (upperBnd - lowerBnd) / this->dt;
	double* pts = new double[size + 1];
	pts[0] = lowerBnd;
	double sum = function(pts[0]) * this->dt / 2;
	for (int i = 1; i <= size; i++) {
		pts[i] = pts[i - 1] + this->dt;
		if (i != size) sum += function(pts[i]) * this->dt;
	}
	sum += function(pts[static_cast<int>(size)]) * this->dt / 2;

	delete[] pts;
	return sum;
}

// Simpson Rules
double Integration::Simpson(fPtr function, double lowerBnd, double upperBnd)
{
	double h = this->dt / 2;
	double size = (upperBnd - lowerBnd) / h;

	double* pts = new double[size + 1];
	pts[0] = lowerBnd;

	double sum = 0;
	for (int i = 0; i <= (size - 2) / 2; i++) {
		pts[2 * i + 1] = pts[2 * i] + h;
		pts[2 * i + 2] = pts[2 * i] + h * 2;
		sum += function(pts[2 * i]) + 4 * function(pts[2 * i + 1]) + function(pts[2 * i + 2]);
	}
	delete[] pts;
	return sum * h / 3;
}

// Template and explicit declaration - Example of using Template
// Interpolator Quadratur
// Interpolation function(points2D) --> Integrator.InterpolarQuadratur(function, a, b);

template <typename T> T Integration::InterpolarQuadratur(Interpolation function, T lowerBnd, T upperBnd) {
	// Calculate operating point
	T interval = upperBnd - lowerBnd;
	T size = interval / this->dt;
	T* operatingPts = new T[size+1];
	operatingPts[0] = lowerBnd;
	T sum = function.lagrange(operatingPts[0])*dt;
	for (int i = 1; i <= size; i++) {
		operatingPts[i] = operatingPts[i-1] + this->dt;
		sum += function.lagrange(operatingPts[i]) * dt;
	}
	return sum;
}

template double Integration::InterpolarQuadratur(Interpolation, double, double);





