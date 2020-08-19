#include "print.h"

namespace {

    void print_time(std::ostream& os, int time)
    {
        int hours = time / 3600;
        if (hours)
        {
            os << "Hours " << hours << " ";
        }
        int min_and_sek = time % 3600;
        int min = min_and_sek / 60;
        if (min)
        {
            os << "Min " << min << " ";
        }
        os << "Sek " << min_and_sek % 60 << std::endl;

    }
}


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

void Printer::out_time(int time) const
{
    print_time(os, time);
}
