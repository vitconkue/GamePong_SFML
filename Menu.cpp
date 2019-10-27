#include "Menu.h"

void Menu::TapToContinued(sf::RenderWindow& window)
{
	sf::Texture texture;
	if (!texture.loadFromFile("ControllerBackgrounds.png"))
	{
		cout << "Fails to load texture file!!!";
	}
	sf::Sprite sprite(texture);
	window.draw(sprite);
	if (!font.loadFromFile("AmaticB.ttf"))
	{
		cout << "Fails to load font file!!!";
	}
	sf::Text a;
	a.setFont(font);
	a.setFillColor(sf::Color::White);
	a.setCharacterSize(150);
	a.setString("PONG GAME");
	a.setPosition(300, 150);
	sf::Text b;
	b.setFont(font);
	b.setFillColor(sf::Color::Red);
	b.setCharacterSize(40);
	b.setString("Press Enter To Play!!!");
	b.setPosition(400, 400);
	window.draw(a);
	window.draw(b);
	window.display();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		window.close();
	}

}

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
	menu[0].setString("PLAY");
	menu[0].setCharacterSize(50);
	menu[0].setPosition(100, 100);


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setCharacterSize(50);
	menu[1].setPosition(100, 200);
	menu[1].setString("OPTIONS");

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
						Sleep(750);
						return 0;
					}
					case 1:
					{
						sound2.play();
						Sleep(750);
						return 1;
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
	sf::RenderWindow window(sf::VideoMode(500, 300), "GAME FINISHED");
	//Set up cac doi tuong in len man hinh
	sf::Text a[3];
	sf::Font font;
	if (!font.loadFromFile("pointfont.ttf"))
	{
		cout << "Fails to load font file";
	}
	a[0].setFillColor(sf::Color::White);
	a[0].setFont(font);
	a[0].setPosition(200, 50);
	if (kq == 1)
	{
		a[0].setString("PLAYER 1 WIN!!!");
	}
	else
	{
		a[0].setString("PLAYER 2 WIN!!!");
	}
	a[1].setFillColor(sf::Color::Cyan);
	a[1].setFont(font);
	a[1].setPosition(200, 150);
	a[1].setString("PLAY AGAIN");
	a[2].setFillColor(sf::Color::White);
	a[2].setFont(font);
	a[2].setPosition(200, 250);
	a[2].setString("MAIN MENU");
	//Thuc thi menu
	int lc = 1;
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
					//Truong hop nguoi choi nhan Up
					if (lc > 1)
					{
						a[lc].setFillColor(sf::Color::White);
						lc--;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					else
					{
						a[lc].setFillColor(sf::Color::White);
						lc = 2;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					break;
				}
				case sf::Keyboard::Down:
				{
					//Truong hop nguoi choi nhan Down
					if (lc < 2)
					{
						a[lc].setFillColor(sf::Color::White);
						lc++;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					else
					{
						a[lc].setFillColor(sf::Color::White);
						lc = 1;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					break;
				}
				case sf::Keyboard::Return:
				{
					switch (lc)
					{
					case 1:
					{
						return 1;
					}
					case 2:
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

		for (int i = 0; i < 3; i++)
		{
			window.draw(a[i]);
		}

		window.display();
	}
	return 0;
}

int Menu::EndGame_1PL(int kq)
{
	sf::RenderWindow window(sf::VideoMode(500, 300), "GAME FINISHED");
	//Set up cac doi tuong in len man hinh
	sf::Text a[3];
	sf::Font font;
	if (!font.loadFromFile("pointfont.ttf"))
	{
		cout << "Fails to load font file";
	}
	a[0].setFillColor(sf::Color::White);
	a[0].setFont(font);
	a[0].setPosition(200, 50);
	if (kq == 1)
	{
		a[0].setString("BOT WIN!!!");
	}
	else
	{
		a[0].setString("YOU WIN!!!");
	}
	a[1].setFillColor(sf::Color::Cyan);
	a[1].setFont(font);
	a[1].setPosition(200, 150);
	a[1].setString("PLAY AGAIN");
	a[2].setFillColor(sf::Color::White);
	a[2].setFont(font);
	a[2].setPosition(200, 250);
	a[2].setString("MAIN MENU");
	//Thuc thi menu
	int lc = 1;
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
					//Truong hop nguoi choi nhan Up
					if (lc > 1)
					{
						a[lc].setFillColor(sf::Color::White);
						lc--;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					else
					{
						a[lc].setFillColor(sf::Color::White);
						lc = 2;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					break;
				}
				case sf::Keyboard::Down:
				{
					//Truong hop nguoi choi nhan Down
					if (lc < 2)
					{
						a[lc].setFillColor(sf::Color::White);
						lc++;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					else
					{
						a[lc].setFillColor(sf::Color::White);
						lc = 1;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					break;
				}
				case sf::Keyboard::Return:
				{
					switch (lc)
					{
					case 1:
					{
						return 1;
					}
					case 2:
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

		for (int i = 0; i < 3; i++)
		{
			window.draw(a[i]);
		}

		window.display();
	}
	return 0;
}

int Menu::Pause()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "GAME FINISHED");
	//Set up cac doi tuong in len man hinh
	sf::Text a[4];
	sf::Font font;
	if (!font.loadFromFile("pointfont.ttf"))
	{
		cout << "Fails to load font file";
	}
	a[0].setFillColor(sf::Color::White);
	a[0].setFont(font);
	a[0].setPosition(200, 50);
	a[0].setString("PAUSE");
	a[1].setFillColor(sf::Color::Cyan);
	a[1].setFont(font);
	a[1].setPosition(200, 150);
	a[1].setString("CONTINUED");
	a[2].setFillColor(sf::Color::White);
	a[2].setFont(font);
	a[2].setPosition(200, 250);
	a[2].setString("RESTART");
	a[3].setFillColor(sf::Color::White);
	a[3].setFont(font);
	a[3].setPosition(200, 300);
	a[3].setString("MAIN MENU");
	//Thuc thi menu
	int lc = 1;
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
					//Truong hop nguoi choi nhan Up
					if (lc > 1)
					{
						a[lc].setFillColor(sf::Color::White);
						lc--;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					else
					{
						a[lc].setFillColor(sf::Color::White);
						lc = 3;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					break;
				}
				case sf::Keyboard::Down:
				{
					//Truong hop nguoi choi nhan Down
					if (lc < 3)
					{
						a[lc].setFillColor(sf::Color::White);
						lc++;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					else
					{
						a[lc].setFillColor(sf::Color::White);
						lc = 1;
						a[lc].setFillColor(sf::Color::Cyan);
					}
					break;
				}
				case sf::Keyboard::Return:
				{
					switch (lc)
					{
					case 1:
					{
						return 1;
					}
					case 2:
					{
						return 2;
					}
					case 3:
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

		for (int i = 0; i < 4; i++)
		{
			window.draw(a[i]);
		}

		window.display();
	}
	return 0;
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
