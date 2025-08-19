#include "linked-list.hpp"

class Solution
{
public:
	std::shared_ptr<ListNode> operator()(std::shared_ptr<ListNode> head, int n)
	{
		auto dummy = std::make_shared<ListNode>(-1, head);
		auto slow = dummy, fast = head;
		for (int i = 0; i < n; i++)
		{
			if (fast)
			{
				fast = fast->next;
			}
			else
			{
				return head;
			}
		}
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		auto next = slow->next->next;
		slow->next.reset();
		slow->next = next;
		return dummy->next;
	}
};