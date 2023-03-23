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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head)
            return NULL;
        else if(!head->next)
            return head;
        ListNode* curr = head;
        ListNode* odd;
        ListNode* even;
        ListNode* even_start;
        int cnt = 1;
        while(1)
        {
            if(cnt == 1)
                odd = curr;
            else if(cnt == 2)
            {
                even = curr;
                even_start = curr;
            }
            else if (cnt % 2 == 1)
            {
                odd->next = curr;
                odd = odd->next;
            }
            else
            {
                even->next = curr;
                even = even->next;
            }
            cnt++;
            if(curr->next)
                curr = curr->next;
            else
            {
                even->next = NULL;
                odd->next = even_start;
                break;
            }
        }
        return head;
    }
};