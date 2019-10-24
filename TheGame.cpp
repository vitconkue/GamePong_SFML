#include "TheGame.h"

TheGame::TheGame() : m_GameScreen(), m_ball(),player1(), player2()
{
	sf::Vector2f wsize = m_GameScreen.GetWindowSize(); 
	m_ball.setPosition(wsize.x / 2,wsize.y / 2);
	player1.setPosition( 20+player1.getSize().x / 2, wsize.y / 2); 
	player2.setFillColor(sf::Color::Red);
	player2.setPosition(wsize.x - 20 - player2.getSize().x / 2, wsize.y / 2);
	point1 = point2 = 0; 
}



void TheGame::Reset()
{
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();
	m_ball.setPosition(wsize.x / 2, wsize.y / 2);
	player1.setPosition(20 + player1.getSize().x / 2, wsize.y / 2);
	player2.setPosition(wsize.x - 20 - player2.getSize().x / 2, wsize.y / 2);
	m_ball.setSpeed(5.0f);
}

void TheGame::ResetAll()
{
	sf::Vector2f wsize = m_GameScreen.GetWindowSize();
	m_ball.setPosition(wsize.x / 2, wsize.y / 2);
	player1.setPosition(20 + player1.getSize().x / 2, wsize.y / 2);
	player2.setPosition(wsize.x - 20 - player2.getSize().x / 2, wsize.y / 2);
	m_ball.setSpeed(0.0f);
	point1 = 0;  
	point2 = 0; 
}

ManHinhChoi* TheGame::getWindow()
{
	return &m_GameScreen;
}
void TheGame::Input()
{
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
}
void TheGame::Update()
{
	m_GameScreen.Update(); 
	checkBallCollusionWithPaddleAndLeftRightWall(); 
	CheckWinnerAndEndGame();
	m_ball.MoveBall(&m_GameScreen);
	//std::cout << "(" << m_ball.getBasicDirect().x << ";" << m_ball.getBasicDirect().x << ")" << std::endl;

}
void TheGame::Render()
{
	m_GameScreen.StartDrawing(); 
	m_GameScreen.Display(m_ball); 
	m_GameScreen.Display(player1);
	m_GameScreen.Display(player2);
	m_GameScreen.InLenManHinh(); 
}

void TheGame::checkBallCollusionWithPaddleAndLeftRightWall()
{
	sf::Event ev; 
	sf::Vector2f ballpos = m_ball.getPosition(); 
	sf::Vector2f p1pos = player1.getPosition(); 
	sf::Vector2f p2pos = player2.getPosition(); 
	sf::Vector2f psize = player1.getSize();
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
		}
    }
	if (ballpos.x < p1pos.x +psize.x/2 )
	{
		point2++;
		Reset(); 
	}
	if (ballpos.x > p2pos.x -psize.x/2)
	{
		point1++; 
		Reset(); 
	}

}

bool TheGame::CheckWinnerAndEndGame()
{
	if (point1 == 3)
	{
		//std::cout << "Player 1 wins" << std::endl;
		m_ball.setSpeed(0.0f);  
		return true; 
	}
	if (point2 == 3)
	{
		//std::cout << "Player 2 wins" << std::endl;
		m_ball.setSpeed(0.0f);
		return true; 
	}
	return false; 
}
