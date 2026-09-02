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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int extra = count%k;
        int size=count/k;
        temp=head;
        int c=0;
        for(int i=0;i<k;i++){
            ListNode* part=temp;
            int partSize=size;
            if(extra>0){
                partSize++;
                extra--;
            }
            for(int j=1;j<partSize;j++){
                temp=temp->next;
            }
            if(temp!=NULL) {
                ListNode* nextPart=temp->next;
                temp->next=NULL;
                temp=nextPart;
            }

            ans.push_back(part);
            
        }
        return ans;
    }
};