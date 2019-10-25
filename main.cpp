#include <SFML/Graphics.hpp>
#include<stdio.h>
#include <iostream>
#include "TheGame.h"
#include "Menu.h"
#include"VsBotMode.h"

int main()
{

	Menu m;
	mainmenu:
	int choose = m.Ve();
	if (choose == 0)
	{
		twoplayer:
		TheGame g;
		while (!g.getWindow()->IsDone())
		{
			g.Input();
			g.Update();
			g.Render();
			int kq = g.CheckWinnerAndEndGame();
			if (kq != 0)
			{
				if (m.EndGame_2PL(kq) == 1)
				{
					goto twoplayer;
				}
				else
				{
					goto mainmenu;
				}
			}
		}
	}
	else if (choose == 1)
	{
		oneplayer:
		VsBotMode g;
		while (!g.getWindow()->IsDone())
		{
			g.Input();
			g.Update();
			g.Render();
			int kq = g.CheckWinnerAndEndGame();
			if (kq != 0)
			{
				if (m.EndGame_1PL(kq) == 1)
				{
					goto oneplayer;
				}
				else
				{
					goto mainmenu;
				}
			}
		}
	}


	return 0;
}