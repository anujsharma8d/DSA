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
    void helper(TreeNode* root, int targetSum,vector<vector<int>> &ans,vector<int> &path){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum==root->val){
                ans.push_back(path);
            }
        }
        targetSum-=root->val;
        helper(root->left,targetSum,ans,path);
        helper(root->right,targetSum,ans,path);
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root,targetSum,ans,path);
        return ans;

    }
};