#include <iostream>
#include <limits>
#include <string>
#include "taskMenu.h"
#include "taskMenuVisualization.h"
bool checkInvalidInput(int option);

void taskMenu(TaskManager& manager)
{
	while (true) // This while loop will keep the task menu running until the user chooses to exit the program.
	{
		taskMenuVisualization(); //The task menu displays the options for the user to choose from.

		int option{};
		std::cin >> option;
		if (checkInvalidInput(option)) // This line checks the validity of the user input. If the input is invalid, an error message is displayed and the user is prompted to try again.
		{
			std::cout << "The option you've chosen is not valid. Please try again!" << '\n';
			continue;
		}
		switch (option)
		{
		case 1: //Add a task
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
		case 2: // View a list of all tasks
			manager.viewTasks();
			break;
		case 3: //Delete a task
		{
			int id{};
			std::cout << "Enter the ID of the task you want to be deleted: ";
			std::cin >> id;

			manager.deleteTask(id);
			break;
		}
		case 4: //Mark a task as complete
		{
			int id{};
			std::cout << "Enter the ID of the task you want to be marked as complete: ";
			std::cin >> id;

			manager.markTaskCompleted(id);
			break;
		}
		case 5: //View remaining task count
			std::cout << "Your remaining task count is: " << manager.getTaskCount() << '\n';
			break;
		case 6:
			std::cout << "You've chosen to exit the program. Goodbye!" << '\n';
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
	else if (t_option < 1 || t_option > 6)
	{
		return true; // Invalid input
	}
	else
	{
		return false; // Valid input
	}
}
