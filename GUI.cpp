#include "GUI.h"

#include <iostream>

GUI::GUI() :
	isQuit(false)
{
	SDL_Init(SDL_INIT_EVERYTHING);
}

GUI::~GUI()
{
	SDL_Quit();
}

std::thread GUI::createGUI(int w, int h, std::string title) {
	
	std::thread mainThread(&GUI::createWindow, this, w, h, title);

	return mainThread;
}

void GUI::createWindow(int w, int h, std::string title) {
	win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	mainLoop();
}

void GUI::registerMenu(Menu *m) {
	menus.push_back(m);
}

void GUI::mainLoop() {
	while (!isQuit) {
		handleInput();
		render();
	}
}

void GUI::handleInput() {
	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		switch (e.type) {
			case SDL_QUIT: {
				SDL_DestroyRenderer(ren);
				SDL_DestroyWindow(win);
				SDL_Quit();
				isQuit = true;
				break;
			}
		}
	}
}

void GUI::render() {
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderClear(ren);

	SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
	for (int i = 0; i < (int)menus.size(); i++) {
		menus[i]->render(ren);
	}

	SDL_RenderPresent(ren);
}