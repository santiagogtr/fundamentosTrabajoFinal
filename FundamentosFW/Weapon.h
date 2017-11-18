#pragma once
#include <string>
class Weapon
{
protected:
	std::string _name;
public:
	Weapon(std::string name);
	virtual void update() =0;
	~Weapon();
};

