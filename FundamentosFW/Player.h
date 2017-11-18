#pragma once
#include "Human.h"
#include "InputManager.h"
#include "Gun.h"
#include <vector>
#include "Camera2D.h"

class Player: public Human
{
private:
	InputManager* _inputManager;
	std::vector<Gun*> _guns;
	int _currentGun;
	Camera2D* _camera2D;
	std::vector<Bullet>* _bullets;
public:
	void addGun(Gun* gun);
	Player();
	~Player();
	void init(float speed, glm::vec2 position, 
		InputManager* inputManager,
		Camera2D* camera2D,
		std::vector<Bullet>* bullets);
	void update(const std::vector<std::string>& levelData,
		std::vector<Human*>& humans,
		std::vector<Zombie*>& zombies,
		float deltaTime);
};

