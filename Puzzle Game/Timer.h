#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

namespace Timer
{
	auto start()
	{
		return std::chrono::high_resolution_clock::now();
	}

	auto stop()
	{
		return std::chrono::high_resolution_clock::now();
	}

	using time = std::chrono::high_resolution_clock::time_point;
	std::chrono::seconds duration(time stop, time start)
	{
		return std::chrono::duration_cast<std::chrono::seconds>(stop - start);
	}
}

#endif // !TIMER_H
