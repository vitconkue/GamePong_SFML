#include <SFML/Graphics.hpp>
#include <iostream>
#include "TheGame.h"
#include "Menu.h"

int main()
{

	Menu m;
	if (m.Ve() == 0)
	{
		TheGame g;
		while (!g.getWindow()->IsDone())
		{
			g.Input();
			g.Update();
			g.Render();
		}


	}


	return 0;
}