#include "Gun.h"
#include <ctime>
#include <random>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm\gtx\rotate_vector.hpp>


Gun::Gun(std::string name, int fireRate,
	int bulletsPershot,float spread, float bulletDamage,
	float bulletSpeed)
	: _name(name),
	_spread(spread),
	_fireRate(fireRate),
	_bulletDamage(bulletDamage),
	_bulletsPershot(bulletsPershot),
	_bulletSpeed(bulletSpeed),
	_frameCounter(0)

{
	
}

void Gun::update(bool isMouseDown,
	const glm::vec2& position,
	const glm::vec2& direction,
	std::vector<Bullet>& bullets,
	float deltaTime
) {
	_frameCounter += 1.0*deltaTime;
	if (_frameCounter >= _fireRate && isMouseDown) {
		fire(direction, position, bullets);
		_frameCounter = 0;
	}
}

void Gun::fire(const glm::vec2& direction, 
			   const glm::vec2& position,
			   std::vector<Bullet>& bullets
	
	) {
	static std::mt19937 randonEngine(time(nullptr));
	std::uniform_real_distribution<float>
		randRotate(-_spread, _spread);

	for (int i = 0; i < _bulletPerShot; i++)
	{
		bullets.emplace_back(position
			- glm::vec2(BULLET_RADIUS),
			glm::rotate(direction, randRotate(randonEngine)),
				_bulletDamage, _bulletSpeed
			);
	}
}


Gun::~Gun()
{
}
