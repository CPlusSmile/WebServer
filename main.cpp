#include "GUI.h"

#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
	GUI g;
	g.addMenu(0, 0, 100, 100);
	std::thread mainThread = g.createGUI(1000, 600, "Server V1");
	g.addMenu(100, 100, 100, 100);

	std::string exitStr;
	std::cout << "Press any key to exit..";
	std::getline(std::cin, exitStr);
	if(mainThread.joinable()) { mainThread.join(); }
	

	return 0;
}