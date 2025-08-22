#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	std::vector<int> nums;
	InputParser ip;
	ip(nums);

	Solution s;
	auto res = s(nums);

	OutputParser op;
	op(res);

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
