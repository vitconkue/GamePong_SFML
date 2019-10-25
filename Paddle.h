#pragma once
#include <SFML/Graphics.hpp>
#include "ManHinhChoi.h"

class Paddle : public sf::RectangleShape
{
public : 
	Paddle(); 
	void MoveUp(ManHinhChoi* in_window); 
	void MoveDown(ManHinhChoi* in_window);
	void BotMoveUp(ManHinhChoi* in_window);
	void BotMoveDown(ManHinhChoi* in_window);
};

