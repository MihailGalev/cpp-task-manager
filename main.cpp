#include <iostream>
#include "taskMenu.h"
#include "taskManager.h"

int main()
{
	//taskMenu();
	TaskManager manager;
	manager.addTask(1, "Hello", "I'm saying Hello!");
	manager.addTask(2, "Hello1", "I'm saying Hello1!");
	manager.viewTasks();
	return 0;
}