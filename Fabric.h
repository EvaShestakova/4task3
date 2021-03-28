#pragma once
#include "CVector.h"
#include "CVectorHori.h"
#include "CVectorVert.h"
class CVectorHori;
class CVectorVert;
class Fabric
{
public:
	virtual CVector* Create() = 0;
};

class FabricHori : public Fabric {
public:
	virtual CVector* Create() override { return new CVectorHori; }
};

class FabricVert : public Fabric {
public:
	virtual CVector* Create() override { return new CVectorVert; }
};

CVector* create(string str, map<string, Fabric*> factory) {
	auto search = factory.find(str);
	if (search == factory.end()) {
		std::cout << "Not found\n";
		throw - 1;
	}
		return factory[str]->Create();
}