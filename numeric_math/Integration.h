#pragma once
#include"main.h"
#include"Interpolation.h"

extern class Interpolation;

class Integration
{
private:
	double dx = 0.001;

public:
	Integration();
	~Integration();

	// Numerik
	// Interpolar Quadratur =======================================================================
	// Function f : [a,b] -> R is given, calculate integration of f from a -> b
	// From interpolation, we receive x0 -> xn in [a,b] -> 
	// Integration = sum[a->b] (p(xi))
	double InterpolarQuadratur(Interpolation& function, double lowerBnd, double upperBnd);
	
	// Put this one in main if use the below function
	// template double Integration::InterpolarQuadratur(Interpolation, double, double);
	template <typename T> T InterpolarQuadratur(Interpolation function, T lowerBnd, T upperBnd);
	
	// Trapez Quadratur =========================================================================
	double SumTrapez(Interpolation function, double lowerBnd, double upperBnd); // Consider Pointer to function here
	
};

