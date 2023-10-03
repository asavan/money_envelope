#include "print.h"

Printer::Printer(std::ostream& _os) : os(_os) {}

void Printer::print_out(const std::vector<int>& b)
{
    memo.emplace_back(b);
}

void Printer::print_total() const
{
    for (auto b : memo) {
        for (int val : b)
        {
            os << val << " ";
        }
        os << std::endl;        
    }
    os << "Total count " << memo.size() << std::endl;
}
