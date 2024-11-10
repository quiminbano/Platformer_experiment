#include "../include/Game.hpp"

Game::Game()
{
	initalizeWindow(800, 600);
	if (!m_window.isOpen())
		throw std::runtime_error("Error creating the window");
	initializePlayer();
	m_gameState = MAINMENU;
}

Game::~Game()
{

}

void	Game::initalizeWindow(uint32_t width, uint32_t heigth)
{
	m_window.create(sf::VideoMode(width, heigth), "Experimental Platformer", sf::Style::Close | sf::Style::Titlebar);
	m_window.setFramerateLimit(60);
}

void	Game::initializePlayer()
{
	m_player = std::make_unique<Player>();
}

const sf::RenderWindow	&Game::getWindow() const
{
	return (m_window);
}

void	Game::updateWindow()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window.close();
		else if (m_gameState == INSIDEGAME && (m_event.type == sf::Event::KeyPressed || m_event.type == sf::Event::KeyReleased))
			handleKeyboardEvents();
		else if (m_gameState == MAINMENU && m_event.type == sf::Event::KeyPressed)
			updateMainMenu();
	}
	if (m_gameState == MAINMENU && m_mainMenu.getPressedStart())
	{
		m_mainMenu.setPressedStart(false);
		m_gameState = INSIDEGAME;
	}
	else if (m_gameState == MAINMENU && m_mainMenu.getPressedExit())
	{
		m_window.close();
	}
	if (m_gameState == INSIDEGAME)
		updatePlayer(Game::pollEvents::OUTSIDE);
}

void	Game::handleKeyboardEvents()
{
	if (m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::Escape)
		m_window.close();
	updatePlayer(Game::pollEvents::INSIDE);
}

void	Game::updateMainMenu()
{
	m_mainMenu.update(m_event);
}

void	Game::updatePlayer(Game::pollEvents pollEvent)
{
	if (pollEvent == Game::pollEvents::INSIDE)
		m_player->update(m_event);
	else
		m_player->update();
}

void	Game::renderPlayer()
{
	m_player->render(m_window);
}

void	Game::renderMainMenu()
{
	m_mainMenu.render(m_window);
}

void	Game::renderWindow()
{
	if (m_gameState == INSIDEGAME)
	{
		m_window.clear(sf::Color::Blue);
		renderPlayer();
	}
	else if (m_gameState == MAINMENU)
	{
		m_window.clear();
		renderMainMenu();
	}
	m_window.display();
}