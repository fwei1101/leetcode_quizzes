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
		std::vector<int> nums1 = tc["input"]["nums1"].as<std::vector<int>>();
		std::vector<int> nums2 = tc["input"]["nums2"].as<std::vector<int>>();
		std::vector<int> expect = tc["expect"].as<std::vector<int>>();

		auto res = s(nums1, nums2);

		std::sort(expect.begin(), expect.end());
		std::sort(res.begin(), res.end());

		if (res != expect)
		{
			std::cout
				<< "{FAILED}:"
					<< "[input:" << "nums1=" << nums1 << ",nums2=" << nums2 << "],"
					<< "[expect:" << expect << "],"
					<< "[got:" << res << "]"
				<< std::endl;
		}
	}

	std::cout << "==== All Test Cases Completed ====" << std::endl;
	return 0;
}