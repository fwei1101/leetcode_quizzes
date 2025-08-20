#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	int i;
	InputParser ip;
	ip(i);

	Solution s;
	auto res = s(i);

	std::cout << "Res: " << res << std::endl;

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
