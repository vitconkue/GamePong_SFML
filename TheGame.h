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
	// constructor cho game
	TheGame();
	// destructor cho game
	~TheGame() {}; 
	// Reset game
	void Reset(); 
	// reset tất cả khi đã chơi xong
	void ResetAll(); 
	// getter màn hình
	ManHinhChoi* getWindow();
	// xử lí nhập bàn phím
	void Input(); 
	// xử lí thành phần game
	void Update();
	// vẽ lên màn hình
	void Render(); 
	// bóng chạm thanh và tường 
	void checkBallCollusionWithPaddleAndLeftRightWall(); 
	// kiếm tra người thắng, kết thúc game
	int CheckWinnerAndEndGame(); 
};

