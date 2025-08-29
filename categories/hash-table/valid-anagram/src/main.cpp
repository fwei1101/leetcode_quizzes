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
		std::string t = tc["input"]["t"].as<std::string>();
		bool expect = tc["expect"].as<bool>();

		auto res = sol(s, t);

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "s=" << s << ",t=" << t << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}