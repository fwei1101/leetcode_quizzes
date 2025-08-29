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
		std::vector<int> nums = tc["input"]["nums"].as<std::vector<int>>();
		int target = tc["input"]["target"].as<int>();
		int expect = tc["expect"].as<int>();

		auto res = s(nums, target);

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "nums=" << nums << ",target=" << target << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}
