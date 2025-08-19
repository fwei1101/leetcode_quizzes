#include "linked-list.hpp"

class Solution
{
public:
	std::shared_ptr<ListNode> operator()(std::shared_ptr<ListNode> head)
	{
		if (head == nullptr)
		{
			return head;
		}

		decltype(head) prev = nullptr;
		auto curr = head;

		while (curr)
		{
			auto next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		return prev;
	}
};