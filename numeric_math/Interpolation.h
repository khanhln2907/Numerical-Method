#pragma once
#include"main.h"

struct p2D;
vector2D;

class Interpolation
{
private:
	p2D* pts;
	double size;

public:
	// Normal Init
	Interpolation();
	// Init function from given points, handler of function 
	Interpolation(vector2D pts); 
	void getInfo();
	~Interpolation();
	
	//Numerik
	// Lagrange Interpolation  ==  Linear Spline ======================================================  
	// y = function.lagrange(x)
	double lagrange(double x);
	// y = Interp.lagrange(x, xPoints, yPoints);
	template<typename T> T lagrangeFromPoints(T x, const std::vector<T> vx, const std::vector<T> vy);
	
	// Newton Interpolation ===========================================================================
	// T y = Interp.newton(vector<T> vx, vector<T> vy, Tx) 
	// pn(x) = c0 + c1*(x-x0) + c2*(x-x0)(x-x1) + ... + cn*(x-x0)...(x-xn-1)
	double newton(double x);

	// Called Used Function - Explicit Instance of Templates put this in main if use below function
	//template double Interpolation::newtonFromPoints(double, const std::vector<double>, const std::vector<double>);
	template <typename T> T newtonFromPoints(T x, const std::vector<T> vx, const std::vector<T> vy);
};




