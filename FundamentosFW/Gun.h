#pragma once
#include "Weapon.h"
#include <glm\glm.hpp>
#include <vector>
#include "Bullet.h"

class Gun
{
public:
	std::string _name;
	Gun(std::string name, int fireRate,
		int bulletsPershot, float spread, float bulletDamage,
		float bulletSpeed);
	~Gun();
	void update(bool isMouseDown,
		const glm::vec2& position,
		const glm::vec2& direction,
		std::vector<Bullet>& bullets,
		float deltaTime
	);

private:
	float _frameCounter;
	void fire(const glm::vec2& direction,
		const glm::vec2& position,
		std::vector<Bullet>& bullets);
	int _fireRate;
	int _bulletsPershot;
	int _bulletPerShot;
	float _spread;
	float _bulletSpeed;
	int _bulletDamage;

};

