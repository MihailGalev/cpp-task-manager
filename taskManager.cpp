#include "TaskManager.h"
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
			std::cout << task.getId() << '\n';
			std::cout << task.getTitle() << '\n';
			std::cout << task.getDescription() << '\n';
			if (task.isCompleted())
			{
				std::cout << "Status: Completed" << '\n';
			}
			else
			{
				std::cout << "Status: Incomplete" << '\n';
			}
		}
	}
}