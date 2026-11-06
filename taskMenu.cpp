#include <iostream>
#include <limits>
#include <string>
#include "taskMenu.h"

void taskMenu(TaskManager& manager)
{
	while (true) // This while loop will keep the task menu running until the user chooses to exit the program.
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
		if (checkInvalidInput(option)) // This line checks the validity of the user input. If the input is invalid, an error message is displayed and the user is prompted to try again.
		{
			std::cout << "The option you've chosen is not valid. Please try again!" << '\n';
			continue;
		}
		switch (option)
		{
		case 1:
		{
			int id{};
			std::cout << "Enter an ID: ";
			std::cin >> id;

			std::string title;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter a title of the Task: ";
			std::getline(std::cin, title);

			std::string description;
			std::cout << "Enter a brief description of the Task: ";
			std::getline(std::cin, description);

			manager.addTask(id, title, description);
			break;
		}
		case 2:
			manager.viewTasks();
			break;
		case 3: //Exit condition for the task menu. If the user chooses option 3, the program will exit the task menu and return to main.cpp
			std::cout << "Exiting the program. Goodbye!" << '\n';
			return;
		}
	}
}

bool checkInvalidInput(int t_option)
{
	if (std::cin.fail() || std::cin.peek() != '\n')// Checks if the input is invalid or there are extra characters in the input stream. If either condition is true, the input is considered invalid.
	{
		std::cin.clear(); // Clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		return true; // Invalid input
	}
	else if (t_option < 1 || t_option > 3)
	{
		return true; // Invalid input
	}
	else
	{
		return false; // Valid input
	}
}
