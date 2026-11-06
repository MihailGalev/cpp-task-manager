#include <iostream>
#include <limits>
#include <string>
#include "taskMenu.h"
#include "taskMenuVisualization.h"
bool checkInvalidInput();
bool isValidMenuOption(int t_option);

void taskMenu(TaskManager& manager)
{
	while (true) // This while loop will keep the task menu running until the user chooses to exit the program.
	{
		taskMenuVisualization(); //The task menu displays the options for the user to choose from.

		int option{};
		std::cin >> option;
		if (checkInvalidInput() || !isValidMenuOption(option)) // This line checks the validity of the user input. If the input is invalid, an error message is displayed and the user is prompted to try again.
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
			if (checkInvalidInput() || id <= 0)
			{
				std::cout << "Invalid ID. ID can be only positive integers." << '\n';
				break;
			}

			std::string title;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter a title of the Task: ";
			std::getline(std::cin, title);

			std::string description;
			std::cout << "Enter a brief description of the Task: ";
			std::getline(std::cin, description);

			if (manager.addTask(id, title, description))
			{
				std::cout << "Task added successfully!" << '\n';
			}
			else
			{
				std::cout << "A task with this ID already exists!" << '\n';
			}
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
			if (checkInvalidInput() || id <= 0)
			{
				std::cout << "Invalid ID. ID can be only positive integers." << '\n';
				break;
			}

			bool done{ manager.deleteTask(id) };
			if (done)
			{
				std::cout << "The task has been deleted successfully!" << '\n';
			}
			else 
			{
				std::cout << "Task not found!" << '\n';
			}
			break;
		}
		case 4: //Mark a task as complete
		{
			int id{};
			std::cout << "Enter the ID of the task you want to be marked as complete: ";
			std::cin >> id;
			if (checkInvalidInput() || id <= 0)
			{
				std::cout << "Invalid ID. ID can be only positive integers." << '\n';
				break;
			}

			bool marked{ manager.markTaskCompleted(id) };
			if (marked)
			{
				std::cout << "The task has been marked as complete successfully!" << '\n';
			}
			else
			{
				std::cout << "Task not found!" << '\n';
			}
			break;
		}
		case 5: //View remaining task count
			std::cout << "Total task count for now: " << manager.getTaskCount() << '\n';
			break;
		case 6:
			std::cout << "You've chosen to exit the program. Goodbye!" << '\n';
			return;
		}
	}
}

bool checkInvalidInput()
{
	if (std::cin.fail() || std::cin.peek() != '\n')// Checks if the input is invalid or there are extra characters in the input stream. If either condition is true, the input is considered invalid.
	{
		std::cin.clear(); // Clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		return true; // Invalid input
	}
	else
	{
		return false; // Valid input
	}
}

bool isValidMenuOption(int t_option)
{
	return t_option >= 1 && t_option <= 6;
}
