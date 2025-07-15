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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode* newnode=new TreeNode(val);
            return newnode;
        }
        if(root->val<val){
            if(root->right==nullptr){
                TreeNode* node=new TreeNode(val);
                root->right=node;
                return root;
            }
            TreeNode* nnode=insertIntoBST(root->right,val);
        }else if(root->val>val){
            if(root->left==nullptr){
                TreeNode* node=new TreeNode(val);
                root->left=node;
                return root;
            }
            TreeNode* nnode=insertIntoBST(root->left,val);
        }
        return root;
    }
};