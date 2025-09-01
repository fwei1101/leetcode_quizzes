#include <vector>
#include <deque>

class Solution
{
	class MonotonicQueue
	{
		std::deque<int> q;
	public:
		MonotonicQueue(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
		{
			for (; begin != end; ++begin)
			{
				push(*begin);
			}
		}
		void pop(int const & n)
		{
			if (!q.empty() && n == q.front()) q.pop_front();
		}
		void push(int n)
		{
			while (!q.empty() && n > q.back()) q.pop_back();
			q.push_back(n);
		}
		int front() const
		{
			return q.front();
		}
	};
public:
	std::vector<int> operator()(std::vector<int> const & nums, int const & k)
	{
		std::vector<int> res;
		MonotonicQueue mq(nums.cbegin(), nums.cbegin() + k);
		res.emplace_back(mq.front());

		for (auto it = nums.cbegin() + k; it != nums.cend(); ++it)
		{
			mq.pop(*(it - k));
			mq.push(*it);
			res.emplace_back(mq.front());
		}

		return res;
	}
};