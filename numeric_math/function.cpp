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

double function::IntegrateSumTrapez(double lowerBnd, double upperBnd)
{
	double size = (upperBnd - lowerBnd) / this->dt;
	double* pts = new double[size+1];
	pts[0] = lowerBnd; 
	double sum = this->out(pts[0]) * this->dt/2;
	for (int i = 1; i <= size; i++) {
		pts[i] = pts[i - 1] + this->dt;
		if(i != size) sum += this->out(pts[i]) * this->dt;
	}
	sum += this->out(pts[static_cast<int>(size)]) * this->dt/2;

	delete[] pts;
	return sum;
}

double function::IntegrateSimpson(double lowerBnd, double upperBnd)
{
	double h = this->dt / 2;
	double size = (upperBnd - lowerBnd) / h ;
	
	double* pts = new double[size + 1];
	pts[0] = lowerBnd;

	double sum = 0;
	for (int i = 0; i <= (size - 2) / 2; i++) {
		pts[2 * i + 1] = pts[2 * i] + h;
		pts[2 * i + 2] = pts[2 * i] + h * 2;
		sum += this->out(pts[2*i]) + 4* this->out(pts[2 * i + 1]) + this->out(pts[2 * i + 2]);
	}
	delete[] pts;
	return sum*h/3;
}

