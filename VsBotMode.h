#pragma once

#include "ManHinhChoi.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include<windows.h>
#include "Ball.h"
#include "Paddle.h"

using namespace std;

class VsBotMode
{
private:
	Ball m_ball;
	Paddle bot;
	Paddle player;
	ManHinhChoi m_GameScreen;
	int point1;
	int point2;
	int level;
	sf::Texture texture;
	sf::SoundBuffer buf;
	sf::SoundBuffer mainbuf;
	sf::SoundBuffer scorebuf;
	sf::SoundBuffer winbuf;
	
public:
	VsBotMode();
	~VsBotMode() {};
	void Reset();
	void ResetAll();
	ManHinhChoi* getWindow();
	void Input();
	void Update();
	void Render();
	void BotMove();
	void checkBallCollusionWithPaddleAndLeftRightWall();
	int CheckWinnerAndEndGame();
	void PlayMainMusic();
};

