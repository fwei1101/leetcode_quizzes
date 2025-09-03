#include "solution.hpp"
#include "parser.hpp"
#include <iostream>
#include <yaml-cpp/yaml.h>

int main()
{
	YAML::Node tcs = YAML::LoadFile("./test/tcs.yaml");

	Solution sol;

	for (auto const & tc : tcs["tcs"])
	{
		auto root = TreeNode::from(tc["input"]["root"].as<std::vector<std::optional<int>>>());
		auto expect = tc["expect"].as<std::vector<std::optional<int>>>();

		auto res = sol(root);

		if (res->to_vec() != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "root=" << root->to_vec() << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res->to_vec() << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}
