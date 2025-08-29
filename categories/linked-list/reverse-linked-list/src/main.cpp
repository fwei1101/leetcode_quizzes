#include "solution.hpp"
#include "parser.hpp"
#include <iostream>
#include <yaml-cpp/yaml.h>

int main()
{
	YAML::Node tcs = YAML::LoadFile("./test/tcs.yaml");

	Solution s;

	for (auto const & tc : tcs["tcs"])
	{
		std::shared_ptr<ListNode> head = ListNode::from(tc["input"]["head"].as<std::vector<int>>());
		std::shared_ptr<ListNode> expect = ListNode::from(tc["expect"].as<std::vector<int>>());

		auto res = s(head);

		auto vres = res->to_vec(), vexpect = expect->to_vec();
		if (vres != vexpect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "head=" << head->to_vec() << "],"
					<< "[expect:" << vexpect << "],"
					<< "[got:" << vres << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}