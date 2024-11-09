#pragma once

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Game
{
private:
	sf::RenderWindow		m_window;
	sf::Event				m_event;
	std::unique_ptr<Player>	m_player;
	enum					pollEvents
	{
		INSIDE,
		OUTSIDE
	};

	void	initalizeWindow(uint32_t width, uint32_t heigth);
	void	initializePlayer();
	void	updatePlayer(Game::pollEvents pollEvent);
	void	handleKeyboardEvents();
public:
	Game();
	virtual ~Game();

	const sf::RenderWindow	&getWindow() const;
	void					updateWindow();
	void					renderPlayer();
	void					renderWindow();
};
