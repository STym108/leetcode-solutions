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
int k=0;
int ans=0;
void getans(TreeNode* root,int x){
    if(!root) return ;
    if(k>=x) return;
    getans(root->left,x);
    k++;
    if(k==x){ ans=root->val;return;}
    getans(root->right,x);
}
    int kthSmallest(TreeNode* root, int x) {
    if(!root) return 0;

    getans(root,x);
    return ans;
    }
};