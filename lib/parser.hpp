#include <iostream>
#include <vector>
#include <sstream>

#define LEFT_BRAKET std::cout << "["
#define RIGHT_BRAKET std::cout << "]"
#define COMMA std::cout << ","

class InputParser
{
public:
	void operator()(int & num);
	void operator()(std::vector<int> & nums);
	void operator()(std::string & str);
	void operator()(std::vector<std::string> & strs);
};

class OutputParser
{
public:
	void operator()(std::vector<int> const & nums);
	void operator()(std::vector<std::vector<int>> const & vecNums);
	void operator()(std::vector<std::vector<std::string>> const & vecStrs);
};

void InputParser::operator()(int& num)
{
	std::string line;

	if (std::getline(std::cin, line))
	{
		std::istringstream iss(line);
		iss >> num;
	}
}

void InputParser::operator()(std::vector<int>& nums)
{
	std::string line;

	if (std::getline(std::cin, line))
	{
		// remove '[' and ']'
		line = line.substr(1, line.length() - 2);
		std::istringstream iss(line);
		std::string strNum;
		while (std::getline(iss, strNum, ',')) {
			int num = std::stoi(strNum);
			nums.push_back(num);
		}
	}
}

void InputParser::operator()(std::string& str)
{
	std::getline(std::cin, str);
}

void InputParser::operator()(std::vector<std::string>& strs)
{
	std::string line;

	if (std::getline(std::cin, line))
	{
		std::istringstream iss(line);
		char ch;
		std::string str;

		// skip '['
		iss >> ch;
		while (iss >> ch)
		{
			if (ch == '"')
			{
				std::getline(iss, str, '"');
				strs.push_back(str);
				// skip '"' or ',' or ' '
				iss >> ch;
			}
		}
	}
}

void OutputParser::operator()(const std::vector<int> & nums)
{
	LEFT_BRAKET;
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i];
		if (i < nums.size() - 1)
		{
			COMMA;
		}
	}
	RIGHT_BRAKET << std::endl;
}


void OutputParser::operator()(const std::vector<std::vector<int>> & vecNums)
{
	LEFT_BRAKET;
	for (size_t i = 0; i < vecNums.size(); i++)
	{
		LEFT_BRAKET;
		const auto& nums = vecNums[i];
		for (size_t j = 0; j < nums.size(); j++)
		{
			std::cout << nums[j];
			if (j < nums.size() - 1)
			{
				COMMA;
			}
		}
		RIGHT_BRAKET;
		if (i < vecNums.size() - 1)
		{
			COMMA;
		}
	}
	RIGHT_BRAKET << std::endl;
}

void OutputParser::operator()(const std::vector<std::vector<std::string>> & vecStrs)
{
	LEFT_BRAKET;
	for (size_t i = 0; i < vecStrs.size(); i++)
	{
		LEFT_BRAKET;
		const auto& strs = vecStrs[i];
		for (size_t j = 0; j < strs.size(); j++)
		{
			std::cout << "\"" << strs[j] << "\"";
			if (j < strs.size() - 1)
			{
				COMMA;
			}
		}
		RIGHT_BRAKET;
		if (i < vecStrs.size() - 1)
		{
			COMMA;
		}
	}
	RIGHT_BRAKET << std::endl;
}