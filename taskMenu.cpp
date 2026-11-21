#include <iostream>
#include <limits>
#include <string>
#include "taskMenu.h"
#include "taskMenuVisualization.h"
#include "taskManipulation.h"

void taskMenu(TaskManager& manager)
{
	while (true) // This while loop will keep the task menu running until the user chooses to exit the program.
	{
		taskMenuVisualization(); //The task menu displays the options for the user to choose from.
		int mode{ 0 }; //mode 0 means it's not in change of task details mode
		int option{};
		std::cin >> option;
		if (checkInvalidInput() || !isValidMenuOption(option, mode)) // This line checks the validity of the user input. If the input is invalid, an error message is displayed and the user is prompted to try again.
		{
			std::cout << "The option you've chosen is not valid. Please try again!" << '\n';
			continue;
		}
		switch (option)
		{
		case 1: //Add a task
			addTask(manager);
			break;
		case 2: // View a list of all tasks
			manager.viewTasks();
			break;
		case 3: //Delete a task
			deleteTask(manager);
			break;
		case 4: //Mark a task as complete
			markTaskComplete(manager);
			break;
		case 5: //View task count, completed tasks count and incomplete tasks count
			std::cout << "Total count of entered tasks: " << manager.getTaskCount() << '\n';
			std::cout << "Total count of completed tasks: " << manager.getCompletedTaskCount() << '\n';
			std::cout << "Total count of incomplete tasks: " << manager.getIncompleteTaskCount() << '\n';
			break;
		case 6: // Task detail manipulation
			changeTaskInfo(manager);
			break;
		case 7: //Exit the program
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

bool isValidMenuOption(int t_option, int mode)
{
	if (mode == 0)
	{
		return t_option >= 1 && t_option <= 7;//main menu options limit
	}
	else
	{
		return t_option >= 1 && t_option <= 3;//task manipulation menu limit
	}
	
}
