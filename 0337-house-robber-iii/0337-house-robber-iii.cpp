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
int getans(TreeNode* root,unordered_map<TreeNode*,int>&mp){
    if(!root) return 0;
    int takeroot=root->val;
    if(mp.find(root)!=mp.end()) return mp[root];
    
    if(root->left) takeroot+=getans(root->left->left,mp)+getans(root->left->right,mp);
    if(root->right) takeroot+=getans(root->right->left,mp)+getans(root->right->right,mp);

    int skiproot=getans(root->left,mp)+getans(root->right,mp);

    return mp[root]= max(skiproot,takeroot);

}

    int rob(TreeNode* root) {
   unordered_map<TreeNode*,int>mp;
    return getans(root,mp);
    }
};