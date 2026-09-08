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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* temp1=dummy;
        ListNode* temp2=dummy;
        while(temp1->next!=NULL && temp1->next->val<x){
            temp1=temp1->next;
        }
        temp2=temp1;
        while(temp1->next!=NULL){
            if(temp1->next->val<x){
                ListNode* ptr=temp1->next;
                temp1->next=ptr->next;
                ptr->next=temp2->next;
                temp2->next=ptr;
                temp2=temp2->next;
            }
            else{
                temp1=temp1->next;
            }
        }
        return dummy->next;
    }
};