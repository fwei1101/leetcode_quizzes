#include "binary-tree.hpp"
#include <stack>

class Solution
{
	void recursive(std::shared_ptr<TreeNode const> root, std::vector<int> & res)
	{
		if (root == nullptr) return;

		// preorder
		// res.emplace_back(root->val);
		// recursitor(root->left, res);
		// recursitor(root->right, res);

		// inorder
		// recursitor(root->left, res);
		// res.emplace_back(root->val);
		// recursitor(root->right, res);

		// postorder
		recursive(root->left, res);
		recursive(root->right, res);
		res.emplace_back(root->val);

		return;
	}

	void iterative(std::shared_ptr<TreeNode const> root, std::vector<int> & res)
	{
		if (root == nullptr) return;
		std::stack<std::shared_ptr<TreeNode const>> s;

		// preorder
		// s.push(root);
		// while (!s.empty())
		// {
		// 	auto node = s.top(); s.pop();
		// 	res.emplace_back(node->val);
		// 	if (node->right) s.push(node->right);
		// 	if (node->left) s.push(node->left);
		// }

		// inorder
		// auto curr = root;
		// while (curr != nullptr || !s.empty())
		// {
		// 	if (curr != nullptr)
		// 	{
		// 		s.push(curr);
		// 		curr = curr->left;
		// 	}
		// 	else
		// 	{
		// 		curr = s.top(); s.pop();
		// 		res.emplace_back(curr->val);
		// 		curr = curr->right;
		// 	}
		// }

		// postorder
		s.push(root);
		while (!s.empty())
		{
			auto node = s.top(); s.pop();
			res.emplace_back(node->val);
			if (node->left) s.push(node->left);
			if (node->right) s.push(node->right);
		}
		std::reverse(res.begin(), res.end());

		return;
	}

public:
	std::vector<int> operator()(std::shared_ptr<TreeNode const> root)
	{
		std::vector<int> res;
		// recursive(root, res);
		iterative(root, res);
		return res;
	}
};