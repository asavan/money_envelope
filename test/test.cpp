#include "../lib/money_to_cases.h"
#include "../utils/timer.h"
#include "../utils/print.h"
#include <fstream>

void check_print(int money, int number, const std::vector<int>& b)
{
	if (money != b[number]) std::cout << "Error" << std::endl;
	bool res = check(money, number, b) ;
	if (res)
	{
		std::cout << "Ok" << std::endl;
	}
	else
	{
		std::cout << "FAILED" << std::endl;
	}
}

void main_funk1000_10(int case_num, const char* name)
{
	std::ofstream ofs(name);
	Printer p(ofs);
	std::vector<int> base(10); // size of cases
	base[0] = 1;
	base[1] = 2;
	base[2] = 4;
	base[3] = 8;
	base[4] = 16;
	base[5] = 31;
	base[6] = 62;
	Timer t;
	put(summ(case_num, base), case_num, 1000 - summ(case_num, base), base, [&p](const std::vector<int>& b) -> void { p.print_out(b); });
	int time = t.stop();
	ofs << "Total count " << p.getGlobCount() << std::endl;
	print_time(ofs, time);
}

int test_1()
{
	// main_funk1000_10(0, "test11.txt");
	// main_funk1000_10(2, "test12.txt");
	// main_funk1000_10(3, "test13.txt");
	// main_funk1000_10(4, "test14.txt");
	main_funk1000_10(5, "test15.txt");
	// main_funk1000_10(6, "test16.txt");
	// main_funk1000_10(7, "test17.txt");
	return 0;
}

int test_2()
{
	std::vector<int> b;
	for(int i = 0; i < 9; ++i)
	{
		int insert = 1 << i;
		b.push_back(insert);
		check_print(insert, i, b);
	}
	int rest = 1000 - summ(9, b);
	b.push_back(rest);
	std::cout << rest << std::endl;
	check_print(rest, 9, b);
	return 0;
}

int main()
{
	test_1();
	return 0;
}
