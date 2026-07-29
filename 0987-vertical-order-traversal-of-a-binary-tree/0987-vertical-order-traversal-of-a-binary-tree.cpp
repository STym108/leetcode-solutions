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
typedef pair<int,int>pr;
int mincol=1001;
void dfs(TreeNode* &root,int i,int j,unordered_map<int,vector<pr>>&mp){
    if(!root) return ;
    mp[j].push_back({i,root->val});
    mincol=min(mincol,j);
    dfs(root->left,i+1,j-1,mp);
    dfs(root->right,i+1,j+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      unordered_map<int,vector<pr>>mp;
      dfs(root,0,0,mp);
      vector<vector<pr>>ans;
      int col=mincol;
      while(mp.find(col)!=mp.end()){
        ans.push_back(mp[col]);
        col++;
      }
      //sorted by col, now sorting by row the if row equal :sort by value
    //   sort(ans.begin(),ans.end(),[](const vector<pr>&a,const vector<pr>&b){
    //   return (a.first<b.first||a.first==b.first&&a.second<b.second);
    //   });
    // sort(ans.begin(),ans.end());
    vector<vector<int>>v;
    for(int i=0;i<ans.size();i++){
        vector<int>temp;
    sort(ans[i].begin(),ans[i].end());
    for(int j=0;j<ans[i].size();j++){
    temp.push_back(ans[i][j].second);
    }

    v.push_back(temp);
    }
    return v;

    }
};