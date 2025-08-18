#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	std::vector<int> nums;
	int val;
	InputParser ip;
	ip(nums);
	ip(val);

	Solution s;
	auto res = s(nums, val);
	std::cout << "Result: " << res << std::endl;

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
