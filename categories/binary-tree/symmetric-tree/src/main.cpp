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
		auto expect = tc["expect"].as<bool>();

		auto res = sol(root);

		if (res != expect)
		{
			std::cout << std::boolalpha
				<< "{FAILED}:"
					<< "[input:" << "root=" << root->to_vec() << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}
