#include "print.h"

void Printer::print_out(const std::vector<int>& b)
{
	++glob_count;
	for(int val : b)
	{
		os << val << " ";
	}
	os << std::endl;
}
