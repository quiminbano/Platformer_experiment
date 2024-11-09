#pragma once

#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Clock	m_animationTimer;
	sf::Sprite	m_playerSprite;
	sf::IntRect	m_currentFrame;
	sf::Texture	m_textureSheet;
	bool		m_moveUp;
	bool		m_moveDown;
	bool		m_moveLeft;
	bool		m_moveRight;

	void	initSprite();
	void	initTexture();
	void	updateMovement();
	void	initializeMoveBooleans();
	void	setMovement(const sf::Keyboard::Key &code);
	void	unsetMovement(const sf::Keyboard::Key &code);
	void	updateAnimations();

public:
	Player();
	virtual ~Player();

	void	update(const sf::Event &event);
	void	update();
	void	render(sf::RenderTarget &target);
};

