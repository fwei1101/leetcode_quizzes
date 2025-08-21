#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	std::string str;
	int k;
	InputParser ip;
	ip(str);
	ip(k);

	Solution s;
	auto res = s(str, k);

	std::cout << "Res: " << res << std::endl;

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
