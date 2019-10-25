#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<windows.h>
using namespace std;
class Menu
{
private:
	int LuaChon;
	sf::Text menu[3];
	sf::Font font;
public:
	int Ve();
	void Len();
	void Xuong();
	void TapToContinued(sf::RenderWindow& window);
	int MainMenu(sf::RenderWindow& window);
	int EndGame_2PL(int kq);
	int EndGame_1PL(int kq);
	Menu();
	~Menu();
};



