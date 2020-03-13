#pragma once
#include"main.h"
#include"Interpolation.h"

class Interpolation;
fPtr1v;

class Integration
{
private:
	double dt = 0.001;

public:
	Integration();
	~Integration();
	void setDt(double dt);

	// Numerik
	// Interpolar Quadratur =======================================================================
	// Function f : [a,b] -> R is given, calculate integration of f from a -> b
	// From interpolation, we receive x0 -> xn in [a,b] -> 
	// Integration = sum[a->b] (p(xi))
	double InterpolarQuadratur(Interpolation& function, double lowerBnd, double upperBnd);
	
	// Put this one in main if use the below function
	// template double Integration::InterpolarQuadratur(Interpolation, double, double);
	template <typename T> T InterpolarQuadratur(Interpolation function, T lowerBnd, T upperBnd);
	
	// Trapezoidal =========================================================================
	double Trapezoidal(fPtr1v function, double lowerBnd, double upperBnd);

	// Simpson =========================================================================
	double Simpson(fPtr1v function, double lowerBnd, double upperBnd);
};

