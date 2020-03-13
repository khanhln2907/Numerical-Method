#pragma once
#include "main.h"

class function 
{
private:
	double dt;
	double (*funcPtr)(double);

	double getX; // Use for Fix Point iteration

public:
	// Define new function with definition
	function(double dt, double (*funcPtr)(double));
	~function();
	// Use functionPointer to calculate output -> double foo(); Ex: func.out(x, foo);
	double out(double in); //

	// Solve Function f(x) = 0 -> x
	double getSolution();



	// Integration
	/* 
	Input: Lower bound and upper bound
	Output: Integration, higher precision as interpolator integration
	*/
	double IntegrateSumTrapez(double lowerBnd, double upperBnd);
	double IntegrateSimpson(double lowerBnd, double upperBnd);

	// Derivative
	/*
	Known: Function y = f(t), t0 and yo. Condition of f: Lipshitz conitnuos
	Input: t
	Output: df = f(t,y(t)), where y(t0) = y0
	*/
	double DerivativeExplicitEuler(double t); // Consistence order = 1;
	double DerivativeImplicitEuler(double t); // 
	double DerivativeModifiedEuler(double t); // Order = 2;

};

