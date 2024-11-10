#pragma once

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "MainMenu.hpp"

class Game
{
private:
	sf::RenderWindow		m_window;
	sf::Event				m_event;
	std::unique_ptr<Player>	m_player;
	enum					gameSections
	{
		MAINMENU,
		INSIDEGAME,
		PAUSEMENU
	};
	enum					pollEvents
	{
		INSIDE,
		OUTSIDE
	};
	Game::gameSections		m_gameState;
	MainMenu				m_mainMenu;

	void	initalizeWindow(uint32_t width, uint32_t heigth);
	void	initializePlayer();
	void	updatePlayer(Game::pollEvents pollEvent);
	void	updateMainMenu();
	void	handleKeyboardEvents();
	void	renderMainMenu();
	void	renderPlayer();
public:
	Game();
	virtual ~Game();

	const sf::RenderWindow	&getWindow() const;
	void					updateWindow();
	void					renderWindow();
};
