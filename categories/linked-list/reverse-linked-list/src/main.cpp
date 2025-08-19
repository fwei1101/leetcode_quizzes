#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	auto head = std::make_shared<ListNode>();
	head.reset();
	InputParser ip;
	ip(head);

	Solution s;
	auto res = s(head);

	OutputParser op;
	op(res);

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
