#ifndef USERINPUT_H
#define USERINPUT_H

#include<iostream>

class Direction;

namespace UserInput
{
	bool isValidCommand(char command);
	char getCommand();
}
#endif // !USERINPUT_H
