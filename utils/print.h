#pragma once
#include <ostream>
#include <vector>

class Printer {
public:
    Printer(std::ostream& _os);
    void print_out(const std::vector<int>& b);
    void print_total() const;
    void out_time(int time) const;
private:
    std::ostream& os;
    int glob_count;
};
