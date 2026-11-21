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
	std::vector<Task>::iterator findTaskById(int id);
public:
	std::size_t getTaskCount() const;
	std::size_t getCompletedTaskCount() const;
	std::size_t getIncompleteTaskCount() const;
	bool addTask(int id, const std::string& title,
		const std::string& description);
	void viewTasks() const;
	bool markTaskCompleted(int id);
	bool deleteTask(int id);
	bool changeTaskTitle(int t_id, const std::string& t_title);
	bool taskExists(int t_id);
	bool isTaskCompleted(int t_id);
	bool changeTaskDescription(int t_id, const std::string& t_description);
};
#endif // !TASK_MANAGER_H

