/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution 
{
public:
	void reorderList(ListNode* head) 
	{
		ListNode *slow = head;
		ListNode *fast = head->next;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* cntr = slow->next;
		slow->next = nullptr;
		ListNode* prev = nullptr;

		while (cntr)
		{
			ListNode* temp = cntr->next;
			cntr->next = prev;
			prev = cntr;
			cntr = temp;
		}

		ListNode* first = head;
		cntr = prev;
		while (cntr)
		{
			ListNode* temp1 = first->next;
			ListNode* temp2 = cntr->next;
			first->next = cntr;
			cntr->next = temp1;
			first = temp1;
			cntr = temp2;
		}
		
	}
};

