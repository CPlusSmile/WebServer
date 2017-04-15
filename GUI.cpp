#include "GUI.h"

#include <iostream>

GUI::GUI() :
	isQuit(false)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
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

	createTextures();
	mainLoop();
}

int GUI::addMenu(int x, int y, int w, int h) {
	menus.push_back(GUI_MENU{ SDL_Rect{ (int)x, (int)y, w, h }, (int)menus.size() });
	return menus.size() - 1;
}

int GUI::loadImage(int winX, int winY, int w, int h, std::string src) {
	loadedImages.push_back(GUI_IMG{ SDL_Rect{ (int)winX, (int)winY, w, h }, src, NULL, (int)loadedImages.size() });
	return loadedImages.size() - 1;
}

void GUI::mainLoop() {
	while (!isQuit) {
		handleInput();
		renderMenus();
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

void GUI::renderMenus() {
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderClear(ren);

	for (int i = 0; i < (int)loadedImages.size(); i++) {
		SDL_RenderCopy(ren, loadedImages[i].tex, NULL, &loadedImages[i].pos);
	}

	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	for (int i = 0; i < (int)menus.size(); i++) {
		SDL_RenderFillRect(ren, &menus[i].pos);
	}

	SDL_RenderPresent(ren);
}

void GUI::createTextures() {
	for (int i = 0; i < loadedImages.size(); i++) {
		loadedImages[i].tex = IMG_LoadTexture(ren, loadedImages[i].src.c_str());
	}
}