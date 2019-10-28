#include "Ball.h"

// constructor cho bóng
Ball::Ball()
{
   setRadius(10); // set bán kính
   setFillColor(sf::Color::White); // set màu quả bóng (trắng)
   setOrigin(this->getRadius(), this->getRadius());  // đặt toạ độ tương đối ban đầu
   speed = 3.0;
   basicDirect = sf::Vector2f(1.0f, 1.0f); 
}

Ball::Ball(float sp, sf::Vector2f incre)
{
	speed = sp; 
	basicDirect = incre; 
}
// hàm di chuyển bóng (chỉ xét tường trên và dưới) 
void Ball::MoveBall(ManHinhChoi* in_window)
{
	sf::Vector2f wsize;
	wsize.x = in_window->GetWindowSize().x; 
	wsize.y = in_window->GetWindowSize().y;
	float bra = getRadius(); 
	// nếu đụng tường thì đổi hướng y. 
	if (getPosition().y > wsize.y - bra && basicDirect.y > 0) 
	{
		ReverseBasicDirectY(); 
	}
	if (getPosition().y < 0 && basicDirect.y < 0)
	{
		ReverseBasicDirectY(); 
	}
	sf::Vector2f newPos; 
	// tìm vị trí mới
	newPos.x = getPosition().x + speed*basicDirect.x; 
	newPos.y = getPosition().y + speed*basicDirect.y; 
	// cho bóng tới vị trí mới
	setPosition(newPos); 
}





