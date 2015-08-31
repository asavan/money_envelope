#include "print.h"
#include <iostream>
int glob_count = 0;
std::ofstream ofs;
void print_out(const std::vector<int>& b)
{
	std::ostream* os;
	if(!ofs.is_open())
	{
		// std::cerr << "FILE not set" << std::endl;
		os = &std::cout;
	}
	else
	{
		os = &ofs;
	}
	++glob_count;
	for(int i = 0; i < b.size(); ++i)
	{
		*os << b[i] << " ";
	}
	*os << std::endl;
}
