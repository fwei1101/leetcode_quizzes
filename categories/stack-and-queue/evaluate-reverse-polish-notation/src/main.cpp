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
		// Init input args here
		std::vector<std::string> tokens = tc["input"]["tokens"].as<std::vector<std::string>>();
		int expect = tc["expect"].as<int>();

		auto res = s(tokens);

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "tokens=" << tokens << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}
