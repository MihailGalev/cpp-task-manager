#ifndef TASK_MENU_H
#define TASK_MENU_H

#include "taskManager.h"
enum class MenuType
{
	MainMenu, 
	ChangeInfoMenu
};
void taskMenu(TaskManager& manager);
bool isValidMenuOption(int t_option, MenuType mode);
#endif // TASK_MENU_H
