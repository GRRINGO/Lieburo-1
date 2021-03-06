#pragma once

//library includes
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

//include required objects
#include "Player.hpp"
#include "MyContactListener.hpp"
#include "SceneNode.hpp"
#include "Entity.hpp"
#include "Menu.hpp"
#include "Options.hpp"
#include "Constants.h"
#include "Gamefield.hpp"
#include "GUI.hpp"
#include "Powerup.hpp"
#include "GravityPU.hpp"
#include "GravityInverter.hpp"
#include "HealthRecovery.hpp"
#include "Bomb.hpp"
#include "Sounds.hpp"

class GUI;
class Menu;
class Options;
class Gamefield;
class Player;
class Sounds;

class Game {
public:

	//TODO: Contact masks

	Game();
	~Game();
	void createRandomPowerup();
	void run();
	void update(sf::Time deltaTime);
	void render();
	void navigateMenu(sf::Event &event);
	void navigateOptions(sf::Event &event);
	b2World* getWorld();
	std::shared_ptr<SceneNode> getSceneNode();
	std::shared_ptr<Player> getPlayer(int id); //used by guided projectiles
	std::shared_ptr<Menu> getMenu();
	std::shared_ptr<Options> getOptions();
	std::shared_ptr<Sounds> getSounds();
	void gameOver(int);
	void newGame();
	void setRunning(bool);
	sf::RenderWindow& getRenderWindow();
	sf::Vector2f limitPlayerCamera(std::shared_ptr<Player>, sf::View);
	void exit();

private:
	Game* mGame;
	bool playing = true;
	bool running;
	sf::RenderWindow rWindow;
	MyContactListener myContactListenerInstance;
	std::shared_ptr<SceneNode> sceneNode;
	b2World* mGameWorld;
	std::shared_ptr<Gamefield> gamefield;
	sf::View viewMenu, view1, view2, statusView;
	std::shared_ptr<GUI> gui;
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;
	std::shared_ptr<Menu> menu;
	std::shared_ptr<Options> options;
	int powerupTimer = 0;
	std::shared_ptr<Sounds> sounds;
};
