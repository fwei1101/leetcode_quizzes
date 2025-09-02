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
		auto nums = tc["input"]["nums"].as<std::vector<int>>();
		auto k = tc["input"]["k"].as<int>();
		auto expect = tc["expect"].as<std::vector<int>>();

		auto res = s(nums, k);

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "nums=" << nums << ",k=" << k << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}
