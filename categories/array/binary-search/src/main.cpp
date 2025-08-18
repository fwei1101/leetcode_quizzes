#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	std::vector<int> nums;
	int target;
	InputParser ip;
	ip(nums);
	ip(target);

	Solution s;
	auto res = s(nums, target);

	std::cout << "Result: " << res << std::endl;

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}