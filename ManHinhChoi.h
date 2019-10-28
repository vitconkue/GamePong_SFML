#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
class ManHinhChoi
{
private:
	//thành phần màn hình	
	sf::RenderWindow m_windows;
	// kích cỡ màn hình ( là 1 vector có chiều rộng x, chiều dài y, 2f: 2 chiều float)
	sf::Vector2f m_WindowSize;
	// tiêu đề màn hình chơi
	std::string m_WindowsTitle;
	// biến bool kiểm tra game đã xong/chưa xong
	bool m_isDone;
	// kiểm tra full màn hình/  không full màn hình
	bool m_isFullWindows;
public:
	// constructor trong màn hình
	ManHinhChoi();
	// destructor cho màn hình
	~ManHinhChoi();
	// cài đặt màn hình chơi, truyền vào tiêu đề và kích cỡ
	void Setup(std::string title, sf::Vector2f& Wsize);
	// getter của biến m_isDome
	bool IsDone(){ return m_isDone; }
	// tạo backgroud rỗng
    void StartDrawing(); 
	// vẽ
	void Display(sf::Drawable& object); 
	// in lên (display)
	void InLenManHinh(); 
	void createScreen(); // có xét xem có phải là full màn hình không 
	// huỷ màn hình, dùng phương thức close()
	void CloseWindow(); 
	// lấy kích cỡ màn hình(vector)
	sf::Vector2f GetWindowSize(); 
	// chuyển đổi full màn hình thành không full hoặc ngược lại, xoá màn hình đi rồi vẽ lại.
	void ToggleFullScreen(); 
	void Update(); // vòng while để xử lí khi nhấn nút x (thoát) hoặc nhấn nút F6 để chuyển đổi giữa full màn hình và không full màn hình
};


	

