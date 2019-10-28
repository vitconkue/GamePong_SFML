#include "TheGame.h"

TheGame::TheGame() : m_GameScreen(), m_ball(),player1(), player2()
{
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();  // lấy kích cỡ màn hình game
	m_ball.setPosition(wsize.x / 2,wsize.y / 2); // bóng ở giữa
	player1.setPosition( 20+player1.getSize().x / 2, wsize.y / 2);  // player 1 bên trái màn hình
	player2.setFillColor(sf::Color::Red);
	player2.setPosition(wsize.x - 20 - player2.getSize().x / 2, wsize.y / 2); // player 2 bên phải màn hình
	point1 = point2 = 0; 
	if (!texture.loadFromFile("InGameBackground.png"))
	{
		cout << "Load fails";
	}
	if (!buf.loadFromFile("MenuSound1.ogg"))
	{
		cout << "Load fails";
	}
	if (!mainbuf.loadFromFile("2PLInGameMusic.ogg"))
	{
		cout << "Load fails";
	}
	if (!scorebuf.loadFromFile("ding.ogg"))
	{
		cout << "Load fails";
	}
	if (!winbuf.loadFromFile("wingame.ogg"))
	{
		cout << "Load fails";
	}
}



void TheGame::Reset()
{
	// set về trạng thái ban đầu ( vẫn giữ điểm)
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();
	m_ball.setPosition(wsize.x / 2, wsize.y / 2);
	player1.setPosition(20 + player1.getSize().x / 2, wsize.y / 2);
	player2.setPosition(wsize.x - 20 - player2.getSize().x / 2, wsize.y / 2);
	m_ball.setSpeed(3.0f);
}

void TheGame::ResetAll()
{
	// Reset tất cả khi đã kết thúc game
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();
	m_ball.setPosition(wsize.x / 2, wsize.y / 2);
	player1.setPosition(20 + player1.getSize().x / 2, wsize.y / 2);
	player2.setPosition(wsize.x - 20 - player2.getSize().x / 2, wsize.y / 2);
	m_ball.setSpeed(3.0f);
	point1 = 0;  
	point2 = 0; 
}

ManHinhChoi* TheGame::getWindow()
{
	return &m_GameScreen;
}
int TheGame::Input()
{
	// xử lí khi người dùng nhập các nút
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player2.MoveUp(&m_GameScreen); 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player2.MoveDown(&m_GameScreen);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player1.MoveUp(&m_GameScreen);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player1.MoveDown(&m_GameScreen);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Reset(); 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		//Tam dung am thanh khi mo menu
		mainsound.pause();
		Menu m;
		int chon = m.Pause();
		if (chon == 1)
		{
			mainsound.play();
		}
		if (chon == 2)
		{
			//Cho phat nhac lai tu dau
			mainsound.stop();
			mainsound.play();
			ResetAll();
		}
		if (chon == 3)
		{
			return 1;
		}
	}
	return 0;
}
void TheGame::Update()
{
	// thực hiện tất cả các xử lí cần thiết trong 1 chu trình trước khi render
	m_GameScreen.Update(); 
	checkBallCollusionWithPaddleAndLeftRightWall(); 
	m_ball.MoveBall(&m_GameScreen);
	int res = CheckWinnerAndEndGame(); 
}
void TheGame::Render()
{
	// in ra màn hình
	m_GameScreen.StartDrawing(); 
	sf::Sprite sprite(texture);
	m_GameScreen.Display(sprite);
	m_GameScreen.Display(m_ball);
	m_GameScreen.Display(player1);
	m_GameScreen.Display(player2);

	//In diem
	sf::Font font;
	if (!font.loadFromFile("PointFont.ttf"))
	{
		cout << "Fails to load Point font!!!";
	}
	sf::Text p1;
	sf::Text p2;
	sf::Text winner;
	p1.setFont(font);
	p2.setFont(font);
	p1.setFillColor(sf::Color::White);
	p2.setFillColor(sf::Color::White);
	p1.setCharacterSize(75);
	p2.setCharacterSize(75);
	p1.setPosition(300, 50);
	p2.setPosition(700, 50);
	p1.setString(toString(point1));
	p2.setString(toString(point2));
	if (point1 == 3)
	{
		p1.setString(toString(point1));
		winner.setFont(font);
		winner.setFillColor(sf::Color::Blue);
		winner.setOutlineThickness(3);
		winner.setOutlineColor(sf::Color::White);
		winner.setPosition(320, 200);
		winner.setCharacterSize(75);
		winner.setString("PLAYER 1 WIN");
		m_GameScreen.Display(winner);
	}
	if (point2 == 3)
	{
		p2.setString(toString(point2));
		winner.setFont(font);
		winner.setFillColor(sf::Color::Red);
		winner.setOutlineThickness(3);
		winner.setOutlineColor(sf::Color::White);
		winner.setPosition(320, 200);
		winner.setCharacterSize(75);
		winner.setString("PLAYER 2 WIN");
		m_GameScreen.Display(winner);
	}
	m_GameScreen.Display(p1);
	m_GameScreen.Display(p2);
	m_GameScreen.InLenManHinh();
	if (point1 == 3 || point2 == 3)
	{
		//Dung nhac nen, phat nhac win
		mainsound.stop();
		sf::Sound s;
		s.setBuffer(winbuf);
		s.play();
		Sleep(5000);
	}

}

void TheGame::checkBallCollusionWithPaddleAndLeftRightWall()
{
	// lấy các thành phần cần thiết bằng các getter
	sf::Event ev; 
	sf::Vector2f ballpos = m_ball.getPosition(); 
	sf::Vector2f p1pos = player1.getPosition(); 
	sf::Vector2f p2pos = player2.getPosition(); 
	sf::Vector2f psize = player1.getSize();
	sf::Vector2f wsize = m_GameScreen.GetWindowSize(); 
	float bra = m_ball.getRadius(); 
	// chạm người chơi trái
	if (ballpos.x - bra <= p1pos.x + psize.x / 2 && m_ball.getBasicDirect().x ==-1) // nếu xét x đã chạm
	{
		if (ballpos.y <= p1pos.y + psize.y / 2 +20 &&
			ballpos.y >= p1pos.y - psize.y / 2-20 ) // nếu xét y đã chạm
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) 
				&& m_ball.getBasicDirect().y == 1)// trường hợp người chơi đang cho thanh đi lên => bóng cũng đi lên
			{
				m_ball.ReverseBasicDirect();
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
					&& m_ball.getBasicDirect().y == -1) // trường hợp người chơi đang cho thanh đi xuống => bóng cũng đi xuống
				{
					m_ball.ReverseBasicDirect();
				}
				else
				{
					m_ball.ReverseBasicDirectX(); 
				}
			}
			m_ball.setSpeed(m_ball.getSpeed() * 1.1); // tăng tốc độ 10%
			sf::Sound sound;
			sound.setBuffer(buf);
			sound.play();
			Sleep(20);
        }

	}
	// chạm người chơi phải
	if (ballpos.x + bra >= p2pos.x - psize.x / 2&& m_ball.getBasicDirect().x == 1) // nếu xét x đã chạm
	{
		if (ballpos.y <= p2pos.y + psize.y / 2+20 &&
			ballpos.y >= p2pos.y - psize.y / 2-20)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
				&& m_ball.getBasicDirect().y == 1) // trường hợp người chơi đang cho thanh đi lên => bóng cũng đi lên
			{
				m_ball.ReverseBasicDirect();
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
					&& m_ball.getBasicDirect().y == -1) // trường hợp người chơi đang cho thanh đi xuống => bóng cũng đi xuống
				{
					m_ball.ReverseBasicDirect();
				}
				else
				{
					m_ball.ReverseBasicDirectX();
				}
			}
			sf::Sound sound;
			sound.setBuffer(buf);
			sound.play();
			Sleep(20);
			m_ball.setSpeed(m_ball.getSpeed() * 1.1);
		}

    }
	if (ballpos.x < p1pos.x +psize.x/2 )
	{
		sf::Sound sound;
		sound.setBuffer(scorebuf);
		sound.play();
		Sleep(1000);
		point2++;
		Reset(); 
	}
	if (ballpos.x > p2pos.x -psize.x/2)
	{
		sf::Sound sound;
		sound.setBuffer(scorebuf);
		sound.play();
		Sleep(1000);
		point1++; 
		Reset(); 
	}

}

int TheGame::CheckWinnerAndEndGame()
{
	if (point1 == 3)
	{
		m_ball.setSpeed(0.0f);  
		return 1;
	}
	if (point2 == 3)
	{
		m_ball.setSpeed(0.0f);
		return 2;
	}
	return 0;
}
void TheGame::PlayMainMusic()
{
	mainsound.setBuffer(mainbuf);
	mainsound.play();
}

string TheGame::toString(int a)
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
