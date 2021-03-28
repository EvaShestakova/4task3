#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Temp;
void AutoTest();
class CVectorHori;

class CVector {
protected:
	vector<double> v;
	int n;
	string filename;
public:
	virtual int output(const string FileName) = 0;
	void SetFileName(const string s) { filename = s; };
	const string GetFileName() { return filename; };

	CVector() { SetZero(); }
	virtual  ~CVector() { Clean(); }
	void Clean();
	void SetZero();
	CVector(const CVector& b);
	CVector(const vector<double> b, int n);
	CVector& operator=(const CVector& b);
	void CopyOnly(const CVector& b);
	void print();
	int length()const;
	void Setn(int m) { Clean(); n = m; v.resize(n); }
	vector<double> Vector()const;
	//CVector operator+(const CVector& b);
	//CVector operator-(const CVector& b);
	const double& operator[](int i) const;
	double operator*(const CVector& b);
	Temp operator[](int i);
	friend class Temp;
	friend CVectorHori operator+(const CVector& a, const CVector& b);
	friend CVectorHori operator-(const CVector& a, const CVector& b);
};
