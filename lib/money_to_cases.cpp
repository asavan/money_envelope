#include "money_to_cases.h"
// #include <iostream>

int summ(int number, const std::vector<int>& b)
{
    int s = 0;
    for (int i = 0; i < number; ++i)
    {
        s += b[i];
    }
    return s;
}

// берем или не берем конверты начиная с самых крупных
bool take(int curr_summ, int curr_index, int money, const std::vector<int>& b) 
{
    if (money == curr_summ) {
        return true;
    }
    if (money < curr_summ || curr_index == -1) {
        return false;
    }
    return take(curr_summ + b[curr_index], curr_index - 1, money, b) || take(curr_summ, curr_index - 1, money, b);
}

// проверяем что можем набрать конкретную сумму
bool check_cur_sum(int money, int number, const std::vector<int>& b)
{
    return take(0, number - 1, money, b);
}

// проверяем что можем набрать все суммы меньше той что кладем в этот конверт
bool check(int money, int number, const std::vector<int>& b)
{
    // допускаем нули для начальных конвертов
    // if(number == 0) return money < 2;
    // на предыдущем шаге мы могли набрать любую сумму до b[number-1]
    // значит можем набрать любую сумму до b[number-1] + (b[number-1] - 1)
    // for(int i = std::max(b[number-1] * 2, 0); i < money; ++i)
    // if (summ(number-1, b) < money-10) return false;
    if (number == 0)
    {
        return money <= 1;
    }
    int prev_index = number - 1;
    for (int i = b[prev_index] * 2; i < money; ++i)
    {
        if (!check_cur_sum(i, number, b)) return false;
    }
    return true;
}

void put(int money, int number, int rest, std::vector<int>& base, std::function<void(const std::vector<int>&)> out)
{
    int size = (int)base.size();
    int prev_index = number - 1;
    int s = summ(number, base) + 1;
    // последний конверт - особый случай
    if (number == size - 1)
    {
        if (rest > s) {
            // std::cout << "Never 1" << std::endl;
            return;
        }
        // нарушен порядок. мы раскладываем монеты упорядоченно. этот случай уже посчитан.
        if (rest < base[prev_index]) {
            // std::cout << "Never 2" << std::endl;
            return;
        }
        if (check(rest, number, base))
        {
            base[number] = rest;
            out(base);
        }
        return;
    }
    // весь остаток положить нельзя, так как конверт не последний. Кладем не больше остатка поделенного на количество пустых конвертов
    int to = std::min(s, rest / (size - number));
    for (int i = money; i <= to; ++i)
    {
        // остаток точно не должен быть больше чем 1000 - 2^number
        if (rest - i - 1 > (1000 - (1 << (number))))
        {
            // std::cout << "Never 5" << std::endl;
            continue;
        }
        // если предпоследний конверт вместе с суммой предыдущих меньше того что останется - проверять нет смысла
        if (number == size - 2 && (s + i) < rest - i + 1) {
            continue;
        }
        if (!check(i, number, base))
        {
            return;
        }
        base[number] = i;
        put(i, number + 1, rest - i, base, out);
    }
}
