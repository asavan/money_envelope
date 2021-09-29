#include "../lib/money_to_cases.h"
#include "../utils/print.h"
#include <iostream>
#include <chrono>

int main(int, char**)
{
    Printer p(std::cout);
    std::vector<int> base(10); // size of cases
    auto start = std::chrono::high_resolution_clock::now();
    put(0, 0, 1000, base, [&p](const auto& b) { p.print_out(b); });
    auto finish = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::milliseconds>(finish - start);
    p.print_total();
    std::cout << duration.count() << "ms" << std::endl;
    return 0;
}
