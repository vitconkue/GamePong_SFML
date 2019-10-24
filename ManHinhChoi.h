#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
class ManHinhChoi
{
private:
	sf::RenderWindow m_windows;
	sf::Vector2f m_WindowSize;
	std::string m_WindowsTitle;
	bool m_isDone;
	bool m_isFullWindows;
public:
	void Setup(std::string title, sf::Vector2f &Wsize);
	ManHinhChoi();
	~ManHinhChoi(); 
	bool IsDone(){ return m_isDone; }
	void StartDrawing(); // tạo backgroud rỗng
	void Display(sf::Drawable& object); // vẽ
	void InLenManHinh(); // in lên (display)
	void createScreen(); // có xét xem có phải là full màn hình không 
	void CloseWindow(); // huỷ màn hình, dùng phương thức close()
	sf::Vector2f GetWindowSize(); 
	void ToggleFullScreen(); // chuyển đổi full màn hình thành không full hoặc ngược lại, xoá màn hình đi rồi vẽ lại. 
	void Update(); // vòng while để xử lí khi nhấn nút x (thoát) hoặc nhấn nút F6 để chuyển đổi giữa full màn hình và không full màn hình
};


	

