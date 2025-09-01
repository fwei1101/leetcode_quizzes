#include <stack>
#include <string>

class Solution
{
public:
	bool operator()(std::string const & s)
	{
		if (s.size() % 2) return false;

		std::stack<char> stk;
		for (auto const & c : s)
		{
			if (c == '(') stk.push(')');
			else if (c == '[') stk.push(']');
			else if (c == '{') stk.push('}');
			else if (stk.empty() || stk.top() != c) return false;
			else stk.pop();
		}
		return stk.empty();
	}
};