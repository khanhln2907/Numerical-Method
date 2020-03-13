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

	void set_dt(double dt);
	double calculate(double t, double x);

	//Euler Method
	double Euler_Explicit(double t);
	double Euler_Implicit(double t); 

	//Runga Kutta
	double RK2(double t);
	double RK4(double t);

};

