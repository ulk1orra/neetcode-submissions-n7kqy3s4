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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
      ListNode *dummy = new ListNode(0, head);
      ListNode *prevGroup = dummy;
      

      while (true)
      {
        ListNode *kth = searchKGroup(prevGroup, k);
        if (!kth)
        {
          break;
        }


        ListNode *grpNext = kth->next;

        ListNode *prev = kth->next;
        ListNode *curr = prevGroup->next;

        while (curr != grpNext)
        {
          ListNode *temp = curr->next;
          curr->next = prev;
          prev = curr;
          curr = temp;

        }
        ListNode *tmp = prevGroup->next;
        prevGroup->next = kth;
        prevGroup = tmp;
      }
      return dummy->next;
    }

private:
    ListNode *searchKGroup(ListNode *curr, int k)
    {
      while (curr && k>0)
      {
        curr = curr->next;
        k--;
      }
      return curr;
    }
    
};




