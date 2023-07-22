#include "UserInput.h"
#include "Direction.h"

bool UserInput::isValidCommand(char in)
{
	return in == 'q'
		|| in == 'w'
		|| in == 's'
		|| in == 'd'
		|| in == 'a'
		|| in == 'y'
		|| in == 'n';
}

char UserInput::getCommand()
{
	while(true)
	{
		char handleInput;
		std::cin >> handleInput;
		if (isValidCommand(handleInput))
		{
			std::cout << "Valid command: " << handleInput << std::endl;
			return handleInput;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
}
