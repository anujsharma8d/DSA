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
    void postOrder(TreeNode* root,int &sum,string &s){
        if(root==NULL){
            return;
        }
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            sum+=stoi(s);
        }
        postOrder(root->left,sum,s);
        postOrder(root->right,sum,s);
        s.pop_back();

    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        int sum = 0;
        postOrder(root,sum,s);
        return sum;
    }
};