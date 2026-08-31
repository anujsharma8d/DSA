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
        vector<int> idx;
        int temp=head->val;
        ListNode* ptr=head->next;
        int i=1;
        while(ptr->next!=NULL){
            int value1 = ptr->val;
            if((temp>value1 && ptr->next->val>value1) || (temp<value1 && ptr->next->val<value1)){
                idx.push_back(i);
            }
            temp=value1;
            ptr=ptr->next;
            i++;
        }
        int mini=INT_MAX;
        if (idx.size() < 2) {
            return {-1, -1};
        }
        vector<int> ans;
        for(int i=0;i<idx.size()-1;i++){
            mini=min(mini,idx[i+1]-idx[i]);
        }
        ans.push_back(mini);
        ans.push_back(idx[idx.size()-1]-idx[0]);
        return ans;
    }
};