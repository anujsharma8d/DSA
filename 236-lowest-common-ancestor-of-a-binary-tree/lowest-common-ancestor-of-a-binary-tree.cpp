/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool lca(TreeNode* root,vector<TreeNode*>& arr, TreeNode* x){
        if(root==NULL){
            return false;
        }
        arr.push_back(root);
        if(root==x){
            return true;
        }
        if (lca(root->left,arr,x) || lca(root->right,arr,x)) return true;
        arr.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> first;
        vector<TreeNode*> second;
        lca(root,first,p);
        lca(root,second,q);
        TreeNode* ans;
        for(int i=0;i<min(first.size(), second.size());i++){
            if(first[i] == second[i])
        ans = first[i];
    else
        break;
        }
        return ans;
    }
};