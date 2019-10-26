#include "VsBotMode.h"

VsBotMode::VsBotMode() : m_GameScreen(), m_ball(), bot(), player(), tex(), buf(), scorebuf(), winbuf()
{
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();
	m_ball.setPosition(wsize.x / 2, wsize.y / 2);
	bot.setPosition(20 + bot.getSize().x / 2, wsize.y / 2);
	player.setFillColor(sf::Color::Red);
	player.setPosition(wsize.x - 20 - player.getSize().x / 2, wsize.y / 2);
	point1 = point2 = 0;
	if (!tex.loadFromFile("InGameBackground.png"))
	{
		cout << "Load fails";
	}
	if (!buf.loadFromFile("MenuSound1.ogg"))
	{
		cout << "Load fails";
	}
	if (!mainbuf.loadFromFile("MenuMusic.ogg"))
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
	PlayMainMusic();
}

void VsBotMode::PlayMainMusic()
{
	sf::Sound s;
	s.setBuffer(mainbuf);
	s.play();
}


void VsBotMode::Reset()
{
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();
	m_ball.setPosition(wsize.x / 2, wsize.y / 2);
	bot.setPosition(20 + bot.getSize().x / 2, wsize.y / 2);
	player.setPosition(wsize.x - 20 - player.getSize().x / 2, wsize.y / 2);
	m_ball.setSpeed(3.0f);

}

void VsBotMode::ResetAll()
{
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();
	m_ball.setPosition(wsize.x / 2, wsize.y / 2);
	bot.setPosition(20 + bot.getSize().x / 2, wsize.y / 2);
	player.setPosition(wsize.x - 20 - player.getSize().x / 2, wsize.y / 2);
	m_ball.setSpeed(0.0f);
	point1 = 0;
	point2 = 0;
}

ManHinhChoi* VsBotMode::getWindow()
{
	return &m_GameScreen;
}
void VsBotMode::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.MoveUp(&m_GameScreen);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.MoveDown(&m_GameScreen);
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player1.MoveUp(&m_GameScreen);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player1.MoveDown(&m_GameScreen);
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Reset();
	}
}
void VsBotMode::Update()
{
	m_GameScreen.Update();
	checkBallCollusionWithPaddleAndLeftRightWall();
	m_ball.MoveBall(&m_GameScreen);
	BotMove();

	//std::cout << "(" << m_ball.getBasicDirect().x << ";" << m_ball.getBasicDirect().x << ")" << std::endl;

}
void VsBotMode::Render()
{
	m_GameScreen.StartDrawing();
	sf::Sprite sprite(tex);
	m_GameScreen.Display(sprite);
	m_GameScreen.Display(m_ball);
	m_GameScreen.Display(bot);
	m_GameScreen.Display(player);
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
	if (point1 == 0)
	{
		p1.setString("0");
	}
	if (point1 == 1)
	{
		p1.setString("1");
	}
	if (point1 == 2)
	{
		p1.setString("2");
	}
	if (point2 == 0)
	{
		p2.setString("0");
	}
	if (point2 == 1)
	{
		p2.setString("1");
	}
	if (point2 == 2)
	{
		p2.setString("2");
	}
	if (point1 == 3)
	{
		p1.setString("3");
		winner.setFont(font);
		winner.setFillColor(sf::Color::Blue);
		winner.setOutlineThickness(3);
		winner.setOutlineColor(sf::Color::White);
		winner.setPosition(400, 200);
		winner.setCharacterSize(75);
		winner.setString("BOT WIN");
		m_GameScreen.Display(winner);
	}
	if (point2 == 3)
	{
		p2.setString("3");
		winner.setFont(font);
		winner.setFillColor(sf::Color::Red);
		winner.setOutlineThickness(3);
		winner.setOutlineColor(sf::Color::White);
		winner.setPosition(400, 200);
		winner.setCharacterSize(75);
		winner.setString("YOU WIN");
		m_GameScreen.Display(winner);
	}
	m_GameScreen.Display(p1);
	m_GameScreen.Display(p2);
	m_GameScreen.InLenManHinh();
	if (point1 == 3 || point2 == 3)
	{
		sf::Sound s;
		s.setBuffer(winbuf);
		s.play();
		Sleep(5000);
	}
}

void VsBotMode::checkBallCollusionWithPaddleAndLeftRightWall()
{
	sf::Event ev;
	sf::Vector2f ballpos = m_ball.getPosition();
	sf::Vector2f p1pos = bot.getPosition();
	sf::Vector2f p2pos = player.getPosition();
	sf::Vector2f psize = bot.getSize();
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();
	float bra = m_ball.getRadius();
	
	// chạm người chơi trái
	if (ballpos.x - bra <= p1pos.x + psize.x / 2)
	{
		if (ballpos.y <= p1pos.y + psize.y / 2 &&
			ballpos.y >= p1pos.y - psize.y / 2)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
				&& m_ball.getBasicDirect().y == 1)
			{
				m_ball.ReverseBasicDirect();
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
					&& m_ball.getBasicDirect().y == -1)
				{
					m_ball.ReverseBasicDirect();
				}
				else
				{
					m_ball.ReverseBasicDirectX();
				}
			}
			m_ball.setSpeed(m_ball.getSpeed() * 1.1);
			sf::Sound sound;
			sound.setBuffer(buf);
			sound.play();
			Sleep(20);
		}

	}
	// chạm người chơi phải
	if (ballpos.x + bra >= p2pos.x - psize.x / 2)
	{
		if (ballpos.y <= p2pos.y + psize.y / 2 &&
			ballpos.y >= p2pos.y - psize.y / 2)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
				&& m_ball.getBasicDirect().y == 1)
			{
				m_ball.ReverseBasicDirect();
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
					&& m_ball.getBasicDirect().y == -1)
				{
					m_ball.ReverseBasicDirect();
				}
				else
				{
					m_ball.ReverseBasicDirectX();
				}
			}
			m_ball.setSpeed(m_ball.getSpeed() * 1.1);
			sf::Sound sound;
			sound.setBuffer(buf);
			sound.play();
			Sleep(20);
		}

	}
	if (ballpos.x < p1pos.x + psize.x / 2)
	{
		point2++;
		sf::Sound sound;
		sound.setBuffer(scorebuf);
		sound.play();
		Sleep(1000);
		Reset();
	}
	if (ballpos.x > p2pos.x - psize.x / 2)
	{
		sf::Sound sound;
		sound.setBuffer(scorebuf);
		sound.play();
		Sleep(1000);
		point1++;
		Reset();
	}

}

void VsBotMode::BotMove()
{
	//Dự đoán đường đi tiếp theo cho Bot.
	level = 3;
	sf::Vector2f ballpos = m_ball.getPosition();
	sf::Vector2f newbotposition;
	sf::Vector2f botpos = bot.getPosition();
	newbotposition.x = bot.getPosition().x;
	//Bot lv 2
	if (ballpos.y > 90 && ballpos.y < 510)
	{
		if (botpos.y < ballpos.y)
		{
			newbotposition.y = botpos.y + 5;
			bot.setPosition(newbotposition);
		}
		else if (botpos.y > ballpos.y)
		{
			newbotposition.y = botpos.y - 5;
			bot.setPosition(newbotposition);
		}
	}
	////Bot level infinity
	//if (ballpos.y > 90 && ballpos.y < 510)
	//{
	//	newbotposition.y = ballpos.y;
	//	bot.setPosition(newbotposition);
	//}

}

int VsBotMode::CheckWinnerAndEndGame()
{
	if (point1 == 3)
	{
		//std::cout << "Player 1 wins" << std::endl;
		m_ball.setSpeed(0.0f);
		return 1;
	}
	if (point2 == 3)
	{
		//std::cout << "Player 2 wins" << std::endl;
		m_ball.setSpeed(0.0f);
		return 2;
	}
	return 0;
}
