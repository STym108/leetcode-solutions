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
int maxst(TreeNode* root){
    if(!root) return 0;
    if(mp.find(root)!=mp.end()) return mp[root];
    int lst=maxst(root->left);
    int rst=maxst(root->right);
    int stans=max(lst,rst);
    int r=root->val;
    if(r+stans>0) return mp[root]=r+stans;
    else if(r>0) return r;
    return 0;
}
int ans=INT_MIN;
void findans(TreeNode* root){
     if(!root) return;
     ans=max(ans,root->val+maxst(root->left)+maxst(root->right));
     findans(root->left);
     findans(root->right);
}
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        findans(root);
        if(ans!=INT_MIN) return ans;
        return 0;
    }
};