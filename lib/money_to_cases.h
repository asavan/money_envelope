/** количество способов положить в size_of_cases конвертов rest денег
*
*/

#include <vector>
bool check(int money, int number, const std::vector<int>& b);
int summ(int number, const std::vector<int>& b);
void put(int money, int number, int rest, std::vector<int>& base, void (*out)(const std::vector<int>& b));
