#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	std::string a, b;
	InputParser ip;
	ip(a);
	ip(b);

	Solution s;
	auto res = s(a, b);
	
	std::cout << "Res: " << res << std::endl;

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}