#pragma once
#include"main.h"

struct p2D {
	double x;
	double y;
};

typedef std::vector<p2D> vector2D;

class Interpolation
{
private:
	
	double size;


public:
	p2D* pts;
	// Normal Init
	Interpolation();
	Interpolation(vector2D pts); // Init function from given points, handler of function 
	void getInfo();
	~Interpolation();
	
	//Numerik
	// Lagrange Interpolation =======================================================================  
	// y = function.lagrange(x)
	double lagrange(double x);
	// y = Interp.lagrange(x, xPoints, yPoints);
	template<typename T> T lagrangeFromPoints(T x, const std::vector<T> vx, const std::vector<T> vy);
	
	// Newton Interpolation ========================================================================
	// T y = Interp.newton(vector<T> vx, vector<T> vy, Tx) 
	// pn(x) = c0 + c1*(x-x0) + c2*(x-x0)(x-x1) + ... + cn*(x-x0)...(x-xn-1)
	double newton(double x);

	// Called Used Function - Explicit Instance of Templates put this in main if use below function
	//template double Interpolation::newtonFromPoints(double, const std::vector<double>, const std::vector<double>);
	template <typename T> T newtonFromPoints(T x, const std::vector<T> vx, const std::vector<T> vy);
};




