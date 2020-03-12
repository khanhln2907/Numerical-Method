#pragma once
#include "main.h"

class function 
{
private:
	double dt;
	double (*funcPtr)(double);

public:
	// Define new function with definition
	function(double dt, double (*funcPtr)(double));
	~function();
	// Use functionPointer to calculate output -> double foo(); Ex: func.out(x, foo);
	double out(double in); //

	// Integration
	double IntegrateSumTrapez(double lowerBnd, double upperBnd);
	double IntegrateSimpson(double lowerBnd, double upperBnd);

};

