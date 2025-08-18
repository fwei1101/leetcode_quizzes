#include <vector>

class Solution
{
public:
	int operator()(int const & target, std::vector<int> const & nums)
	{
		int res = __INT_MAX__, sum = 0;
		auto left = nums.begin(), right = left;
		for (; right != nums.end(); ++right)
		{
			sum += *right;
			while (sum >= target)
			{
				res = std::min(res, static_cast<int>(std::distance(left, right)) + 1);
				sum -= *left;
				++left;
			}
		}
		return res == __INT_MAX__ ? 0 : res;
	}
};