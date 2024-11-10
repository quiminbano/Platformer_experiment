#pragma once

#include <SFML/Graphics.hpp>

class MainMenu
{
private:
	sf::Font	m_mainMenuFontOptions;
	sf::Font	m_mainMenuFontTitle;
	sf::Text	m_mainMenuTextTitle;
	sf::Text	m_mainMenuTextStart;
	sf::Text	m_mainMenuTextExit;
	bool		m_pressedStart;
	bool		m_pressedExit;

	void	initializeFont();
	void	initializeTexts();
	void	updateMainMenu(sf::Event &event);
public:
	MainMenu();
	~MainMenu();

	void	update(sf::Event &event);
	void	render(sf::RenderTarget &target);
	bool	getPressedStart() const;
	bool	getPressedExit() const;
	void	setPressedStart(bool option);
	void	setPressedExit(bool option);
};
