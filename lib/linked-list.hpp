#pragma once

#include <memory>
#include <vector>

struct ListNode
{
	int val;
	std::shared_ptr<ListNode> next;
	ListNode() : val(), next(nullptr) {}
	ListNode(int v) : val(v), next(nullptr) {}
	ListNode(int v, std::shared_ptr<ListNode> n) : val(v), next(n) {}

	static std::shared_ptr<ListNode> from(std::vector<int> const & vec);
	std::vector<int> to_vec() const;
};

std::shared_ptr<ListNode> ListNode::from(std::vector<int> const & vec)
{
	if (vec.empty()) return nullptr;

	auto head = std::make_shared<ListNode>(vec.front());
	auto curr = head;
	for (auto it = std::next(vec.begin()); it != vec.end(); ++it)
	{
		curr->next = std::make_shared<ListNode>(*it);
		curr = curr->next;
	}
	return head;
}

std::vector<int> ListNode::to_vec() const
{
	std::vector<int> vec;
	auto curr = this;
	while (curr)
	{
		vec.emplace_back(curr->val);
		curr = curr->next.get();
	}
	return vec;
}