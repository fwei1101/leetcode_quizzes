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
		int n = tc["input"]["n"].as<int>();
		bool expect = tc["expect"].as<bool>();

		auto res = s(n);

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "n=" << n << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}