#pragma once

#include <memory>

struct ListNode
{
	int val;
	std::shared_ptr<ListNode> next;
	ListNode() : val(), next(nullptr) {}
	ListNode(int v) : val(v), next(nullptr) {}
	ListNode(int v, std::shared_ptr<ListNode> n) : val(v), next(n) {}
};