#pragma once

#include "ManHinhChoi.h"
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include<windows.h>
#include "Ball.h"
#include "Paddle.h"

using namespace std;

class TheGame
{
private : 
	Ball m_ball;
	Paddle player1; 
	Paddle player2;
	ManHinhChoi m_GameScreen; 
	int point1; 
	int point2;
	sf::Texture texture;
	sf::SoundBuffer buf;
	sf::SoundBuffer mainbuf;
	sf::SoundBuffer scorebuf;
	sf::SoundBuffer winbuf;
public : 
	TheGame();
	~TheGame() {}; 
	void Reset(); 
	void ResetAll(); 
	ManHinhChoi* getWindow();
	void Input(); 
	void Update();
	void Render(); 
	void checkBallCollusionWithPaddleAndLeftRightWall(); 
	int CheckWinnerAndEndGame(); 
};

