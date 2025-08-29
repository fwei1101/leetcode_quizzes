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
		int val = tc["input"]["val"].as<int>();
		int expect = tc["expect"].as<int>();

		auto res = s(nums, val);

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "nums=" << nums << ",val=" << val << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}
