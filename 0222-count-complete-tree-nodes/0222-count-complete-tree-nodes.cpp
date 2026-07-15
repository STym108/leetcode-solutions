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
int getleftheight(TreeNode* root){
    if(!root) return 0;
    TreeNode* temp=root;
    int x=0;
    while(temp){x++;temp=temp->left;}
    return x;
}
int getrightheight(TreeNode* root){
    if(!root) return 0;
    TreeNode* temp=root;
    int x=0;
    while(temp){x++;temp=temp->right;}
    return x;
}
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lst=getleftheight(root);
        int rst=getrightheight(root);
        if(lst==rst) return pow(2,lst) -1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};