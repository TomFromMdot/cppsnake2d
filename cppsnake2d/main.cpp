#include <iostream>

#include "Window.h"

int main()
{
	Window window("Test", 800, 600);
	window.windowStart();


	std::cout << "Hello World!\n";
	return 0;
}