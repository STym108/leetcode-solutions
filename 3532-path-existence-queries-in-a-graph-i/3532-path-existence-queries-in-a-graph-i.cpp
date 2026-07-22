class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxdiff, vector<vector<int>>& q) {
    vector<bool>ans(q.size());
    vector<int>par(n,0);
    for(int i=0;i<n;i++) par[i]=i;
    for(int i=1;i<n;i++){
    if(nums[i]-nums[i-1]<=maxdiff) par[i]=par[i-1];
    }
    for(int i=0;i<q.size();i++){
        int u=q[i][0];
        int v=q[i][1];
        if(par[u]==par[v]) ans[i]=true;
        else ans[i]=false;
    }
    return ans;
    }
};