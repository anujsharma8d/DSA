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
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        int n = 0;
        ListNode* temp=dummy;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        ListNode* temp1=head;
        ListNode* temp2=head;
        for(int i=1;i<k;i++){
            temp1=temp1->next;
        }
        for(int i=1;i<n-k;i++){
            temp2=temp2->next;
        }
        swap(temp1->val,temp2->val);
        return head;
        
    }
};