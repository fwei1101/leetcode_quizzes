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
		// Init input args here
		std::string s = tc["input"]["s"].as<std::string>();
		std::string expect = tc["expect"].as<std::string>();

		auto res = sol(s);

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "s=\"" << s << "\"],"
					<< "[expect:\"" << expect <<"\"],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}
