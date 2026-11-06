#ifndef TASK_H
#define TASK_H
#include <string>
class Task //This class represents a task in the task manager. It contains information about the task such as its ID, title, description, and completion status.
{
private:
	int m_id;
	std::string m_title;
	std::string m_description;
	bool m_completed;

public:
	Task(int id, const std::string& title, const std::string& description); //This is the constructor for the Task class. 
};
#endif