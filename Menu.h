#pragma once

#include <SDL.h>
#include "Color.h"

class Menu
{
public:
	Menu(int x, int y, int w, int h, Color c, Menu *parent);
	~Menu();

	void render(SDL_Renderer *ren); //Rendering function

private:
	Color color; //Stores Menu Color
	Menu *p; //Stores the parent of this menu

	SDL_Rect pos; //Stores the position of the menu
};

