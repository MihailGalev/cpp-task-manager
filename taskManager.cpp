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
	auto it = findTaskById(id);
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
	auto it = findTaskById(t_id);
	if (it != m_tasks.end())
	{
		if (!(it->isCompleted()))
		{
			it->markCompleted();
		}
		return true;
	}
	
	return false;
}

bool TaskManager::deleteTask(int t_id)
{
	auto it = findTaskById(t_id);
	if (it != m_tasks.end())
	{
		m_tasks.erase(it);
		return true;
	}

	return false;
}

std::vector<Task>::iterator TaskManager::findTaskById(int t_id)
{
	return std::find_if(
		m_tasks.begin(), 
		m_tasks.end(), 
		[t_id](const Task& task) {
		return task.getId() == t_id;
	}
	);
}

bool TaskManager::changeTaskTitle(int t_id, const std::string& t_title)
{
	auto it = findTaskById(t_id);
	if (it != m_tasks.end())
	{
		it->setTitle(t_title);
		return true;
	}

	return false;
}