#include <vector>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> operator()(std::vector<int> const & nums1, std::vector<int> const & nums2)
	{
		int nums1_set[1001] = {0};
		for (auto const & i : nums1)
		{
			nums1_set[i] = 1;
		}
		std::vector<int> res;
		for (auto const & i : nums2)
		{
			if (nums1_set[i] != 0)
			{
				res.emplace_back(i);
				nums1_set[i] = 0;
			}
		}
		return res;
	}
};