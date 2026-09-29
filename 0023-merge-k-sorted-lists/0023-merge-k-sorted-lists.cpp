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
    ListNode* merge(ListNode* a , ListNode* b){
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(a && b){
            if(a->val<=b->val){
                temp->next = a;
                a = a->next;
            }else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        while(a){
            temp->next = a ;
            a = a->next;
            temp = temp->next;
        }
        while(b){
            temp->next = b ;
            b = b->next;
            temp = temp->next;
        }
        return dummy.next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* ans = lists[0];
        for (int i = 1 ; i < lists.size() ; i++){
            ans = merge(ans , lists[i]);
        }
        return ans ;
    }
};