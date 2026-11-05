#include <iostream>
#include "taskMenu.h"

void taskMenu()
{
	//The task menu displays the options for the user to choose from. It will be called in main.cpp
	std::cout << "================================" << '\n';
	std::cout << "          TASK MANAGER          " << '\n';
	std::cout << "================================" << '\n';
	std::cout << '\n';
	std::cout << "Welcome to your Task Manager" << '\n';
	std::cout << '\n';
	std::cout << "1. Add Task" << '\n';
	std::cout << "2. View Task" << '\n';
	std::cout << "3. Exit" << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "Select an option: ";
	//The user will input their option here. The input will be stored in the variable "option"
	int option{};
	std::cin >> option; 
	if (option < 1 || option > 3)
	{
		std::cout << "The option you've chosen is not valid. Please try again!"; //This line is for testing purposes. It will be removed in the final version of the program.
	}
	else
	{
		std::cout << "You've chosen option " << option << '.\n'; //This line is for testing purposes. It will be removed in the final version of the program.
	}
}
