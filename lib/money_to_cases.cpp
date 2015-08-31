#include "money_to_cases.h"
int summ(int number, const std::vector<int>& b)
{
	int s = 0;
	for(int i = 0; i < number; ++i)
	{
		s += b[i];
	}
	return s;
}

// проверяем что можем набрать конкретную сумму
bool check_cur_sum(int money, int number, const std::vector<int>& b)
{
	for (int j = 1; j < (1<<number); ++j)
	{
		int res = 0;
		for(int k = 0; k < number; ++k)
		{
			res += ((j>>k)&1) * b[k];
		}
		if (res == money) 
		{
			return true;
		}
	}
	return false;
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
	for(int i = b[number-1]*2; i < money; ++i)
	{
		if (!check_cur_sum(i, number, b)) return false;
	}
	return true;
}

void put(int money, int number, int rest, std::vector<int>& base, void (*out)(const std::vector<int>& b))
{
	int to = summ(number, base) + 1;
	// последний конверт - особый случай
	if (number == base.size() - 1)
	{	
		if (rest > to) return; 
		// нарушен порядок. мы раскладываем монеты упорядоченно. этот случай уже посчитан.
		if (rest < base[number-1]) return;
		if (check(rest, number, base))
		{
			base[number] = rest;
			out(base);
		}
		return;
	}
	// весь остаток положить нельзя, так как конверт не последний
	to = std::min(to, rest);
	for(int i = money; i <= to; ++i)
	{
		// остаток точно не должен быть больше чем 1000 - 2^number
		if (rest - i - 1 > (1000-(1<<(number))))
		{
			return;
		}
		if (!check(i, number, base))
		{
			return;
		}
		base[number] = i;
		put(i, number+1, rest - i, base, out);
	}
}
