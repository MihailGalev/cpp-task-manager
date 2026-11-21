#include "taskManipulation.h"
#include "taskManager.h"
#include "taskMenu.h"
#include "taskMenuVisualization.h"
#include <iostream>

void addTask(TaskManager& manager)
{
	while (true)
	{
		int id{};
		std::cout << "Enter an ID: ";
		std::cin >> id;
		if (checkInvalidInput() || id <= 0)
		{
			std::cout << "Invalid ID. ID can be only positive integers." << '\n';
		}
		else if (manager.taskExists(id))
		{
			std::cout << "A task with this ID already exists! Try again!" << '\n';
		}
		else
		{
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
				break;
			}
			else
			{
				std::cout << "Task wasn't added. Try again!" << '\n';
			}
		}
	}
}

void deleteTask(TaskManager& manager)
{
	while (true)
	{
		int id{};
		std::cout << "Enter the ID of the task you want to be deleted: ";
		std::cin >> id;
		if (checkInvalidInput() || id <= 0)
		{
			std::cout << "Invalid ID. ID can be only positive integers." << '\n';
		}
		else if (!manager.taskExists(id))
		{
			std::cout << "Task not found! Try again!" << '\n';
		}
		else
		{
			if (manager.deleteTask(id))
			{
				std::cout << "The task has been deleted successfully!" << '\n';
				break;
			}
			else
			{
				std::cout << "Task wasn't deleted. Try again!" << '\n';
			}
		}
	}
}

void markTaskComplete(TaskManager& manager)
{
	while (true)
	{
		int id{};
		std::cout << "Enter the ID of the task you want to be marked as complete: ";
		std::cin >> id;
		if (checkInvalidInput() || id <= 0)
		{
			std::cout << "Invalid ID. ID can be only positive integers." << '\n';
		}
		else if (!manager.taskExists(id))
		{
			std::cout << "Task not found! Try again!" << '\n';
		}
		else if (manager.isTaskCompleted(id))
		{
			std::cout << "The task has already been completed!" << '\n';
			break;
		}
		else
		{
			if (manager.markTaskCompleted(id))
			{
				std::cout << "The task has been marked as complete successfully!" << '\n';
				break;
			}
			else
			{
				std::cout << "Task wasn't marked as complete. Try again!" << '\n';
			}
		}
	}
}

void changeTaskInfo(TaskManager& manager)
{
	while (true)
	{
		std::cout << "Enter the ID of the task you'd like to manipulate: ";
		int id{};
		std::cin >> id;
		if (checkInvalidInput() || id <= 0)
		{
			std::cout << "Invalid ID. ID can be only positive integers." << '\n';
		}
		else if (!manager.taskExists(id))
		{
			std::cout << "Task not found! Try again!" << '\n';
		}
		else
		{
			int mode{ 1 }; // mode 1 means details of the task will be changed
			while (true) //task manipulation menu begins
			{
				taskDetailManipulationMenuVisualisation();
				int option{};
				std::cin >> option;
				if (checkInvalidInput() || !isValidMenuOption(option, mode)) // This line checks the validity of the user input. If the input is invalid, an error message is displayed and the user is prompted to try again.
				{
					std::cout << "The option you've chosen is not valid. Please try again!" << '\n';
					continue;
				}
				switch (option)
				{
				case 1: //change of the title 
				{
					std::cout << "Enter a new title for the task: ";
					std::string new_title;
					std::cin >> new_title;
					if (manager.changeTaskTitle(id, new_title))
					{
						std::cout << "The task has a new title: " << new_title<< '\n';
					}
					else
					{
						std::cout << "The title was not changed!" << '\n';
					}
					break;
				}
				case 2: //change of the description
				{
					std::cout << "Enter a new description of the task: ";
					std::string new_description;
					std::cin >> new_description;
					if (manager.changeTaskDescription(id, new_description))
					{
						std::cout << "The task has a new description: " << new_description << '\n';
					}
					else
					{
						std::cout << "The description was not changed!" << '\n';
					}
					break;
				}
				case 3: //exit of this menu and go back to the main menu
					return;
				}
			}
		}
	}
}