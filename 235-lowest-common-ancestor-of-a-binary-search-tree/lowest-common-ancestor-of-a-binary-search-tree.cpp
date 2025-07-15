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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return root;

        int value=root->val;
        int x=p->val;
        int y=q->val;

        if(value<x&&value<y){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(value>x&&value>y){
            return lowestCommonAncestor(root->left,p,q);
        }
        else return root;
        
    }
};