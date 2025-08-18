#include <vector>

class Solution
{
public:
	std::vector<int> operator()(std::vector<int> const & nums)
	{
		std::vector<int> result(nums.size());

		auto left = nums.begin(), right = std::prev(nums.end());
		for (auto writer = result.rbegin(); writer != result.rend(); ++writer)
		{
			if ((*left) * (*left) > (*right) * (*right))
			{
				*writer = (*left) * (*left);
				++left;
			} else
			{
				*writer = (*right) * (*right);
				--right;
			}
		}

		return result;
	}
};