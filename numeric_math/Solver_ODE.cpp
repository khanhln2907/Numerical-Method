#include "Solver_ODE.h"

Solver_ODE::Solver_ODE(double t0, double x0, double dt, fPtr2v function)
{
	this->pFcn = function;
	this->t0 = t0;
	this->x0 = x0;
	this->dt = dt;
}

Solver_ODE::~Solver_ODE()
{
	;
}

void Solver_ODE::set_dt(double dt)
{
	this->dt = dt;
}

double Solver_ODE::calculate(double t, double x)
{
	return this->pFcn(t,x);
}

double Solver_ODE::Euler_Explicit(double t)
{
	assert( t >= this->t0 );
	double range = (t - this->t0) / this->dt;
	double xt = this->x0;
	for (int i = 1; i <= range; i++) {
		xt += this->dt * this->calculate(t0 + i * this->dt, xt);
	}
	return xt;
}

double Solver_ODE::Euler_Implicit(double t)
{
	assert(t >= this->t0);
	double range = (t - this->t0) / this->dt;
	double xt = this->x0;
	double currentX = x0;
	for (int i = 1; i <= range; i++) {
		double euler_predict = currentX + this->dt * this->calculate(this->t0 + i * this->dt, currentX);
		double euler_correct = currentX + this->dt * this->calculate(this->t0 + i * this->dt + 1, euler_predict);
		xt = euler_predict;
		currentX = xt;
	}
	return xt;
}

// x+ = x + (F1 + F2)/2, where 
// F1 = dt * f(t,x)
// F2 = dt * f(t+,x+F1)
double Solver_ODE::RK2(double t) 
{
	assert(t >= this->t0);
	double xt = this->x0;
	double range = (t - this->t0) / this->dt;
	double currentX = x0;
	double currentT = this->t0;
	for (int i = 1; i <= range; i++) {
		double F1 = this->dt * this->calculate(currentT, currentX);
		double F2 = this->dt * this->calculate(currentT + this->dt, currentX + F1);
		xt += (F1 + F2) / 2;
		currentT += this->dt;
		currentX = xt;
	}
	return xt;
}
