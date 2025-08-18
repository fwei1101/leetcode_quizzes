#include <vector>

class Solution
{
public:
	int operator()(std::vector<int> const & nums, int const & target)
	{
		auto left = nums.begin(), right = nums.end();
		while (left < right)
		{
			auto mid = left + (right - left) / 2;
			if (*mid == target)
				return std::distance(nums.begin(), mid);
			else if (*mid < target)
				left = std::next(mid);
			else
				right = mid;
		}
		return -1;
	}
};