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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head ;
        for (int i = 0 ; i < k ; i++){
            if(curr == nullptr) return head ;
            curr = curr->next;
        }
        ListNode* temp = head ;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for (int i = 0 ; i < k ; i++){
            nxt = temp->next ;
            temp->next = prev ;
            prev = temp ;
            temp = nxt ;
        }
        head->next = reverseKGroup(temp , k);
        return prev ;
        
    }
};