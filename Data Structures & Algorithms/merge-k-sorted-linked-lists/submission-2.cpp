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
	// Главная функция, которую вызывает система
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty())
		{
			return nullptr;
		}

		 return devide(lists, 0, lists.size() - 1);
		

	}

private:
	ListNode* devide(vector<ListNode*>& lists, int l, int r)
	{
		if (l > r)
		{
			return nullptr;
		}
		if (l == r)
		{
			return lists[l];
		}

		int mid = l + (r - l) / 2;

		ListNode* left = devide(lists, l, mid);
		ListNode* right = devide(lists, mid + 1, r);

		return merge(left, right);
	}
	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		ListNode temp(0);
		ListNode *curr = &temp;

		while (l1 && l2)
		{
			if (l1->val <= l2->val)
			{
				curr->next = l1;
				l1 = l1->next;
			}
			else
			{
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}

		if (l1)
		{
			curr->next = l1;
		}
		else if (l2)
		{
			curr->next = l2;
		}
		return temp.next;
	}

};