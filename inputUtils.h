#ifndef INPUT_UTILS_H 
#define INPUT_UTILS_H
#include <string>
enum class InputResult
{
	Success, 
	Invalid, 
	EndOfInput
};
InputResult tryReadPositiveInteger(int& id);
bool tryParseInteger(const std::string& input, int& value);
#endif INPUT_UTILS_H