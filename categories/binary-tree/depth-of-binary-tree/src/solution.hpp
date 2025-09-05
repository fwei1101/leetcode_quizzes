#include "binary-tree.hpp"

class Solution
{
	int get_max_depth(std::shared_ptr<TreeNode> const & node)
	{
		if (node == nullptr) return 0;
		int left_depth = get_max_depth(node->left);
		int right_depth = get_max_depth(node->right);
		return 1 + std::max(left_depth, right_depth);
	}
	int get_min_depth(std::shared_ptr<TreeNode> const & node)
	{
		if (node == nullptr) return 0;
		if (node->left == nullptr && node->right != nullptr)
		{
			return 1 + get_min_depth(node->right);
		}
		if (node->left != nullptr && node->right == nullptr)
		{
			return 1 + get_min_depth(node->left);
		}
		int left_depth = get_min_depth(node->left);
		int right_depth = get_min_depth(node->right);
		return 1 + std::min(left_depth, right_depth);
	}
public:
	int operator()(std::shared_ptr<TreeNode> const & root)
	{
		// return get_max_depth(root);
		return get_min_depth(root);
	}
};