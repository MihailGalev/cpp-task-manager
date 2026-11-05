#include <string>
#ifndef TASK_H
#define TASK_H
class Task
{
public:

private:
	int id{};
	std::string title{};
	std::string description{};
	bool completed{};
};
#endif