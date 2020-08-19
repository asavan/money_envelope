#pragma once
#include <time.h>
#include <iostream>
class Timer
{
public:
	Timer()
	{
		time_start = time(0);
	}
	int stop()
	{
		time_t time_end = time(0);
		return difftime(time_end, time_start);
	}
private:
	time_t time_start;
	time_t time_end;
};

void print_time(std::ostream& os, int time);
