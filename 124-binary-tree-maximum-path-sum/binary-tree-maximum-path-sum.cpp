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
    int maxi=INT_MIN;
    int Sum(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftt=0,rightt=0;
        if(root->left!=nullptr)leftt=max(0,Sum(root->left));
        if(root->right!=nullptr)rightt=max(0,Sum(root->right));
        maxi=max(maxi,leftt+rightt+root->val);
        return root->val+max(leftt,rightt);
    }
    int maxPathSum(TreeNode* root){
        int val=Sum(root);
        return maxi;
    }
};