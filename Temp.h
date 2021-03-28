#pragma once
#include <iostream>
#include <fstream>
class CVector;
class Temp
{
	CVector* v; int i;
	public:
		Temp(CVector* v, int i) { this->v = v; this->i = i; }
		Temp& operator=(double c);
		operator double();
};


