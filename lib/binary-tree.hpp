#pragma once

#include <memory>
#include <vector>
#include <optional>
#include <queue>
#include "yaml_optional.hpp"

struct TreeNode : public std::enable_shared_from_this<TreeNode>
{
	int val;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode() : val(), left(nullptr), right(nullptr) {}
	TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, std::shared_ptr<TreeNode> l, std::shared_ptr<TreeNode> r) : val(v), left(l), right(r) {}

	static std::shared_ptr<TreeNode> from(std::vector<std::optional<int>> const &);
	std::vector<std::optional<int>> to_vec() const;
};

std::shared_ptr<TreeNode> TreeNode::from(std::vector<std::optional<int>> const & vec)
{
	if (vec.empty() || !vec.front().has_value()) return nullptr;

	auto root = std::make_shared<TreeNode>(vec.front().value());
	auto it = std::next(vec.cbegin());
	std::queue<std::shared_ptr<TreeNode>> q;
	q.push(root);
	while (!q.empty() && it < vec.cend())
	{
		auto node = q.front(); q.pop();
		if (it < vec.cend() && it->has_value())
		{
			node->left = std::make_shared<TreeNode>(it->value());
			q.push(node->left);
		}
		++it;
		if (it < vec.cend() && it->has_value())
		{
			node->right = std::make_shared<TreeNode>(it->value());
			q.push(node->right);
		}
		++it;
	}

	return root;
}

std::vector<std::optional<int>> TreeNode::to_vec() const
{
	std::vector<std::optional<int>> vec;
	std::queue<std::shared_ptr<TreeNode const>> q;
	q.push(shared_from_this());
	while (!q.empty())
	{
		auto const node = q.front(); q.pop();
		if (node)
		{
			vec.push_back(node->val);
			q.push(node->left);
			q.push(node->right);
		}
		else
		{
			vec.push_back(std::nullopt);
		}
	}

	while (!vec.empty() && !vec.back().has_value())
	{
		vec.pop_back();
	}

	return vec;
}