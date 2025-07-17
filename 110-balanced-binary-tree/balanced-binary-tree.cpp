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
    int check(TreeNode* root,bool &checks){
        if(root==nullptr) return 0;
        int leftt=0,rightt=0;
        if(root->left!=nullptr)leftt=check(root->left,checks);
        if(root->right!=nullptr)rightt=check(root->right,checks);
        if(abs(leftt-rightt)>1)checks=false;
        return 1+max(leftt,rightt);
    }
    bool isBalanced(TreeNode* root) {
        bool checks=true;
        int val=check(root, checks);
        return checks;
    }
};