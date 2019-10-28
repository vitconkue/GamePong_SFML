#pragma once

#include "ManHinhChoi.h"
#include <SFML/Graphics.hpp>
class Ball : public sf::CircleShape
{
private: 
	float speed; // tốc độ bóng  
	sf::Vector2f basicDirect; // hướng
public :
	// constructor cho bóng
	Ball(); 
	// constructor cho bóng, truyền vào tốc độ và hướng
	Ball(float sp, sf::Vector2f incre); 
	// getter speed
	float getSpeed() { return speed;  }
	// thay đổi tốc độ (setter speed) 
	void setSpeed(float in) { speed = in;  }
	// getter lấy hướng
	sf::Vector2f getBasicDirect() { return basicDirect;  }
	// setter hướng
	void setBasicDirect(sf::Vector2f in) { basicDirect = in;  }
	// đảo hướng theo chiều x
	void ReverseBasicDirectX() { basicDirect.x = -basicDirect.x;  }
	// đảo hướng theo chiều y
	void ReverseBasicDirectY() { basicDirect.y = -basicDirect.y;  }
	// đảo hướng theo cả 2 chiều ( hướng ngược)
	void ReverseBasicDirect() { basicDirect = -basicDirect;  }
	
	//sf::Vector2f getIncrement() { return basicDirect; }

	// di chuyển bóng, truyền vào màn hình hiện tại
	void MoveBall(ManHinhChoi* in_window); 

};

