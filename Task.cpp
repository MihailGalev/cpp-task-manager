#include "Task.h"

Task::Task(int id, const std::string& title, const std::string& description) //This is the constructor for the Task class. It initializes the member variables of the class with the values passed as arguments.
		:m_id(id), 
		m_title(title), 
		m_description(description),
		m_completed(false)
	{
	}

int Task::getId() const
{
	return m_id;
}

const std::string& Task::getTitle() const
{
	return m_title;
}

const std::string& Task::getDescription() const
{
	return m_description;
}

bool Task::getCompleted() const
{
	return m_completed;
}
