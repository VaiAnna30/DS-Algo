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
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    int dfs(TreeNode* node,int path){
        if(!node) return 0;
        path=path*10+node->val;
        if(node->left==nullptr&&node->right==nullptr) return path;
        return dfs(node->left,path)+dfs(node->right,path);
    }
};
/*
    1
   2 3
   nodes->left&nodes->right===nullptr
   add result to ans;
   else val+=(val*10)+node->val;
   when trace back val=val/10;
*/