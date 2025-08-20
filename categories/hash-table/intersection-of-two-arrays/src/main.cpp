#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	std::vector<int> nums1, nums2;
	InputParser ip;
	ip(nums1);
	ip(nums2);

	Solution s;
	auto res = s(nums1, nums2);
	
	OutputParser op;
	op(res);

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
