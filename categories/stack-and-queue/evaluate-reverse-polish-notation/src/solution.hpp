#include <stack>
#include <string>
#include <vector>
#include <stdexcept>

class Solution
{
	int evaluate(int n1, int n2, char op)
	{
		switch (op)
		{
			case '+': return n1 + n2;
			case '-': return n1 - n2;
			case '*': return n1 * n2;
			case '/': return n1 / n2;
			default: throw std::runtime_error("Invalid operator");
		}
	}
public:
	int operator()(std::vector<std::string> const & tokens)
	{
		std::stack<int> stk;
		for (auto const & token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				int n2 = stk.top(); stk.pop();
				int n1 = stk.top(); stk.pop();
				stk.push(evaluate(n1, n2, token.front()));
			}
			else
			{
				stk.push(std::stoi(token));
			}
		}
		int res = stk.top(); stk.pop();
		return res;
	}
};