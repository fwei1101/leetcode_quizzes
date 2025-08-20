#include <unordered_set>

class Solution
{
private:
	std::unordered_set<int> seen;
	int get_sum(int n)
	{
		int sum = 0;
		while (n)
		{
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
public:
	bool operator()(int const & n)
	{
		auto sum = get_sum(n);
		if (sum == 1)
		{
			return true;
		}
		else if (seen.find(sum) != seen.end())
		{
			return false;
		}
		else
		{
			seen.insert(sum);
			return this->operator()(sum);
		}
	}
};