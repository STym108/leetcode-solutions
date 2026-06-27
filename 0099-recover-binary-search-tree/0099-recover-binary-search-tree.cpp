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
typedef long long int ll;
void dfs(TreeNode* root,vector<TreeNode*>&v){
     if(!root) return;
     dfs(root->left,v);
          v.push_back(root);
     dfs(root->right,v);
}
    void recoverTree(TreeNode* root) {
    vector<TreeNode*>v;
    dfs(root,v);
    int maxi=INT_MIN;
    int lidx=-1;
    int ridx=-1;
    int lf=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]->val<maxi){
        ridx=i;
        lf=lidx;
        }
        else if(v[i]->val>maxi){
            maxi=v[i]->val;
            lidx=i;
        }
    }
    int x=v[lf]->val;
    v[lf]->val=v[ridx]->val;
    v[ridx]->val=x;
    
    }
};