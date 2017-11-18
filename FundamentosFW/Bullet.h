#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "SpriteBacth.h"

class Human;
class Zombie;
class Agent;

const int BULLET_RADIUS = 5;

class Bullet
{
private:
	bool collideWithWorld(
				const std::vector<std::string>& levelData);
	glm::vec2 _direction;
	glm::vec2 _position;
	float _damage;
	float _speed;

public:
	Bullet(glm::vec2 position, glm::vec2 direction,
		float damage, float speed);
	~Bullet();
	void draw(SpriteBacth& spriteBatch);
	bool update(const std::vector<std::string>& levelData,
								float deltaTime);
	bool collideWithAgent(Agent* agent);
	float getDamage()const { return _damage; };

};

