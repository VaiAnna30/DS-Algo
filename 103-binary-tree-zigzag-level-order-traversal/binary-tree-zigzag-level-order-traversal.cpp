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
    void levelorder(TreeNode* root,vector<vector<int>>&level){
        if(root==nullptr) return;
        queue<TreeNode*>s;
        s.push(root);
        int type=0;
        while(!s.empty()){
            int n=s.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode* node=s.front();
                s.pop();
                temp.push_back(node->val);
                if(node->left!=nullptr)s.push(node->left);
                if(node->right!=nullptr)s.push(node->right);
            }
            if(type%2==1)reverse(temp.begin(),temp.end());
            level.push_back(temp);
            type++;
        }
    }


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>level;
        levelorder(root,level);
        return level;
    }
};