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
		std::string s = tc["input"]["s"].as<std::string>();
		int k = tc["input"]["k"].as<int>();
		std::string expect = tc["expect"].as<std::string>();

		auto res = sol(s, k);

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "s=" << s << ",k=" << k << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}