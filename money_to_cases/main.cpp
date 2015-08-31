#include "../lib/money_to_cases.h"
#include "../utils/timer.h"
#include "../utils/print.h"
#include <fstream>
#include <iostream>
#include <math.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ofs.open("out_fast2.txt");
	}
	else
	{
		ofs.open(argv[1]);
	}
	glob_count = 0;
	std::vector<int> base(10); // size of cases
	base[0] = 1;
	int case_num = 1;
	Timer t;
	put(1, case_num, 1000-summ(case_num, base), base, print_out);
	int time = t.stop();
	ofs << "Total count " << glob_count << std::endl;
	print_time(ofs, time);
	ofs.close();
	return 0;
}
