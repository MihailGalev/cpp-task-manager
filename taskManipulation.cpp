#include "taskManipulation.h"
#include "taskManager.h"
#include "taskMenu.h"
#include "taskMenuVisualization.h"
#include "inputUtils.h"
#include <iostream>

namespace
{
	void taskDetailManipulation(TaskManager& manager, int id)
	{
		int mode{ 1 }; // mode 1 means details of the task will be changed
		while (true) //task manipulation menu begins
		{
			taskDetailManipulationMenuVisualisation();
			int option{};
			std::string input;
			if (!std::getline(std::cin, input))
			{
				return;
			}
			if (!tryParseInteger(input, option) || !isValidMenuOption(option, mode)) // This line checks the validity of the user input. If the input is invalid, an error message is displayed and the user is prompted to try again.
			{
				std::cout << "The option you've chosen is not valid. Please try again!" << '\n';
				continue;
			}
			switch (option)
			{
			case 1: //change of the title 
			{
				std::cout << "Enter a new title for the task: ";
				std::string t_title;
				if (!std::getline(std::cin, t_title))
				{
					return;
				}
				if (manager.changeTaskTitle(id, t_title))
				{
					std::cout << "The task has a new title: " << t_title << '\n';
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
				std::string t_description;
				if (!std::getline(std::cin, t_description))
				{
					return;
				}
				if (manager.changeTaskDescription(id, t_description))
				{
					std::cout << "The task has a new description: " << t_description << '\n';
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

void addTask(TaskManager& manager)
{
	while (true)
	{
		int id{};
		std::string input;
		std::cout << "Enter an ID: ";
		if (!std::getline(std::cin, input))
		{
			return;
		}
		if (!tryParseInteger(input, id) || id <= 0)
		{
			std::cout << "Invalid ID. ID can be only positive integers." << '\n';
			continue;
		}
		if (manager.taskExists(id))
		{
			std::cout << "A task with this ID already exists! Try again!" << '\n';
			continue;
		}

		std::string title;
		std::cout << "Enter a title of the Task: ";
		if (!std::getline(std::cin, title))
		{
			return;
		}

		std::string description;
		std::cout << "Enter a brief description of the Task: ";
		if (!std::getline(std::cin, description))
		{
			return;
		}

		if (manager.addTask(id, title, description))
		{
			std::cout << "Task added successfully!" << '\n';
			break;
		}

		std::cout << "Task wasn't added. Try again!" << '\n';
	}
}

void deleteTask(TaskManager& manager)
{
	while (true)
	{
		int id{};
		std::string input;
		std::cout << "Enter the ID of the task you want to be deleted: ";
		if (!std::getline(std::cin, input))
		{
			return;
		}
		if (!tryParseInteger(input, id) || id <= 0)
		{
			std::cout << "Invalid ID. ID can be only positive integers." << '\n';
			continue;
		}
		if (manager.deleteTask(id))
		{
			std::cout << "The task has been deleted successfully!" << '\n';
			return;
		}

		std::cout << "Task ID not found!" << '\n';
	}
}

void markTaskComplete(TaskManager& manager)
{
	while (true)
	{
		int id{};
		std::string input;
		std::cout << "Enter the ID of the task you want to be marked as complete: ";
		if (!std::getline(std::cin, input))
		{
			return;
		}
		if (!tryParseInteger(input, id) || id <= 0)
		{
			std::cout << "Invalid ID. ID can be only positive integers." << '\n';
			continue;
		}
		CompletionResult result = manager.markTaskCompleted(id);
		switch (result)
		{
		case CompletionResult::Success:
			std::cout << "The task has been marked as complete successfully!" << '\n';
			return;
		case CompletionResult::AlreadyCompleted:
			std::cout << "The task is already marked as complete!" << '\n';
			return;
		case CompletionResult::NotFound:
			std::cout << "Task ID not found!" << '\n';
			break;
		}
	}
}

void changeTaskInfo(TaskManager& manager)
{
	while (true)
	{
		int id{};
		std::string input;
		std::cout << "Enter the ID of the task you'd like to manipulate: ";
		if (!std::getline(std::cin, input))
		{
			return;
		}
		if (!tryParseInteger(input, id) || id <= 0)
		{
			std::cout << "Invalid ID. ID can be only positive integers." << '\n';
			continue;
		}
		if (!manager.taskExists(id))
		{
			std::cout << "Task not found! Try again!" << '\n';
			continue;
		}

		taskDetailManipulation(manager, id);
		return;
	}
}

