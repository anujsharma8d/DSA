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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp1 = dummy;
        ListNode* temp2 = head;
        int idx1=0;
        int idx2=1;
        while(idx1!=left-1){
            temp1=temp1->next;
            idx1++;
        }
        while(idx2!=right){
            temp2=temp2->next;
            idx2++;
        }
        ListNode* after = temp2->next;
        ListNode* prev=after;
        ListNode* curr=temp1->next;
        while(curr!=after){
            ListNode* save = curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
        }
        temp1->next=prev;
        return dummy->next;

    }
};