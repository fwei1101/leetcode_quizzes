#include <vector>

class Solution
{
public:
	int operator()(std::vector<int> & nums, int & val)
	{
		auto reader = nums.begin(), writer = reader;
		for (; reader != nums.end(); ++reader)
		{
			if (*reader != val)
			{
				*writer = *reader;
				writer++;
			}
		}
		return std::distance(nums.begin(), writer);
	}
};