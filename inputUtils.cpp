#include "inputUtils.h"
#include <sstream>

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