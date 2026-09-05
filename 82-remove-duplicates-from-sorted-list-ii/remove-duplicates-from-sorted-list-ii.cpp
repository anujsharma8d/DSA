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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            bool duplicate=false;
            while(temp!=NULL && curr->val==temp->val){
                duplicate = true;
                temp=temp->next;
            }
            if(duplicate){
                prev->next=temp;
            }
            else{
                prev=curr;
            }
            curr=temp;
        }
        return dummy->next;
    }
};