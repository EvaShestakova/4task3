#pragma once
#include "CVector.h"
#include "Temp.h"
class CVectorVert : public CVector
{
public:
	using CVector::operator=;
	CVectorVert() {}
	~CVectorVert() {}
	CVectorVert(const CVector& b) : CVector(b) {}
	CVectorVert(const vector<double> b, int n) :CVector(b, n) {}
	int output(const string FileName) override;
};

