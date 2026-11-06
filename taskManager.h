#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include <vector>
#include <cstddef>
#include <string>
#include "Task.h"
class TaskManager
{
private:
	std::vector<Task> m_tasks;
public:
	std::size_t getTaskCount() const;
	bool addTask(int id, const std::string& title,
		const std::string& description);
	void viewTasks() const;
	bool markTaskCompleted(int id);
	bool deleteTask(int id);
};
#endif // !TASK_MANAGER_H

