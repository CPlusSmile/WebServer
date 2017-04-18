#include "Menu.h"
#include<iostream>


Menu::Menu(int posX, int posY, int w, int h, Color c, Menu *parent) :
	color(c),
	p(parent)
{
	if (parent != 0) {
		pos = { parent->pos.x + posX, parent->pos.y + posY, w, h };
	}
	else {
		pos = { posX, posY, w, h };
	}
}

Menu::~Menu(){}

void Menu::render(SDL_Renderer *ren) {
	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.alpha);
	SDL_RenderFillRect(ren, &pos);
}
