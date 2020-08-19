#include "../lib/money_to_cases.h"
#include "../utils/timer.h"
#include "../utils/print.h"
#include <fstream>
#include <chrono>

int main(int argc, char *argv[])
{
	std::ostream& os = std::cout;
	Printer p(os);
	std::vector<int> base(10); // size of cases
	auto start = std::chrono::high_resolution_clock::now();
	put(0, 0, 1000, base, [&p](const std::vector<int>& b) -> void { p.print_out(b); });
	auto finish = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::seconds>(finish - start);
	os << "Total count " << p.getGlobCount() << std::endl;
	print_time(os, duration.count());
	return 0;
}
