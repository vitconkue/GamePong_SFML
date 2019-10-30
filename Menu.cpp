#include "Menu.h"

//void Menu::TapToContinued(sf::RenderWindow& window)
//{
//	sf::Texture texture;
//	if (!texture.loadFromFile("ControllerBackgrounds.png"))
//	{
//		cout << "Fails to load texture file!!!";
//	}
//	sf::Sprite sprite(texture);
//	window.draw(sprite);
//	if (!font.loadFromFile("AmaticB.ttf"))
//	{
//		cout << "Fails to load font file!!!";
//	}
//	sf::Text a;
//	a.setFont(font);
//	a.setFillColor(sf::Color::White);
//	a.setCharacterSize(150);
//	a.setString("PONG GAME");
//	a.setPosition(300, 150);
//	sf::Text b;
//	b.setFont(font);
//	b.setFillColor(sf::Color::Red);
//	b.setCharacterSize(40);
//	b.setString("Press Enter To Play!!!");
//	b.setPosition(400, 400);
//	window.draw(a);
//	window.draw(b);
//	window.display();
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
//	{
//		window.close();
//	}
//
//}

int Menu::MainMenu(sf::RenderWindow& window)
{
	LuaChon = 0;
	//Load file am thanh va hieu ung am thanh
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	sf::SoundBuffer mainbuffer;
	if (!buffer1.loadFromFile("MenuSound1.ogg"))
	{
		cout << "Fails to load sound files";
	}

	if (!buffer2.loadFromFile("MenuSound2.ogg"))
	{
		cout << "Fails to load sound file";
	}
	if (!mainbuffer.loadFromFile("MenuMusic.ogg"))
	{
		cout << "Fails to load sound file";
	}
	sf::Sound sound1;
	sf::Sound sound2;
	sf::Sound mainsound;
	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);
	mainsound.setBuffer(mainbuffer);
	if (!font.loadFromFile("NexaRust.otf"))
	{
		cout << "Fails to load font file!!!";
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("1 PLAYER MODE");
	menu[0].setCharacterSize(50);
	menu[0].setPosition(100, 100);


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setCharacterSize(50);
	menu[1].setPosition(100, 200);
	menu[1].setString("2 PLAYERS MODE");

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setCharacterSize(50);
	menu[2].setPosition(100, 300);
	menu[2].setString("EXIT");
	mainsound.play();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
				{
					Len();
					sound1.play();
					break;
				}
				case sf::Keyboard::Down:
				{
					Xuong();
					sound1.play();
					break;
				}
				case sf::Keyboard::Return:
				{
					switch (LuaChon)
					{
					case 0:
					{
						sound2.play();
						Sleep(500);
						return 1;
					}
					case 1:
					{
						sound2.play();
						Sleep(500);
						return 0;
					}
					case 2:
					{
						sound2.play();
						Sleep(750);
						return 2;
					}
					}

					break;
				}
				}

				break;
			case sf::Event::Closed:

				window.close();

				break;

			}
		}

		window.clear();
		sf::Sprite sprite(tex);
		window.draw(sprite);

		for (int i = 0; i < 3; i++)
		{
			window.draw(menu[i]);
		}

		window.display();
	}
}

int Menu::Ve()
{
	//Ve Tap Enter to Continued
	sf::RenderWindow window(sf::VideoMode(1000, 600), "PONG GAME");
	//while (window.isOpen())
	//{
	//	window.clear();
	//	TapToContinued(window);
	//}
	//window.clear();
	//Ve Main Menu
	window.clear();
	int gt = MainMenu(window);
	return gt;
}

void Menu::Len()
{
	if (LuaChon > 0)
	{
		menu[LuaChon].setFillColor(sf::Color::White);
		LuaChon--;
		menu[LuaChon].setFillColor(sf::Color::Cyan);
	}
	else
	{
		menu[LuaChon].setFillColor(sf::Color::White);
		LuaChon = 2;
		menu[LuaChon].setFillColor(sf::Color::Cyan);
	}
}

void Menu::Xuong()
{
	if (LuaChon < 2)
	{
		menu[LuaChon].setFillColor(sf::Color::White);
		LuaChon++;
		menu[LuaChon].setFillColor(sf::Color::Cyan);
	}
	else
	{
		menu[LuaChon].setFillColor(sf::Color::White);
		LuaChon = 0;
		menu[LuaChon].setFillColor(sf::Color::Cyan);
	}
}

int Menu::EndGame_2PL(int kq)
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "GAME FINISHED");
	//Load file am thanh va hieu ung am thanh
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	if (!buffer1.loadFromFile("MenuSound1.ogg"))
	{
		cout << "Fails to load sound files";
	}

	if (!buffer2.loadFromFile("MenuSound2.ogg"))
	{
		cout << "Fails to load sound file";
	}
	sf::Sound sound1;
	sf::Sound sound2;
	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);
	//Set up cac doi tuong in len man hinh
	sf::Texture b;
	b.loadFromFile("MenuBack.png");
	sf::Sprite back(b);
	sf::Text a;
	if (!font.loadFromFile("pointfont.ttf"))
	{
		cout << "Fails to load font file";
	}

	a.setFont(font);
	a.setFillColor(sf::Color::Yellow);
	a.setOutlineThickness(3);
	a.setOutlineColor(sf::Color::Black);
	a.setPosition(115, 50);
	a.setCharacterSize(75);
	if (kq == 1)
	{
		a.setOutlineColor(sf::Color::Blue);
		a.setString("PLAYER 1 WIN");
	}
	else
	{
		a.setOutlineColor(sf::Color::Red);
		a.setString("PLAYER 2 WIN");
	}
	sf::Texture tex[4];
	tex[0].loadFromFile("return.png");
	tex[1].loadFromFile("Rmainmenu.png");
	tex[2].loadFromFile("return_c.png");
	tex[3].loadFromFile("Rmainmenu_c.png");
	sf::Sprite spr[2];
	spr[0].setTexture(tex[2]);
	spr[1].setTexture(tex[1]);
	spr[0].setPosition(175, 200);
	spr[1].setPosition(350, 200);
	//Thuc thi menu
	int lc = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
				{
					//Truong hop nguoi choi nhan Up
					if (lc > 0)
					{
						spr[lc].setTexture(tex[lc]);
						lc--;
						spr[lc].setTexture(tex[lc + 2]);
					}
					else
					{
						spr[lc].setTexture(tex[lc]);
						lc = 1;
						spr[lc].setTexture(tex[lc + 2]);
					}
					sound1.play();
					break;
				}
				case sf::Keyboard::Right:
				{
					//Truong hop nguoi choi nhan Down
					if (lc < 1)
					{
						spr[lc].setTexture(tex[lc]);
						lc++;
						spr[lc].setTexture(tex[lc + 2]);
					}
					else
					{
						spr[lc].setTexture(tex[lc]);
						lc = 0;
						spr[lc].setTexture(tex[lc + 2]);
					}
					sound1.play();
					break;
				}
				case sf::Keyboard::Return:
				{
					sound2.play();
					Sleep(500);
					switch (lc)
					{
					case 0:
					{
						return 1;
					}
					case 1:
					{
						return 2;
					}
					}

					break;
				}
				}

				break;
			case sf::Event::Closed:

				window.close();

				break;

			}
		}

		window.clear();
		window.draw(back);
		window.draw(a);
		for (int i = 0; i < 2; i++)
		{
			window.draw(spr[i]);
		}

		window.display();
	}

	return 0;
}

int Menu::EndGame_1PL(int kq)
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "GAME FINISHED");
	//Load file am thanh va hieu ung am thanh
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	if (!buffer1.loadFromFile("MenuSound1.ogg"))
	{
		cout << "Fails to load sound files";
	}

	if (!buffer2.loadFromFile("MenuSound2.ogg"))
	{
		cout << "Fails to load sound file";
	}
	sf::Sound sound1;
	sf::Sound sound2;
	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);
	//Set up cac doi tuong in len man hinh
	sf::Texture b;
	b.loadFromFile("MenuBack.png");
	sf::Sprite back(b);
	sf::Text a;
	if (!font.loadFromFile("pointfont.ttf"))
	{
		cout << "Fails to load font file";
	}

	a.setFont(font);
	a.setFillColor(sf::Color::Yellow);
	a.setOutlineThickness(3);
	a.setOutlineColor(sf::Color::Black);
	a.setPosition(175, 50);
	a.setCharacterSize(75);
	if (kq == 1)
	{
		a.setString("BOT WIN");
	}
	else
	{
		a.setString("YOU WIN");
	}
	sf::Texture tex[4];
	tex[0].loadFromFile("return.png");
	tex[1].loadFromFile("Rmainmenu.png");
	tex[2].loadFromFile("return_c.png");
	tex[3].loadFromFile("Rmainmenu_c.png");
	sf::Sprite spr[2];
	spr[0].setTexture(tex[2]);
	spr[1].setTexture(tex[1]);
	spr[0].setPosition(175, 200);
	spr[1].setPosition(350, 200);
	//Thuc thi menu
	int lc = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
				{
					//Truong hop nguoi choi nhan Up
					if (lc > 0)
					{
						spr[lc].setTexture(tex[lc]);
						lc--;
						spr[lc].setTexture(tex[lc + 2]);
					}
					else
					{
						spr[lc].setTexture(tex[lc]);
						lc = 1;
						spr[lc].setTexture(tex[lc + 2]);
					}
					sound1.play();
					break;
				}
				case sf::Keyboard::Right:
				{
					//Truong hop nguoi choi nhan Down
					if (lc < 1)
					{
						spr[lc].setTexture(tex[lc]);
						lc++;
						spr[lc].setTexture(tex[lc + 2]);
					}
					else
					{
						spr[lc].setTexture(tex[lc]);
						lc = 0;
						spr[lc].setTexture(tex[lc + 2]);
					}
					sound1.play();
					break;
				}
				case sf::Keyboard::Return:
				{
					sound2.play();
					Sleep(500);
					switch (lc)
					{
					case 0:
					{
						return 1;
					}
					case 1:
					{
						return 2;
					}
					}

					break;
				}
				}

				break;
			case sf::Event::Closed:

				window.close();

				break;

			}
		}

		window.clear();
		window.draw(back);
		window.draw(a);
		for (int i = 0; i < 2; i++)
		{
			window.draw(spr[i]);
		}

		window.display();
	}

	return 0;
}

int Menu::Pause()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "PAUSE");
	//Load file am thanh va hieu ung am thanh
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	if (!buffer1.loadFromFile("MenuSound1.ogg"))
	{
		cout << "Fails to load sound files";
	}

	if (!buffer2.loadFromFile("MenuSound2.ogg"))
	{
		cout << "Fails to load sound file";
	}
	sf::Sound sound1;
	sf::Sound sound2;
	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);
	//Set up cac doi tuong in len man hinh
	sf::Texture b;
	b.loadFromFile("MenuBack.png");
	sf::Sprite back(b);
	sf::Text a;
	if (!font.loadFromFile("pointfont.ttf"))
	{
		cout << "Fails to load font file";
	}

	a.setFont(font);
	a.setFillColor(sf::Color::Yellow);
	a.setOutlineThickness(3);
	a.setOutlineColor(sf::Color::Black);
	a.setPosition(175, 50);
	a.setCharacterSize(100);


	a.setString("PAUSE");
	sf::Texture tex[6];
	tex[0].loadFromFile("play.png");
	tex[1].loadFromFile("return.png");
	tex[2].loadFromFile("Rmainmenu.png");
	tex[3].loadFromFile("play_c.png");
	tex[4].loadFromFile("return_c.png");
	tex[5].loadFromFile("Rmainmenu_c.png");
	sf::Sprite spr[3];
	spr[0].setTexture(tex[3]);
	spr[1].setTexture(tex[1]);
	spr[2].setTexture(tex[2]);
	spr[0].setPosition(75, 200);
	spr[1].setPosition(250, 200);
	spr[2].setPosition(425, 200);
	//Thuc thi menu
	int lc = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
				{
					//Truong hop nguoi choi nhan Up
					if (lc > 0)
					{
						spr[lc].setTexture(tex[lc]);
						lc--;
						spr[lc].setTexture(tex[lc + 3]);
					}
					else
					{
						spr[lc].setTexture(tex[lc]);
						lc = 2;
						spr[lc].setTexture(tex[lc + 3]);
					}
					sound1.play();
					break;
				}
				case sf::Keyboard::Right:
				{
					//Truong hop nguoi choi nhan Down
					if (lc < 2)
					{
						spr[lc].setTexture(tex[lc]);
						lc++;
						spr[lc].setTexture(tex[lc + 3]);
					}
					else
					{
						spr[lc].setTexture(tex[lc]);
						lc = 0;
						spr[lc].setTexture(tex[lc + 3]);
					}
					sound1.play();
					break;
				}
				case sf::Keyboard::Return:
				{
					sound2.play();
					Sleep(500);
					switch (lc)
					{
					case 0:
					{
						return 1;
					}
					case 1:
					{
						return 2;
					}
					case 2:
					{
						return 3;
					}
					}

					break;
				}
				}

				break;
			case sf::Event::Closed:

				window.close();

				break;

			}
		}

		window.clear();
		window.draw(back);
		window.draw(a);
		for (int i = 0; i < 3; i++)
		{
			window.draw(spr[i]);
		}

		window.display();
	}

	return 0;
}

int Menu::WinScore()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "CHOOSE WIN SCORE");
	tex.loadFromFile("InGameBackground.png");
	//Load file am thanh va hieu ung am thanh
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	if (!buffer1.loadFromFile("MenuSound1.ogg"))
	{
		cout << "Fails to load sound files";
	}

	if (!buffer2.loadFromFile("MenuSound2.ogg"))
	{
		cout << "Fails to load sound file";
	}
	sf::Sound sound1;
	sf::Sound sound2;
	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);
	sf::Sprite sp;
	sp.setTexture(tex);
	int wscore = 1;
	sf::Texture tex[4];
	tex[0].loadFromFile("deplay.png");
	tex[1].loadFromFile("play.png");
	tex[2].loadFromFile("deplay_c.png");
	tex[3].loadFromFile("play_c.png");
	sf::Sprite spr[2];
	spr[0].setTexture(tex[0]);
	spr[1].setTexture(tex[1]);
	spr[0].setPosition(200, 300);
	spr[1].setPosition(700, 300);
	font.loadFromFile("pointfont.ttf");
	sf::Text a;
	a.setFont(font);
	a.setCharacterSize(70);
	a.setPosition(225, 100);
	a.setFillColor(sf::Color::White);
	a.setString("Choose win score");
	sf::Text s;
	s.setCharacterSize(75);
	s.setFont(font);
	s.setPosition(480, 300);
	s.setFillColor(sf::Color::White);
	while (window.isOpen())
	{
		int kt = 0;
		sf::Event event;
		spr[0].setTexture(tex[0]);
		spr[1].setTexture(tex[1]);
		s.setString(toString(wscore));
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
				{
					//Truong hop nguoi choi nhan Left
					if (wscore > 1)
					{
						wscore--;
						spr[0].setTexture(tex[2]);
						kt = 1;
					}
					sound1.play();
					break;
				}
				case sf::Keyboard::Right:
				{
					///Truong hop nguoi choi nhan Left
					if (wscore < 20)
					{
						wscore++;
						spr[1].setTexture(tex[3]);
						kt = 1;
					}
					sound1.play();
					break;
				}
				case sf::Keyboard::Return:
				{
					sound2.play();
					Sleep(500);
					return wscore;
					break;
				}
				}

				break;
			case sf::Event::Closed:

				window.close();

				break;

			}
		}

		window.clear();
		window.draw(sp);
		window.draw(a);
		window.draw(s);
		for (int i = 0; i < 2; i++)
		{
			window.draw(spr[i]);
		}

		window.display();
		if (kt == 1)
		{
			Sleep(100);
		}
	}
	return 0;
}

string Menu::toString(int a)
{
	string str = "";
	if (a == 0)
	{
		str = "0";
	}
	while (a != 0)
	{
		str += char(a % 10 + 48);
		a /= 10;
	}
	for (int i = 0; i < str.length() / 2; i++)
	{
		swap(str[i], str[str.length() - i - 1]);
	}
	return str;
}

Menu::Menu()
{
	LuaChon = 0;
	if (!tex.loadFromFile("MainMenu.png"))
	{
		cout<<"Load fails";
	}
}
Menu::~Menu()
{

}
