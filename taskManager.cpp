#include "taskManager.h"
#include <iostream>
#include <algorithm>

std::size_t TaskManager::getTaskCount() const
{
	return m_tasks.size();
}

std::size_t TaskManager::getCompletedTaskCount() const
{
	return std::count_if(
		m_tasks.begin(),
		m_tasks.end(),
		[](const Task& task) 
		{
		return task.isCompleted();
		}
	);
}

std::size_t TaskManager::getIncompleteTaskCount() const
{
	return std::count_if(
		m_tasks.begin(), 
		m_tasks.end(), 
		[](const Task& task) {
		return !task.isCompleted();
	}
	);
}

bool TaskManager::addTask(int id, const std::string& title,
	const std::string& description)
{

	auto it = std::find_if(
		m_tasks.begin(), 
		m_tasks.end(),
		[id](const Task& task)
		{
		return task.getId() == id;
		}
	);
	if (it != m_tasks.end())
	{
		return false;
	}
	Task newTask(id, title, description);
	m_tasks.push_back(newTask);
	return true;
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
				std::cout << "Status: Complete" << '\n';
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

bool TaskManager::deleteTask(int t_id)
{
	auto it = m_tasks.begin(); //Points to the first task
	while(it != m_tasks.end())
	{
		if (it->getId() == t_id) //Access the ID of the object the iterator "it" is pointing to and compare it.
		{
			m_tasks.erase(it);
			return true;
		}
		it++;
	}
	return false;
}