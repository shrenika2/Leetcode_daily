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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;

        ListNode* slow = head;
        ListNode* fast = head;
//mid
        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
// reverse
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev ;
            prev = curr ;
            curr = temp ;
        }

        ListNode* first = head ;
        ListNode* second = prev ;
// merge
        while(second){
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1 ;
            second = t2 ;
        }

    }
};