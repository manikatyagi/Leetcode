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
    ListNode* swapNodes(ListNode* head, int k) {
       
        ListNode* right=head,*left=head;
        
        for(int i=0;i<k-1;i++){
            //cout<<right->val<<" ";
            right=right->next;
            
        }
        
        ListNode* start=right;
        
        while(right->next){
            right=right->next;
            left=left->next;
        }
        
        swap(start->val,left->val);
        
        return head;
    }
};