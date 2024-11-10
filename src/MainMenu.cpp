#include "../include/MainMenu.hpp"


MainMenu::MainMenu()
{
	initializeFont();
	initializeTexts();
	m_pressedStart = false;
	m_pressedExit = false;
}

MainMenu::~MainMenu()
{

}

void	MainMenu::initializeFont()
{
	if (!m_mainMenuFontTitle.loadFromFile("../../fonts/mainTitle.ttf"))
		std::runtime_error("Program could not load font for main menu");
	if (!m_mainMenuFontOptions.loadFromFile("../../fonts/cuphead.ttf"))
		std::runtime_error("Program could not load font for main menu");
}

void	MainMenu::initializeTexts()
{
	m_mainMenuTextTitle.setFont(m_mainMenuFontTitle);
	m_mainMenuTextTitle.setColor(sf::Color::White);
	m_mainMenuTextTitle.setString("Experimental Platformer");
	m_mainMenuTextTitle.setPosition(400 - (m_mainMenuTextTitle.getLocalBounds().width / 2), 10);	
	m_mainMenuTextStart.setFont(m_mainMenuFontOptions);
	m_mainMenuTextStart.setColor(sf::Color::Blue);
	m_mainMenuTextStart.setString("Start Game");
	m_mainMenuTextStart.setPosition((400 - m_mainMenuTextStart.getLocalBounds().width / 2), 250);
	m_mainMenuTextExit.setFont(m_mainMenuFontOptions);
	m_mainMenuTextExit.setColor(sf::Color::White);
	m_mainMenuTextExit.setString("Exit");
	m_mainMenuTextExit.setPosition((400 - m_mainMenuTextExit.getLocalBounds().width / 2), 400);
}

void	MainMenu::update(sf::Event &event)
{
	updateMainMenu(event);
}

void	MainMenu::updateMainMenu(sf::Event &event)
{
	if ((event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S) && m_mainMenuTextStart.getColor() == sf::Color::Blue)
	{
		m_mainMenuTextStart.setColor(sf::Color::White);
		m_mainMenuTextExit.setColor(sf::Color::Blue);
	}
	else if ((event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S) && m_mainMenuTextExit.getColor() == sf::Color::Blue)
	{
		m_mainMenuTextStart.setColor(sf::Color::Blue);
		m_mainMenuTextExit.setColor(sf::Color::White);
	}
	if (event.key.code == sf::Keyboard::Enter && m_mainMenuTextStart.getColor() == sf::Color::Blue)
	{
		m_pressedStart = true;
		m_pressedExit = false;
	}
	else if (event.key.code == sf::Keyboard::Enter && m_mainMenuTextExit.getColor() == sf::Color::Blue)
	{
		m_pressedExit = true;
		m_pressedStart = false;
	}
}

bool	MainMenu::getPressedStart() const
{
	return (m_pressedStart);
}

bool	MainMenu::getPressedExit() const
{
	return (m_pressedExit);
}

void	MainMenu::setPressedStart(bool option)
{
	m_pressedStart = option;
}

void	MainMenu::setPressedExit(bool option)
{
	m_pressedExit = option;
}

void	MainMenu::render(sf::RenderTarget &target)
{
	target.draw(m_mainMenuTextTitle);
	target.draw(m_mainMenuTextStart);
	target.draw(m_mainMenuTextExit);
}
