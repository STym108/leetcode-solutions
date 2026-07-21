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
unordered_map<TreeNode*,int>mp;
int findh(TreeNode* root){
    if(!root||!root->left&&!root->right) return 0;
    if(mp.find(root)!=mp.end()) return mp[root];
    int lst=findh(root->left);
    int rst=findh(root->right);
    return mp[root]= 1+max(lst,rst);
}
int maxdia=0;
int dfs(TreeNode* root){
if(!root) return 0;
    int lh=0;
    int rh=0;
    if(root->left) lh=1+findh(root->left);
    if(root->right) rh=1+findh(root->right);
    maxdia=max(maxdia,lh+rh);
    return max({dfs(root->left),dfs(root->right),maxdia});
}
    int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    dfs(root);
    return maxdia;
    }
};