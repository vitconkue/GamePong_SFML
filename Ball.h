#pragma once

#include "ManHinhChoi.h"
#include <SFML/Graphics.hpp>
class Ball : public sf::CircleShape
{
private: 
	float speed;  
	sf::Vector2f basicDirect; // huong
public :
	Ball(); 
	Ball(float sp, sf::Vector2f incre); 
	float getSpeed() { return speed;  }
	void setSpeed(float in) { speed = in;  }
	sf::Vector2f getBasicDirect() { return basicDirect;  }
	void setBasicDirect(sf::Vector2f in) { basicDirect = in;  }
	void ReverseBasicDirectX() { basicDirect.x = -basicDirect.x;  }
	void ReverseBasicDirectY() { basicDirect.y = -basicDirect.y;  }
	void ReverseBasicDirect() { basicDirect = -basicDirect;  }
	sf::Vector2f getIncrement() { return basicDirect; }
	void MoveBall(ManHinhChoi* in_window); 

};

