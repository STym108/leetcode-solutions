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
void attach(TreeNode* root,int x){
    if(!root) return ;
    if(root->val<x){
     if(root->right) attach(root->right,x);
     else{
        TreeNode* nnode=new TreeNode(x);
        root->right=nnode; return;
     }
    }
    if(root->val>x){
    if(root->left) attach(root->left,x);
    else{
     TreeNode* nnode=new TreeNode(x);
        root->left=nnode; return;
    }
    }
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root){
        TreeNode* nnode=new TreeNode(val); return nnode;
    }
    attach(root,val);
    return root;
    }
};