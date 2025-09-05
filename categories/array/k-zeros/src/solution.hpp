#include <vector>

class Solution
{
public:
	int operator()(std::vector<int> const & nums, int k)
	{
		auto left = nums.cbegin();
		auto right = left;
		int maximumContinuousOne = 0;
		while (left <= right && right != nums.cend())
		{
			while (right < nums.cend() && (*right == 1 || k > 0))
			{
				if (*right == 0) k--;
				right++;
			}
			int len = std::distance(left, right);
			maximumContinuousOne = std::max(len, maximumContinuousOne);
			while (*left == 1 && left < right)
			{
				left++;
			}
			++left;
			++k;
		}
		return maximumContinuousOne;
	}
};