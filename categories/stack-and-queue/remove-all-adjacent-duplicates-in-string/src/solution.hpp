#include <string>
#include <deque>

class Solution
{
public:
	std::string operator()(std::string const & s)
	{
		std::string res;
		for (auto const & c: s)
		{
			if (res.empty() || res.back() != c)
			{
				res.push_back(c);
			}
			else
			{
				res.pop_back();
			}
		}
		return res;
	}
};