#include "Interpolation.h"

Interpolation::Interpolation()
{
	this->size = 0;
	this->pts = NULL;
}

Interpolation::Interpolation(vector2D pts)
{
	this->size = pts.size();
	this->pts = new p2D[this->size];
	for(int i = 0; i < size; i++){
		this->pts[i].x = pts[i].x;
		this->pts[i].y = pts[i].y;
	}
}

void Interpolation::getInfo()
{
	cout << "adress " << &(this->pts[0]) << " value " << this->pts[0].x << " " << this->pts[0].y << endl;
}

Interpolation::~Interpolation()
{
	delete[] this->pts;
}


// Numeric
// Lagrange
double Interpolation::lagrange(double x) {
	// Interpolationspolynom Lm of Lagrange: Lkn(xk) = 1, Lkn(xi) = 0 for i != k
	double sum = 0;

	for (int k = 0; k < this->size; k++) {
		double L = 1;
		for (int j = 0; j < this->size; j++) {
			if (j != k) {
				L = L * (x - (this->pts[j]).x) / (this->pts[k].x - this->pts[j].x);
			}
		}
		sum += this->pts[k].y * L;
	}
	return sum;
}

// Newton
double Interpolation::newton(double x) {
	std::vector<double> b(this->size);
	std::vector<double> vx(this->size);
	for (int i = 0; i < this->size; i++) {
		b[i] = this->pts[i].y;
		vx[i] = this->pts[i].x;
	}
	int n = this->size - 1;

	// find coeef
	for (int j = 1; j <= n; j++)
		for (int i = n; i >= j; i--)
			b[i] = (b[i] - b[i - 1]) / (vx[i] - vx[i - j]);

	double u = b[n];
	for (int i = n - 1; i >= 0; i--)
		u = b[i] + (x - vx[i]) * u;
	return u;
}

// Define Template and remember to attach explicit declaration
template<typename T> T Interpolation::lagrangeFromPoints(T x, const std::vector<T> vx, const std::vector<T> vy) {
	assert(vx.size() == vy.size());
	// Interpolationspolynom Lm of Lagrange: Lkn(xk) = 1, Lkn(xi) = 0 for i != k
	T sum = 0;

	for (int k = 0; k < vx.size(); k++) {
		T L = 1;
		for (int j = 0; j < vx.size(); j++) {
			if (j != k) {
				L = L * (x - vx[j]) / (vx[k] - vx[j]);
			}
		}
		sum += vy[k] * L;
	}
	return sum;
}
template double Interpolation::lagrangeFromPoints(double, const std::vector<double>, const std::vector<double>);

// Newton
template<typename T> T Interpolation::newtonFromPoints(T x,const std::vector<T> vx, const std::vector<T> vy)
{
	std::vector<T> b = vy;
	int n = vx.size() - 1;

	// find coeef
	for (int j = 1; j <= n; j++)
		for (int i = n; i >= j; i--)
			b[i] = (b[i] - b[i - 1]) / (vx[i] - vx[i - j]);

	T u = b[n];
	for (int i = n - 1; i >= 0; i--)
		u = b[i] + (x - vx[i]) * u;
	return u;
};
template double Interpolation::newtonFromPoints(double, const std::vector<double>, const std::vector<double>);

