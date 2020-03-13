#pragma once
#include"main.h"

fPtr2v;

class Solver_ODE
{
private:
	fPtr2v pFcn;
	double t0;
	double x0;
	double dt;

public:
	Solver_ODE(double t0, double x0, double dt, fPtr2v function);
	~Solver_ODE();

	double calculate(double t, double x);
	double Euler_Explicit(double t);

};
