#ifndef TASK_MENU_H
#define TASK_MENU_H

#include "taskManager.h"
void taskMenu(TaskManager& manager);
bool checkInvalidInput();
bool isValidMenuOption(int t_option, int mode);
#endif // TASK_MENU_H
