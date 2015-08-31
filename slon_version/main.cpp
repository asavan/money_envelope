#include <iostream>
#include <vector>
#include "../utils/print.h"

int f_recursive(int t)
{
	int res = 1;
	if (t == 0) return 1;

	int k = (t-1)/2;
	
	if (t%2) 
	{
		// 2*k + 1 = t
		res = f_recursive(2*k);		
	}
	else 
	{	
		// 2*k + 2 = t
		res = f_recursive(2*k) + f_recursive(k+1);
	}
	// std::cout<<t<< " " << res << std::endl;
	return res;
}

int f_loop(int t)
{
	if(t<0) return 0;
	int res = 0;
	std::vector<int> answer(t+1);
	answer[0] = 1;	
	for(int i=0; i < t/2; ++i)
	{
		answer[2*i+1] = answer[2*i];
		answer[2*i+2] = answer[2*i] + answer[i+1];
	}

	if(t%2)
	{
		int i = t/2;
		answer[2*i+1] = answer[2*i];
		// answer[t] = answer[t-1];
	}
	// std::cout << "f8 ";
	// print_out(answer);
	return answer[t];
}


int g(int i)
{
	return f_recursive(1023-i);
}

int g2(int i)
{
	return f_loop(1023-i);
}

bool test()
{
	return g(1001) == 74 && g(1000) == 74 && g(1002) == 60 && g(1003) == 60 && g(999) == 94;
}

bool test2()
{
	return g2(1001) == 74 && g2(1000) == 74 && g2(1002) == 60 && g2(1003) == 60 && g2(999) == 94;
}


int main()
{
	// std::cout<< f2(0) << std::endl;
	std::cout << g2(1000) << std::endl;	
	// std::cout << g2(1000) << std::endl;	
	std::cout << (test() && test2()) << std::endl;
	// std::cout <<  << std::endl;
}
