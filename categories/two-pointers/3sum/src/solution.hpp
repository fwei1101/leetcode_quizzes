#include <vector>
#include <algorithm>

class Solution
{
public:
	std::vector<std::vector<int>> operator()(std::vector<int> & nums)
	{
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> res;
		auto a = nums.begin();
		for (; a != nums.end(); ++a)
		{
			if (*a > 0)
			{
				break;
			}
			if (a != nums.begin() && *a == *std::prev(a))
			{
				continue;
			}
			auto b = std::next(a), c = std::prev(nums.end());
			while (b < c)
			{
				if (*a + *b + *c > 0)
				{
					--c;
				}
				else if (*a + *b + *c < 0)
				{
					++b;
				}
				else
				{
					res.emplace_back(std::vector<int>{*a, *b, *c});
					while (b < c && *c == *std::prev(c))
					{
						--c;
					}
					while (b < c && *b == *std::next(b))
					{
						++b;
					}
					--c;
					++b;
				}
			}
		}
		return res;
	}
};