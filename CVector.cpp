#include "CVector.h"
#include "Temp.h"
#include <chrono>
#include <omp.h>

class Temp;

void CVector::Clean() { SetZero(); }
void CVector::SetZero() { v.clear(); n = 0; }

CVector::CVector(const CVector& b) { CopyOnly(b); }

CVector& CVector::operator=(const CVector& b) {
	if (this != &b) {
		Clean(); CopyOnly(b); 
	}
	return *this;
}

CVector::CVector(const vector < double> b, int n) {
	this->n = n;
	v = b;
}

void CVector::CopyOnly(const CVector& b) { 
	n = b.n; 
	v = b.v;
}

void CVector::print() {
	for (auto i = v.begin(); i != v.end(); ++i) cout << *i << ' ';
	cout << endl;
}

int CVector::length()const { return n; }
vector<double> CVector::Vector()const{ return v; }

/*CVector CVector::operator+(const CVector& b) {
	if (n > b.n) {
		double* d = new double[n];
		b[n - 1] = 0;
		for (int i = 0; i < n; i++) d[i] = v[i] + b[i];
		CVector* res(d, n);
		delete[] d;
		return res;
	}
	if (n < b.n) {
		double* d = new double[n];
		v[b.n-1] = 0;
		for (int i = 0; i < b.n; i++) d[i] = v[i] + b[i];
		CVector res(d, n);
		delete[] d;
		return res;
	}
	if (n = b.n) {
		double* d = new double[n];
		for (int i = 0; i < n; i++) d[i]=v[i]+b[i];
		CVector res(d,n);
		delete[] d;
		return res;
	}
}
CVector CVector::operator-(const CVector& b) {
	if (n != b.n) {
		printf("Error. Incorrect length\n");
		return *this;
	}
	else {
		double* d = new double[n];
		for (int i = 0; i < n; i++) d[i] = v[i] - b[i];
		CVector res(d, n);
		delete[] d;
		return res;
	}
}*/
const double& CVector::operator[](int i) const{
	if (i < 0 || i>=n) {
		printf("Error.Incorrect index\n");
		throw - 4;
	}
	return v[i];
}
double CVector::operator*(const CVector& b) {
	if (n != b.n) {
		printf("Error. Incorrect length\n");
		return 0;
	}
	else {
		double res=0;
		double tmp = 0;
		const int N = n;
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
#pragma omp parallel shared(res) private(tmp) 
{	
#pragma omp for reduction(+:res) 
		for (int i = 0; i < N; i++) {
			tmp = v[i] * b[i];
			res += tmp;
		}
}
		
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Mult operator runtime is " << elapsed_ms << " ms\n";
		return res;
	}
}


Temp CVector::operator[](int i) {
	if (i < 0) {
		throw - 1;
	}
	return Temp(this, i);
}