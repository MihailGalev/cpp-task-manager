#include "taskManager.h"
#include <iostream>

std::size_t TaskManager::getTaskCount() const
{
	return m_tasks.size();
}

void TaskManager::addTask(int id, const std::string& title,
	const std::string& description)
{
	Task newTask(id, title, description);
	m_tasks.push_back(newTask);
}

void TaskManager::viewTasks() const
{
	if (m_tasks.empty()) //Check if the vector is empty, so no redundant actions are done
	{
		std::cout << "There are no tasks available!" << '\n';
	}
	else
	{
		for (const auto& task : m_tasks) //Loop through the vector to retreive each task
		{
			std::cout << "==============LIST==============" << '\n';
			std::cout << "ID: " << task.getId() << '\n';
			std::cout << "Title: " << task.getTitle() << '\n';
			std::cout << "Description: " << task.getDescription() << '\n';
			if (task.isCompleted())
			{
				std::cout << "Status: Completed" << '\n';
			}
			else
			{
				std::cout << "Status: Incomplete" << '\n';
			}
			std::cout << "==============LIST==============" << '\n';
		}
	}
}

bool TaskManager::markTaskCompleted(int t_id)
{
	bool found{ false };
	for (auto& task : m_tasks)
	{
		if (t_id == task.getId()) //Check to see if the ID that was given is a match
		{
			if (!task.isCompleted()) //Check if the task is not completed
			{
				task.markCompleted();
			}
			return true;
		}
	}
	return false;
}