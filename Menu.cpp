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
	//Load font
	if (!font.loadFromFile("NexaRust.otf"))
	{
		cout << "Fails to load font file!!!";
	}
	//Set up các thuộc tính của dòng thứ nhất "1 PLAYER MODE"
	//Dùng font đã load
	menu[0].setFont(font);
	//Sử dụng màu Cyan
	menu[0].setFillColor(sf::Color::Cyan);
	//set string
	menu[0].setString("1 PLAYER MODE");
	//Set kích thước chữ
	menu[0].setCharacterSize(50);
	//Set vị trí
	menu[0].setPosition(100, 100);

	//Set up các thuộc tính của dòng thứ nhất "2 PLAYERs MODE"
	//Dùng font đã load
	menu[1].setFont(font);
	//Màu
	menu[1].setFillColor(sf::Color::White);
	//Kích thước chữ
	menu[1].setCharacterSize(50);
	//Vị trí trên cửa sổ
	menu[1].setPosition(100, 200);
	menu[1].setString("2 PLAYERS MODE");

	//Set up các thuộc tính của dòng thứ nhất "EXIT"
	//Dùng font đã load
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setCharacterSize(50);
	menu[2].setPosition(100, 300);
	menu[2].setString("EXIT");

	//Choi nhac
	mainsound.play();
	while (window.isOpen())
	{
		//Tao event
		sf::Event event;
		while (window.pollEvent(event))
		{
			//Phân loại
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
				{
					//trường hợp nhấn Up
					Len();
					sound1.play();
					break;
				}
				case sf::Keyboard::Down:
				{
					//Trường hợp nhấn Down
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
		//Xoa man hinh
		window.clear();
		//Tao Sprite và load texture vào Sprite
		sf::Sprite sprite(tex);
		//Vẽ Sprite
		window.draw(sprite);
		//Vẽ các đối tượng của menu
		for (int i = 0; i < 3; i++)
		{
			window.draw(menu[i]);
		}
		//Im lên màn hình cửa sổ
		window.display();
	}
}

int Menu::Ve()
{
	//Hàm vẽ và trả về giá trị tương ứng với lựa chọn của người chơi
	sf::RenderWindow window(sf::VideoMode(1000, 600), "PONG GAME");
	//Ve Main Menu
	window.clear();
	int gt = MainMenu(window);
	return gt;
}

//Xử lí thao tác chọn Up của Main Menu
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
//Xử lí thao tác chọn Down của Main Menu
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

//Menu kết thúc game đối với mode 2 người chơi
//Biến kq được truyền và là số chỉ người chiến thắng
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
	//Load các texture từ file png
	sf::Texture tex[4];
	tex[0].loadFromFile("return.png");
	tex[1].loadFromFile("Rmainmenu.png");
	tex[2].loadFromFile("return_c.png");
	tex[3].loadFromFile("Rmainmenu_c.png");
	//Tạo 2 đối tượng icon in ra màn hình 
	sf::Sprite spr[2];
	//Ban đầu đang trong trang thái chọn lựa chọn 1 nên set tex[2] cho spr[0]
	spr[0].setTexture(tex[2]);
	spr[1].setTexture(tex[1]);
	spr[0].setPosition(175, 200);
	spr[1].setPosition(350, 200);
	//Thuc thi menu
	int lc = 0;
	while (window.isOpen())
	{
		//Tạo event
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
						//Set texture khác cho đối tượng
						spr[lc].setTexture(tex[lc]);
						lc--;
						//Set texture khác cho đối tượng còn lại
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
					//Sleep chương trình để nhạc chạy và người xem nhìn rõ lựa chọn của mình.
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
		//Clear màn hình cửa sổ
		window.clear();
		//Vẽ background
		window.draw(back);
		//Vẽ dòng Text
		window.draw(a);
		//vẽ các đối tượng trong bản chọn
		for (int i = 0; i < 2; i++)
		{
			window.draw(spr[i]);
		}
		//In ra màn hình
		window.display();
	}

	return 0;
}

//Tương tự hàm EndGame_2PL bên trên
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

//Quản lí cửa sổ tạm dừng game
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
	//Set độ dày viền chữ
	a.setOutlineThickness(3);
	//Set màu viền chữ
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

//Menu chọn điểm thắng
int Menu::WinScore()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "CHOOSE WIN SCORE");
	//Load texture
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
	//Set texture vào Sprite
	sp.setTexture(tex);
	//Để mặc định số điểm ban đầu là 1
	int wscore = 1;
	//Tạo mảng 4 Texture bao gồm 2 trạng thái của 2 đối tượng Sprite
	sf::Texture tex[4];
	tex[0].loadFromFile("deplay.png");
	tex[1].loadFromFile("play.png");
	tex[2].loadFromFile("deplay_c.png");
	tex[3].loadFromFile("play_c.png");
	//Tạo mảng các đối tưởng Sprite
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
		//Set lại texture ban đầu trước khi có hoạt ảnh thay đổi
		spr[0].setTexture(tex[0]);
		spr[1].setTexture(tex[1]);
		//Dùng hàm toString trả về giá trị wscore kiểu stirng để set vào s
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
						//Thay đổi texture của Sprite tương ứng với lựa chọn để người chơi nhận biết mình vừa lựa chọn
						spr[0].setTexture(tex[2]);
						//Tạo biến kt xem người chơi có nhập Input không
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
		//nếu người chơi có nhập Input thì cho tạm dừng cửa sổ 0,1 tạm thời để người chơi nhận ra sử thay đổi trạng thái sau khi set texture khác cho Sprite tương ứng với Inout nhập vào
		if (kt == 1)
		{
			Sleep(100);
		}
	}
	return 0;
}
//Hàm trả về giá trị kiểu string. (dùng để in kiểu số ra màn hình)
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

//Set up ban đầu cho tất cả các menu 

Menu::Menu()
{
	//Lựa chọn ban đầu mặc định luôn là lựa chọn đầu tiên
	LuaChon = 0;
	//Load Texture mặc định cho menu
	if (!tex.loadFromFile("MainMenu.png"))
	{
		cout<<"Load fails";
	}
}
Menu::~Menu()
{

}
