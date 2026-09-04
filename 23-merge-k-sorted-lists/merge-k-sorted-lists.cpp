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
    ListNode* mergeTwoLinkedLists(ListNode* l1,ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<=l2->val){
            l1->next = mergeTwoLinkedLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLinkedLists(l1,l2->next);
            return l2;
        }
    }

    ListNode* SplitAndSolve(int st,int end,vector<ListNode*>& lists){
        if(st>end){
            return NULL;
        }
        if(st==end){
            return lists[st];
        }
        int mid = st+(end-st)/2;
        ListNode* L1 = SplitAndSolve(st,mid,lists);
        ListNode* L2 = SplitAndSolve(mid+1,end,lists);

        return mergeTwoLinkedLists(L1,L2);
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int st=0;
        int end=lists.size()-1;
        if(lists.size()==0){
            return NULL;
        }
        return SplitAndSolve(st,end,lists);
    }
};