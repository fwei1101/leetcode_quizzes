#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	auto head = std::make_shared<ListNode>(-1);
	int val;
	InputParser ip;
	ip(head);
	ip(val);
	
	Solution s;
	auto res = s(head, val);
	OutputParser op;
	op(res);
	// OutputParser op;
	// op(head);

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
