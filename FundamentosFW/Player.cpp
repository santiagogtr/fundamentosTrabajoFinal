#include "Player.h"
#include <SDL\SDL.h>
#include <iostream>

void Player::init(float speed, glm::vec2 position,
	InputManager* inputManager,
	Camera2D* camera,
	std::vector<Bullet>* bullets) {
	_speed = speed;
	_camera2D = camera;
	_position = position;
	_inputManager = inputManager;
	color.set(0, 0, 185, 255);
	_bullets = bullets;
	_currentGun = -1;
}

void Player::addGun(Gun* gun) {
	_guns.push_back(gun);
	if (_currentGun == -1) {
		_currentGun = 0;
	}
}

void Player::update(const std::vector<std::string>& levelData,
	std::vector<Human*>& humans,
	std::vector<Zombie*>& zombies, 
	float deltaTime) {
	if (_inputManager->isKeyPressed(SDLK_w)) {
		_position.y += _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_s)) {
		_position.y -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_a)) {
		_position.x -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_d)) {
		_position.x += _speed;
	}

	glm::vec2 mouseCoords = _inputManager->getMouseCoords();
	mouseCoords = _camera2D->convertScreenToWorl(mouseCoords);

	glm::vec2 centerPosition = 
		_position + glm::vec2(AGENT_RADIUS);

	glm::vec2 direction = glm::normalize(mouseCoords - centerPosition);

	if (_currentGun != -1 && 
			_inputManager->isKeyDown(SDL_BUTTON_LEFT)) {
		std::cout << _position.x << ',' << _position.y << std::endl;
		std::cout << centerPosition.x << ',' << centerPosition.y << std::endl;
		_guns[_currentGun]->update(
			_inputManager->isKeyDown(SDL_BUTTON_LEFT),
			centerPosition,
			direction,
			*_bullets,
			deltaTime
		);
	}

	collideWithLevel(levelData);
}


Player::Player()
{
}


Player::~Player()
{
}
