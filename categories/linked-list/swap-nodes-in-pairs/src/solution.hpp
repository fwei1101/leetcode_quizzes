#include "linked-list.hpp"

class Solution
{
public:
	std::shared_ptr<ListNode> operator()(std::shared_ptr<ListNode> head)
	{
		auto dummy = std::make_shared<ListNode>(-1, head);
		auto prev = dummy, curr = head;
		
		while (curr && curr->next)
		{
			auto next = curr->next->next;
			prev->next = curr->next;
			prev->next->next = curr;
			curr->next = next;
			prev = curr;
			curr = next;
		}

		return dummy->next;
	}
};