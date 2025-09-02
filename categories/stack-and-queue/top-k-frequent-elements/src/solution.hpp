#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

class Solution
{
public:
	std::vector<int> operator()(std::vector<int> const & nums, int k)
	{
		std::unordered_map<int, int> freq;
		for (auto const & n: nums)
		{
			freq[n]++;
		}

		auto cmp = [](std::pair<int, int> const & a, std::pair<int, int> const & b)
		{
			return a.second > b.second;
		};
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
		for (auto it = freq.begin(); it != freq.end(); ++it)
		{
			pq.push(*it);
			if (pq.size() > static_cast<unsigned>(k)) pq.pop();
		}
		
		std::vector<int> res(k);
		for (auto it = res.rbegin(); it != res.rend(); ++it)
		{
			*it = pq.top().first; pq.pop();
		}
		return res;
	}
};