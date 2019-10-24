#include <SFML/Graphics.hpp>
#include <iostream>
#include "TheGame.h"

int main()
{
	TheGame g; 
	while (!g.getWindow()->IsDone())
	{
		g.Input(); 
		g.Update(); 
		g.Render();
	}
}