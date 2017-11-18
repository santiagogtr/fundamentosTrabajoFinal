#pragma once
#include "Game.h"
#include <algorithm>
#include "MenuScreen.h"
#include "GamePlayScreen.h"

class App : public Game
{
public:
	App();
	~App();
	virtual void onInit() override;
	virtual void addScreens() override;
	virtual void onExit() override;

private:
	std::unique_ptr<GamePlayScreen> _gamePlayScreen = nullptr;
	std::unique_ptr<MenuScreen> _menuScreen = nullptr;
};

