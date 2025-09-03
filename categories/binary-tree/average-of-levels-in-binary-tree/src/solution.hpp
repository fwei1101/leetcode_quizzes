#include "binary-tree.hpp"
#include <queue>
#include <vector>
#include <memory>

class Solution
{
public:
	std::vector<double> operator()(std::shared_ptr<TreeNode> const & root)
	{
		std::vector<double> res;
		if (root.get() == nullptr) return res;
		std::queue<std::shared_ptr<TreeNode>> q;
		q.push(root);
		while (!q.empty())
		{
			double sum = 0.0;
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				auto node = q.front();
				q.pop();
				sum += node->val;
				if (node->left != nullptr) q.push(node->left);
				if (node->right != nullptr) q.push(node->right);
			}
			res.emplace_back(sum / static_cast<double>(size));
		}
		return res;
	}
};