#include "print.h"

Printer::Printer(std::ostream& _os) : os(_os), glob_count(0) {}

void Printer::print_out(const std::vector<int>& b)
{
    ++glob_count;
    for (int val : b)
    {
        os << val << " ";
    }
    os << std::endl;
}

void Printer::print_total() const
{
    os << "Total count " << glob_count << std::endl;
}
