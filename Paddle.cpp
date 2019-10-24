#include "Paddle.h"

Paddle::Paddle() 
{
	sf::Vector2f paddleSize(25, 130);
	setFillColor(sf::Color::Blue);  
	setSize(sf::Vector2f(paddleSize)); 
	setOrigin(paddleSize / 2.f);
	setOutlineThickness(3); 
	
}


void Paddle::MoveUp(ManHinhChoi* in_window)
{
	sf::Vector2f step(0.0, -30.0); 
	sf::Vector2f pos = getPosition(); 
	sf::Vector2f wsize = in_window->GetWindowSize(); 
	if (pos.y - getSize().y/2>= 30.f)
	{
		sf::Vector2f newPos = pos + step;
		setPosition(newPos);
	}
	

}

void Paddle::MoveDown(ManHinhChoi* in_window)
{
	sf::Vector2f step(0.0, 30.0);
	sf::Vector2f pos = getPosition();
	sf::Vector2f wsize = in_window->GetWindowSize();
	if (pos.y + getSize().y / 2 < wsize.y - 30.f)
	{
		sf::Vector2f newPos = pos + step; 
		setPosition(newPos); 
	}
}


