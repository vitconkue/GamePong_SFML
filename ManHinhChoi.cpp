#include "ManHinhChoi.h"

void ManHinhChoi::Setup(std::string title, sf::Vector2f &Wsize)
{
	m_WindowsTitle = title; 
	m_WindowSize.x = Wsize.x; 
	m_WindowSize.y = Wsize.y;  
	m_isDone = false; 
	m_isFullWindows = false;
	createScreen(); 
}
//
ManHinhChoi::ManHinhChoi()
{
	sf::Vector2f s; 
	s.x = 1000; s.y = 600; 
	Setup("Game Pong", s); 
	m_windows.setFramerateLimit(40); 
}

ManHinhChoi::~ManHinhChoi()
{
	CloseWindow(); 
}


void ManHinhChoi::StartDrawing()
{
	m_windows.clear(sf::Color::Black); 
}

void ManHinhChoi::Display(sf::Drawable& object)
{
	m_windows.draw(object); 
}

void ManHinhChoi::InLenManHinh()
{
	m_windows.display(); 
}

void ManHinhChoi::createScreen()
{
	auto style = (m_isFullWindows ? sf::Style::Fullscreen : sf::Style::Default); 
	m_windows.create({ (unsigned int)m_WindowSize.x,(unsigned int)m_WindowSize.y,32 }, m_WindowsTitle, style);
}

void ManHinhChoi::CloseWindow()
{
	m_windows.close(); 
}

sf::Vector2f ManHinhChoi::GetWindowSize()
{
	return m_WindowSize;
}

void ManHinhChoi::ToggleFullScreen()
{
	m_isFullWindows = !m_isFullWindows; 
	CloseWindow();
	createScreen(); 
}

void ManHinhChoi::Update()
{
	sf::Event ev; 
	while (m_windows.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			m_isDone = true; 
		}
    }
}
