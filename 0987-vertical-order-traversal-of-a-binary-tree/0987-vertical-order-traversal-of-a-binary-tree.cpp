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
   unordered_map<int, vector<vector<int>>> mp;
   void makemap(TreeNode* root,int r,int c){
   if(!root) return ;
   mp[c].push_back({c,r,root->val});
   makemap(root->left,r+1,c-1);
   makemap(root->right,r+1,c+1);
   }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    
    makemap(root,0,0);
     vector<vector<int>>ans;
    for(auto vp:mp){
    vector<vector<int>>v=vp.second;
        sort(v.begin(),v.end(),[](const vector<int>&a,const vector<int>&b){
        if(a[1]==b[1]) return a[2]<b[2];
        else return a[1]<b[1];
        return false;
        });
        vector<int>temp;
        for(int i=0;i<v.size();i++){
            temp.push_back(v[i][2]);
        }
        temp.push_back(vp.first);
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end(),[](const vector<int>&a,const vector<int>&b){
    return a[a.size()-1]<b[b.size()-1];
    });
    for(int i=0;i<ans.size();i++){
        ans[i].pop_back();
    }
    return ans;
   
    }
};