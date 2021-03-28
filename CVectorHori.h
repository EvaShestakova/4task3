#pragma once
#include "CVector.h"
#include "Temp.h"
class CVector;
class CVectorHori : public CVector
{
public:
	using CVector::operator=;
	CVectorHori(){}
	~CVectorHori() {}
	CVectorHori(const CVector& b) : CVector(b) {}
	CVectorHori(const vector<double> b, int n) : CVector(b, n) {}
	friend CVectorHori operator+(const CVector& a, const CVector& b);
	friend CVectorHori operator-(const CVector& a, const CVector& b);
	int output(const string FileName) override;
};

