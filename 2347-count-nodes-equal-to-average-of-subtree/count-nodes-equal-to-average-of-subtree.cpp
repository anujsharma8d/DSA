/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL)
            return 0;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        int sum=0;
        for(int i:ans){
            sum+=i;
        }
        int avg=sum/ans.size();
        if(avg==ans[0]){
            return 1+averageOfSubtree(root->left)+averageOfSubtree(root->right);
        }

        return averageOfSubtree(root->left)+averageOfSubtree(root->right);
    }
};