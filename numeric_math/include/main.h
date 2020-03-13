#pragma once
#include<vector>
#include<iostream>
#include<assert.h>

//using std::vector;
using std::cout;
using std::endl;
using std::cin;

struct p2D {
	double x;
	double y;
};

typedef std::vector<p2D> vector2D;
typedef double (*fPtr1v)(double); // define fptr as function pointer
typedef double(*fPtr2v)(double, double); // Pointer to derivative function f(t,x)