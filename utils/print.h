#pragma once
#include <ostream>
#include <vector>

class Printer {
public:
    Printer(std::ostream& _os) : os(_os), glob_count(0) {};
    void print_out(const std::vector<int>& b);
    int getGlobCount() const { return glob_count; }
private:
    std::ostream& os;
    int glob_count;
};
