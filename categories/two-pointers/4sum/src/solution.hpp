#include <vector>
#include <algorithm>

class Solution
{
public:
	std::vector<std::vector<int>> operator()(std::vector<int> & nums, int const & target)
	{
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> res;
		for (auto a = nums.begin(); a != nums.end(); ++a)
		{
			if (*a > target && *a >= 0)
			{
				break;
			}
			if (a != nums.begin() && *a == *std::prev(a))
			{
				continue;
			}
			for (auto b = std::next(a); b != nums.end(); ++b)
			{
				if (*a + *b > target && *b >= 0)
				{
					break;
				}
				if (b != std::next(a) && *b == *std::prev(b))
				{
					continue;
				}
				auto c = std::next(b), d = std::prev(nums.end());
				while (c < d)
				{
					if ((long) *a + *b + *c + *d > target)
					{
						--d;
					}
					else if ((long) *a + *b + *c + *d < target)
					{
						++c;
					}
					else
					{
						res.emplace_back(std::vector<int>{*a, *b, *c, *d});
						while (c < d && *c == *std::next(c))
						{
							++c;
						}
						while (c < d && *d == *std::prev(d))
						{
							--d;
						}
						++c;
						--d;
					}
				}
			}
		}
		return res;
	}
};