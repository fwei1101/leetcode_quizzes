#include "linked-list.hpp"

class Solution
{
public:
	std::shared_ptr<ListNode> operator()(std::shared_ptr<ListNode> head, int val)
	{
		auto dummy = std::make_shared<ListNode>(-1, head);
		auto prev = dummy, curr = head;
		while (curr)
		{
			if (curr->val == val)
			{
				prev->next = curr->next;
				curr = prev->next;
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
		return dummy->next;
	}
};