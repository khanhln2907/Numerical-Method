#include "function.h"

function::function(double dt, double (*funcPtr)(double))
{
	this->dt = dt;
	this->funcPtr = funcPtr;
}

function::~function()
{
	;
}

double function::out(double in) 
{
	return this->funcPtr(in);
}

double function::integralInterpolarQuadratur(double lowerBnd, double upperBnd)
{
	// Calculate operating point
	double interval = upperBnd - lowerBnd;
	double size = interval / this->dt;
	double* operatingPts = new double[size + 1];
	operatingPts[0] = lowerBnd;
	double sum = this->out(operatingPts[0]) * dt;
	for (int i = 1; i <= size; i++) {
		operatingPts[i] = operatingPts[i - 1] + this->dt;
		sum += this->out(operatingPts[i]) * dt;
	}
	delete[] operatingPts;
	return sum;
}

