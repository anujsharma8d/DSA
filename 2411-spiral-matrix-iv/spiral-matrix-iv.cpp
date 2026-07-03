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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int rowst=0;
        int colst=0;
        int rowend=m-1;
        int colend=n-1;
        ListNode* node = head;
        while(rowst<=rowend && colst<=colend){
            for(int i=colst;i<=colend;i++){
                if(node==NULL){
                    break;
                }
                ans[rowst][i]=node->val;
                node=node->next;
            }
            rowst++;
            for(int j=rowst;j<=rowend;j++){
                    if(node==NULL){
                    break;
                }
                ans[j][colend]=node->val;
                node=node->next;
            }
            colend--;
            for(int i=colend;i>=colst;i--){
                    if(node==NULL){
                    break;
                }
                ans[rowend][i]=node->val;
                node=node->next;
            }
            rowend--;
            for(int j=rowend;j>=rowst;j--){
                    if(node==NULL){
                    break;
                }
                ans[j][colst]=node->val;
                node=node->next;
            }
            colst++;
        }  
        return ans;
    }
};