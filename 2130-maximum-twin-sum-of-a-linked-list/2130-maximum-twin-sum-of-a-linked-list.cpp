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
    ListNode* reverse(ListNode* head){
        ListNode* prev=0;
        ListNode* curr=head,*nextnode=head;
        
        while(nextnode!=0){
            nextnode=nextnode->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        
       // head=prev;
        
        return prev;
            
    }
    int pairSum(ListNode* head) {
        
       ListNode* slow=head,*fast=head;
        
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* rev=reverse(slow);
        int ans=0;
        while(rev){
            ans=max(ans,rev->val+head->val);
            
            rev=rev->next;
            head=head->next;
        }
        return ans;
    }
};