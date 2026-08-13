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
unordered_map<TreeNode*,int>pmp;
unordered_map<TreeNode*,int>smp;
ll  premake(TreeNode* root){
    if(!root) return INT_MIN;

ll lst=  premake(root->left);
   ll rst=premake(root->right);
   pmp[root]=lst;
   return max({lst,rst,(ll)root->val});
}
ll succmake(TreeNode* root){
    if(!root) return INT_MAX;
  
    ll lst=succmake(root->left);
    ll rst=succmake(root->right);
    smp[root]=rst;
    return min({(ll)root->val,lst,rst});
}
bool checkkar(TreeNode* root){
    if(!root) return true;

bool lst=checkkar(root->left);

bool rst= checkkar(root->right);

    
    if(root->left&&root->val<=pmp[root]) return false;
    if(root->right&&root->val>=smp[root]) return false;
    return lst&&rst;
}
    bool isValidBST(TreeNode* root) {
    if(!root) return true;
    ll x= premake(root);
   ll y= succmake(root);
   return checkkar(root);
    }
};
// [-2147483648,null,2147483647,-2147483647]