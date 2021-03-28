#include "CVectorHori.h"
#include <chrono>
#include <omp.h>

int CVectorHori::output(const string FileName)
{
	ofstream fout(FileName,ios_base::app);
	for (auto i = v.begin(); i != v.end(); ++i) {
		fout << *i << ' ';
	}
	fout << '\n';
	fout.close(); 
    return 0;
}

CVectorHori operator+(const CVector& a, const CVector& b) {
	/*if (a.n > b.n) {
		double* d = new double[a.n];
		b[a.n - 1] = 0;
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] + b[i];
		CVectorHori res(d, a.n);
		delete[] d;
		return res;
	}
	if (a.n < b.n) {
		double* d = new double[a.n];
		a.v[b.n - 1] = 0;
		for (int i = 0; i < b.n; i++) d[i] = a.v[i] + b[i];
		CVectorHori res(d, a.n);
		delete[] d;
		return res;
	}*/
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		return a;
	}
	else{
		vector<double>d(a.n);
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
#pragma omp parallel for
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] + b[i];
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
		CVectorHori res(d, a.n);
		return res;
	}
}
CVectorHori operator-(const CVector& a, const CVector& b) {
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		return a;
	}
	else {
		vector<double>d(a.n);
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
#pragma omp parallel for
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] - b[i];
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Subtraction operator runtime is " << elapsed_ms << " ms\n";
		CVectorHori res(d, a.n);
		return res;
	}
}