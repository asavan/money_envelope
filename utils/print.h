#pragma once
#include <ostream>
#include <vector>

class Printer {
public:
    explicit Printer(std::ostream& _os);
    void print_out(const std::vector<int>& b);
    void print_total() const;
private:
    std::ostream& os;
    std::vector<std::vector<int>> memo;
};
