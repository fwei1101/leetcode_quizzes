#include <string>

class Solution
{
public:
	bool operator()(std::string const & s, std::string const & t)
	{
		int record[26] = {0};
		for (auto const & c : s)
		{
			++record[c - 'a'];
		}
		for (auto const & c : t)
		{
			if (--record[c - 'a'] < 0)
			{
				return false;
			}
		}
		for (auto const & count : record)
		{
			if (count != 0)
			{
				return false;
			}
		}
		return true;
	}
};