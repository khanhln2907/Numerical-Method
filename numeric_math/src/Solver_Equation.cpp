#include "Solver_Equation.h"

Solver_Equation::Solver_Equation(fPtr1v function)
{
	this->function = function;
	this->derivativeFunction = NULL;
}

Solver_Equation::~Solver_Equation()
{
	;
}

void Solver_Equation::setDerivative(fPtr1v derivativeFunction)
{
	this->derivativeFunction = derivativeFunction;
}

double Solver_Equation::bisection(double lowerBnd, double upperBnd, double tol, double res, double maxit)
{
	double u = this->function(lowerBnd); // Init
	double e = upperBnd - lowerBnd; // Interval length
	double c = 0; // Middle Point

	for (int k = 1; k <= maxit; k++) {
		e *= 0.5; 
		c = lowerBnd + e;
		double w = this->function(c);
		if (fabs(e) < tol || fabs(w) < res) return c;
		((u > 0 && w < 0) || (u < 0 && w>0)) ? (upperBnd = c) : (lowerBnd = c, u = w);
	}
	return c;
}

// Newton Method
double Solver_Equation::Newton(double xp, double tol, double res, int mxt) {
	assert(this->derivativeFunction != NULL);

	double v = this->function(xp);
	double xnew;

	for (int k = 1; k <= mxt; k++) {
		double derv = this->derivativeFunction(xp);
		if (!derv) {
			cout << "Devision by 0 occured in Newton. \n";
			exit(1);
		}

		xnew = xp - v / derv;
		v = this->function(xnew);
		if (fabs(xnew - xp) < tol || fabs(v) < res) return xnew;
		xp = xnew;
	}
	return xnew;
}
