#pragma once

#include "ManHinhChoi.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"

using namespace std;

class VsBotMode
{
private:
	Ball m_ball;
	Paddle player1;
	Paddle player2;
	ManHinhChoi m_GameScreen;
	int point1;
	int point2;
	int level;
public:
	VsBotMode();
	~VsBotMode() {};
	void Reset();
	void ResetAll();
	ManHinhChoi* getWindow();
	void Input();
	void Update();
	void Render();
	void checkBallCollusionWithPaddleAndLeftRightWall();
	int CheckWinnerAndEndGame();
};

