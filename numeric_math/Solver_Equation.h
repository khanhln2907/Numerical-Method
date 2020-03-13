#pragma once
#include "main.h"
fPtr1v;

class Solver_Equation
{
private:
	fPtr1v function;
	fPtr1v derivativeFunction;

public:
	Solver_Equation(fPtr1v function);
	~Solver_Equation();
	void setDerivative(fPtr1v derivativeFunction);

	// Bisection Method;
	/*
	find x for f(x) = 0. 
	lowerBnd, upperBnd: initialize of boundaries
	tol: tolerance
	res: fault
	mxt: max iteration
	*/
	double bisection(double lowerBnd, double upperBnd, double tol, double res, double maxit);

	// Newton Method;
	/*
	find x for f(x) = 0. Please initialize derivative with setDerivative(function)
	xp: initial guess for root
	tol: tolerance
	res: fault
	mxt: max iteration
	*/
	double Newton(double xp, double tol, double res, int mxt);
};

