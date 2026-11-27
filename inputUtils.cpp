#include "inputUtils.h"
#include <sstream>
#include <iostream>

bool tryParseInteger(const std::string& input, int& value)
{
	std::istringstream stream(input);
	int parsedValue{};
	stream >> parsedValue;

	if (stream.fail())
	{
		return false;
	}
	stream >> std::ws;

	if (stream.peek() != EOF)
	{
		return false;
	}
	value = parsedValue;
	return true;
}

InputResult tryReadPositiveInteger(int& value)
{
	std::string input;
	int t_value{};
	if (!std::getline(std::cin, input))
	{
		return InputResult::EndOfInput;
	}
	if (!tryParseInteger(input, t_value) || t_value <= 0)
	{
		return InputResult::Invalid;
	}

	value = t_value;
	return InputResult::Success;
}