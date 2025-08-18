#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	int target;
	std::vector<int> nums;
	InputParser ip;
	ip(target);
	ip(nums);

	Solution s;
	auto res = s(target, nums);

	std::cout << "Result: " << res << std::endl;
	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
