#pragma once
#include "main.h"

class function 
{
private:
	double dt;
	double (*funcPtr)(double);

public:
	function(double dt, double (*funcPtr)(double));
	~function();
	// Use functionPointer to calculate output -> double foo(); Ex: func.out(x, foo);
	double out(double in); //
	double integralInterpolarQuadratur(double lowerBnd, double upperBnd);
};

