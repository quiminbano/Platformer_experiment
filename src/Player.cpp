#include "../include/Player.hpp"
#include <iostream>

Player::Player()
{
	m_animationTimer.restart(); //Restart the timer.
	initTexture();
	initSprite();
}

Player::~Player()
{

}

void	Player::initTexture()
{
	if (!m_textureSheet.loadFromFile("../../textures/main_character.png"))
		throw std::runtime_error("Error loading character texture!");
}

void	Player::initSprite()
{
	m_playerSprite.setTexture(m_textureSheet);
	m_currentFrame = sf::IntRect(0, 86, 44, 129);
	m_playerSprite.setTextureRect(m_currentFrame);
	m_playerSprite.setScale(2.0f, 2.0f);
}

void	Player::initializeMoveBooleans()
{
	m_moveUp = false;
	m_moveDown = false;
	m_moveLeft = false;
	m_moveRight = false;
}

void	Player::updateMovement()
{
	if (m_moveUp)
		m_playerSprite.move(0.f, -5.f);
	if (m_moveDown)
		m_playerSprite.move(0.f, 5.f);
	if (m_moveLeft)
		m_playerSprite.move(-5.f, 0.f);
	if (m_moveRight)
		m_playerSprite.move(5.f, 0.f);
}

void	Player::update(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
		setMovement(event.key.code);
	else if (event.type == sf::Event::KeyReleased)
		unsetMovement(event.key.code);
	updateMovement();
	updateAnimations();
}

void	Player::update()
{
	updateMovement();
	updateAnimations();
}

void	Player::setMovement(const sf::Keyboard::Key &key)
{
	if (key == sf::Keyboard::W)
		m_moveUp = true;
	else if (key == sf::Keyboard::S)
		m_moveDown = true;
	else if (key == sf::Keyboard::A)
		m_moveLeft = true;
	else if (key == sf::Keyboard::D)
		m_moveRight = true;
}

void	Player::unsetMovement(const sf::Keyboard::Key &key)
{
	if (key == sf::Keyboard::W)
		m_moveUp = false;
	else if (key == sf::Keyboard::S)
		m_moveDown = false;
	else if (key == sf::Keyboard::A)
		m_moveLeft = false;
	else if (key == sf::Keyboard::D)
		m_moveRight = false;
}

void	Player::updateAnimations()
{
	if (m_animationTimer.getElapsedTime().asSeconds() >= 0.5f)
	{
		if (!m_moveUp && !m_moveDown && !m_moveLeft && !m_moveRight)
		{
			m_currentFrame.left += 44;
			if (m_currentFrame.left >= 132)
				m_currentFrame.left = 0;
		}
		m_animationTimer.restart();
		m_playerSprite.setTextureRect(m_currentFrame);
	}
}

void	Player::render(sf::RenderTarget &target)
{
	target.draw(m_playerSprite);
}