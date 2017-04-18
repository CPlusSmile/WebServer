#include "GUI.h"

#include <iostream>
#include <thread>
#include "Menu.h"
#include "Color.h"

int main(int argc, char *argv[]) {
	GUI g;

	/*Initialize all of the used menus*/
	Menu m(0, 0, 1000, 600, Color(230, 230, 230, 255), NULL);
	Menu mTwo(300, 20, 400, 560, Color(255, 255, 255, 255), &m);
	Menu heading(0, 0, 400, 20, Color(130, 190, 255, 255), &mTwo);

	/*Register all of the menus to the gui*/
	g.registerMenu(&m);
	g.registerMenu(&mTwo);
	g.registerMenu(&heading);

	/*Create the window for the menus and initialize the gui*/
	std::thread mainThread = g.createGUI(1000, 600, "Server V1");

	/*Wait until the window thread has been terminated*/
	if(mainThread.joinable()) { mainThread.join(); }

	return 0;
}