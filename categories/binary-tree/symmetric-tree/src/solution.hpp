#include "binary-tree.hpp"
#include <stack>
#include <memory>

class Solution
{
public:
	bool operator()(std::shared_ptr<TreeNode> const & root)
	{
		if (root == nullptr) return true;
		std::stack<std::shared_ptr<TreeNode>> s;
		s.push(root->left);
		s.push(root->right);
		while (!s.empty())
		{
			auto left = s.top(); s.pop();
			auto right = s.top(); s.pop();
			if (left == nullptr && right == nullptr)
			{
				continue;
			}
			if (left == nullptr || right == nullptr || left->val != right->val)
			{
				return false;
			}
			s.push(left->left);
			s.push(right->right);
			s.push(left->right);
			s.push(right->left);
		}
		return true;
	}
};