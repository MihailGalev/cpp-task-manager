#ifndef TASK_MANIPULATION_H
#define TASKL_MANIPULATION_H
#include "taskManager.h"
void addTask(TaskManager& manager);
void deleteTask(TaskManager& manager);
void markTaskComplete(TaskManager& manager);
void changeTaskInfo(TaskManager& manager);
#endif // !TASK_MANIPULATION_H

