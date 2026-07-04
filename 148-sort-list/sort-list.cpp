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
    ListNode* sortList(ListNode* head) {
        vector<int> value;
        ListNode* node= head;
        if(head==NULL){
            return NULL;
        }
        while(node!=NULL){
            value.push_back(node->val);
            node=node->next;
        }
        sort(value.begin(),value.end());
        ListNode* ans = new ListNode(value[0]);
        ListNode* curr = ans;
        for(int i=1;i<value.size();i++){
            curr->next = new ListNode(value[i]);
            curr=curr->next;

        }
        return ans;
    }
};