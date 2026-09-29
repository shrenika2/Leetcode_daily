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
        int n = lists.size();
        while(n > 1){
            int idx = 0 ;
            for (int i = 0 ; i < n ; i+=2){
                if(i+1  < n){
                lists[idx]=merge(lists[i], lists[i+1]);
                }else{
                    lists[idx]=lists[i];
                }
                idx++;
            }
            n = idx;
        }
        return lists[0];
    }
};