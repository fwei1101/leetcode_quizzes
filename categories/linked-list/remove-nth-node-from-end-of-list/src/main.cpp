#include "solution.hpp"
#include "parser.hpp"
#include <iostream>

int main()
{
	auto head = std::make_shared<ListNode>();
	int n;
	InputParser ip;
	ip(head);
	ip(n);

	Solution s;
	auto res = s(head, n);
	
	OutputParser op;
	op(res);

	std::cout << "==== Completed ====" << std::endl;
	return 0;
}
