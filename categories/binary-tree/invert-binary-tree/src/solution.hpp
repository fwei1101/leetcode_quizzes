#include "binary-tree.hpp"
#include <memory>

class Solution
{
	void recur_invert(std::shared_ptr<TreeNode> root)
	{
		if (root == nullptr) return;
		std::swap(root->left, root->right);
		recur_invert(root->left);
		recur_invert(root->right);
	}
public:
	std::shared_ptr<TreeNode> operator()(std::shared_ptr<TreeNode> root)
	{
		recur_invert(root);
		return root;
	}
};