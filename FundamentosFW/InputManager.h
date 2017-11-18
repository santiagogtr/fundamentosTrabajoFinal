#pragma once
#include <unordered_map>
#include <glm\glm.hpp>

class InputManager
{
private:
	bool wasKeyDown(unsigned int keyCode);
	std::unordered_map<unsigned int, bool> _keyMap;
	std::unordered_map<unsigned int, bool> _previousKeyMap;
	glm::vec2 _mouseCoords;

public:
	InputManager();
	~InputManager();
	void update();
	void pressKey(unsigned int keyCode);
	void releaseKey(unsigned int keyCode);
	void setMouseCoords(float x, float y);
	bool isKeyDown(unsigned int keyCode);
	bool isKeyPressed(unsigned int keyCode);
	glm::vec2 getMouseCoords() const {
		return _mouseCoords;
	}
};

