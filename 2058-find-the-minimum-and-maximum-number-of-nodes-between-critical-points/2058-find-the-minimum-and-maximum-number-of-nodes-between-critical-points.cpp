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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head ;
        ListNode* curr = head->next;

        int i = 1 ;
        int prevpos = 0 ;
        int firstpos = 0 ;

        int minDist = INT_MAX;

        while(curr->next != NULL){
            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val) ){
                if(prevpos == 0){
                    prevpos = i ;
                    firstpos =  i;
                }else{
                    minDist = min(minDist , i - prevpos);
                    prevpos = i ;
                }
            }
            i++;
            prev = curr ;
            curr = curr->next ;
        }
        if(minDist== INT_MAX){
            return {-1 , -1};
        }
        return {minDist , prevpos - firstpos};
    }
};