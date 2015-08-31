#include "timer.h"
void print_time(std::ostream& os, int time)
{
	int hours = time/3600;
	if(hours)
	{
		os << "Hours " << hours << " ";
	}
	int min_and_sek = time%3600;
	int min = min_and_sek/60;
	if(min)
	{
		os << "Min " << min << " ";
	}
	os << "Sek " << min_and_sek%60 << std::endl;

}
