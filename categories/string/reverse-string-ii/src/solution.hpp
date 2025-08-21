#include <string>
#include <algorithm>

class Solution
{
public:
	std::string operator()(std::string input, int k)
	{
		for (size_t i = 0; i < input.size(); i += 2 * k)
		{
			if (i + k <= input.size())
			{
				reverse(input.begin() + i, input.begin() + i + k);
			}
			else
			{
				reverse(input.begin() + i, input.end());
			}
		}
		return input;
	}
};