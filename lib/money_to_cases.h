#pragma once
/** ���������� �������� �������� � size_of_cases ��������� rest �����
*
*/

#include <vector>
#include <functional>
bool check(int money, int number, const std::vector<int>& b);
int summ(int number, const std::vector<int>& b);
void put(int money, int number, int rest, std::vector<int>& base, std::function<void(const std::vector<int>&)> out);
