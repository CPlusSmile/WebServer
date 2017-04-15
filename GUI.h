#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <thread>
#include <SDL_image.h>

class GUI
{
public:
	GUI();
	~GUI();
	std::thread createGUI(int w, int h, std::string title);
	int addMenu(int x, int y, int w, int h);
	int loadImage(int winX, int winY, int w, int h, std::string src);
private:
	//GUI Type Structures
	struct GUI_IMG {
		SDL_Rect pos;
		std::string src;
		SDL_Texture *tex;
		int index;
	};
	struct GUI_MENU {
		SDL_Rect pos;
		int index;
	};
	//GUI Essentials
	std::vector<GUI_IMG> loadedImages;
	std::vector<GUI_MENU> menus;

	//SDL Window Essentials
	SDL_Window *win;
	SDL_Renderer *ren;

	//GUI Core Functions
	void createWindow(int w, int h, std::string title);
	void renderMenus();
	void mainLoop();
	void handleInput();
	void createTextures();

	//GUI State
	bool isQuit;
};

