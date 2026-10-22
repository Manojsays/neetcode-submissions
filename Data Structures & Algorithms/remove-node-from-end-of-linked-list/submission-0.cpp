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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        if(n > cnt)return NULL;

        int required = cnt - n;
        ListNode* prev = NULL;
        temp = head;

        if(required == 0)return head->next;
        while(required--){
            prev = temp;
            temp = temp->next;
        }
        if(temp->next)prev->next = temp->next;
        else prev->next = NULL;

        return head;
    }
};
