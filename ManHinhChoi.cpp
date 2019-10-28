#include "ManHinhChoi.h"

// setup màn hình chơi ban đầu
void ManHinhChoi::Setup(std::string title, sf::Vector2f &Wsize)
{
	m_WindowsTitle = title; 
	m_WindowSize.x = Wsize.x; 
	m_WindowSize.y = Wsize.y;  
	m_isDone = false; 
	m_isFullWindows = false;
	createScreen(); 
}
//
ManHinhChoi::ManHinhChoi()
{
	sf::Vector2f s; 
	s.x = 1000; s.y = 600; 
	Setup("Game Pong", s); 
	m_windows.setFramerateLimit(80); // tối đa 80fps, nếu quá cao dễ bị giựt và văng
}

// huỷ dùng close()
ManHinhChoi::~ManHinhChoi()
{
	CloseWindow(); 
}

// clear toàn bộ, màn hình, đưa background về màu đen
void ManHinhChoi::StartDrawing()
{
	m_windows.clear(sf::Color::Black); 
}
// vẽ. chưa đưa lên màn hình
void ManHinhChoi::Display(sf::Drawable& object)
{
	m_windows.draw(object); 
}
// đưa lên màn hình những gì đã vẽ
void ManHinhChoi::InLenManHinh()
{
	m_windows.display(); 
}

void ManHinhChoi::createScreen()
{
	auto style = (m_isFullWindows ? sf::Style::Fullscreen : sf::Style::Default); 
	m_windows.create({ (unsigned int)m_WindowSize.x,(unsigned int)m_WindowSize.y,32 }, m_WindowsTitle, style);
}
// đóng màn hình, phương thức close có sẵn trong thư viện sfml
void ManHinhChoi::CloseWindow()
{
	m_windows.close(); 
}
// getter
sf::Vector2f ManHinhChoi::GetWindowSize()
{
	return m_WindowSize;
}
// chuyển đổi giữa 2 trạng thái full/ không full màn hình
void ManHinhChoi::ToggleFullScreen()
{
	m_isFullWindows = !m_isFullWindows; 
	CloseWindow();
	createScreen(); 
}
// nếu người dùng nháy nút thoát bằng chuột thì trò chơi đã xong
void ManHinhChoi::Update()
{
	sf::Event ev; // biến sự kiện
	while (m_windows.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed) // nháy vào nút thoát
		{
			m_isDone = true; 
		}
    }
}
