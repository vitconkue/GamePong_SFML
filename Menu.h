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
	sf::Texture tex;
public:
	int Ve();
	//Thay doi khi nguoi choi nhan Len
	void Len();
	//Thay doi khi nguoi choi nhan Xuong
	void Xuong();
	void TapToContinued(sf::RenderWindow& window);
	//Ve Menu chinh
	int MainMenu(sf::RenderWindow& window);
	//Ve menu ket thuc game 2 nguoi choi
	int EndGame_2PL(int kq);
	//Ve menu ket thuc game 1 nguoi choi vs bot
	int EndGame_1PL(int kq);
	//Menu tam dung
	int Pause();
	//Menu chon diem toi da de thang
	int WinScore();
	string toString(int a);
	Menu();
	~Menu();
};



