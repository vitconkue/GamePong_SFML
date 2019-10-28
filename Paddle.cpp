#include "Paddle.h"


// constructor cho thanh
Paddle::Paddle() 
{
	sf::Vector2f paddleSize(25, 130);
	setFillColor(sf::Color::Blue);  // đặt màu
	setSize(sf::Vector2f(paddleSize)); // đặt kích cỡ hình chữ nhật
	setOrigin(paddleSize / 2.f); //đặt gốc toạ độ là điểm ở giữa thanh
	setOutlineThickness(3); // bề dày viền thanh (vẽ)
	
}


void Paddle::MoveUp(ManHinhChoi* in_window)
{
	sf::Vector2f step(0.0, -10.0); // bước nhảy 10 pixel
	sf::Vector2f pos = getPosition(); 
	sf::Vector2f wsize = in_window->GetWindowSize(); 
	if (pos.y - getSize().y/2>= 10.f) // nếu chưa văng ra ngoài
	{
		sf::Vector2f newPos = pos + step;
		setPosition(newPos); // đặt vị trí mới
	}
	

}

void Paddle::MoveDown(ManHinhChoi* in_window)
{
	sf::Vector2f step(0.0, 10.0); // bước nhảy 10 pixel
	sf::Vector2f pos = getPosition();
	sf::Vector2f wsize = in_window->GetWindowSize();
	if (pos.y + getSize().y / 2 < wsize.y - 10.f) // nếu chưa văng ra ngoài
	{
		sf::Vector2f newPos = pos + step; 
		setPosition(newPos); 
	}
}


