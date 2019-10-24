#include "Ball.h"

Ball::Ball()
{
   setRadius(10); 
   setFillColor(sf::Color::White);
   setOrigin(this->getRadius(), this->getRadius()); 
   speed = 5;
   basicDirect = sf::Vector2f(1.0f, 1.0f); 
}

Ball::Ball(float sp, sf::Vector2f incre)
{
	speed = sp; 
	basicDirect = incre; 
}

void Ball::MoveBall(ManHinhChoi* in_window)
{
	sf::Vector2f wsize;
	wsize.x = in_window->GetWindowSize().x; 
	wsize.y = in_window->GetWindowSize().y;
	float bra = getRadius(); 
	if (getPosition().y > wsize.y - bra && basicDirect.y > 0)
	{
		ReverseBasicDirectY(); 
	}
	if (getPosition().y < 0 && basicDirect.y < 0)
	{
		ReverseBasicDirectY(); 
	}
	sf::Vector2f newPos; 
	newPos.x = getPosition().x + speed*basicDirect.x; 
	newPos.y = getPosition().y + speed*basicDirect.y; 
	setPosition(newPos); 
}





