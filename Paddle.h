#pragma once
#include <SFML/Graphics.hpp>
#include "ManHinhChoi.h"

class Paddle : public sf::RectangleShape
{
public : 
	// constructor cho thanh 
	Paddle(); 
	// thanh đi lên
	void MoveUp(ManHinhChoi* in_window); 
	// thanh đi xuống
	void MoveDown(ManHinhChoi* in_window);
};

