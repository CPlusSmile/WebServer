#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <thread>
#include <SDL_image.h>

#include "Menu.h"

enum class GUI_AssignTypes {
	GUI_IMAGES,
	GUI_MENU
};

class GUI
{
public:
	GUI();
	~GUI();

	struct GUI_Color {
		int r;
		int g;
		int b;
	};

	//GUI Starting Function
	std::thread createGUI(int w, int h, std::string title);

	/* GUI Menu Functions */
	void registerMenu(Menu *m); //Registeres the menu with the GUI
private:
	/* SDL Window Essentials */
	SDL_Window *win;
	SDL_Renderer *ren;

	//Menu Array
	std::vector<Menu*> menus;

	/* GUI Core Functions */
	void createWindow(int w, int h, std::string title); //Creates the window
	void render(); //Renderes all of the components
	void mainLoop(); //Updates the window
	void handleInput(); //Handles input to the window

	//GUI State
	bool isQuit;
};

