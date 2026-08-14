class Solution {
public:
void kahns(vector<vector<int>>&adj,int node,vector<int>&ans,vector<int>&ind){
    queue<int>q;
    q.push(node);
    while(q.size()){
    int fn=q.front();q.pop();
    ans.push_back(fn);
    for(auto neighb:adj[fn]){
        ind[neighb]--;
        if(ind[neighb]==0) q.push(neighb);
    }
    }
}
    vector<int> findOrder(int n, vector<vector<int>>& grid) {
    vector<int>ind(n,0);
    vector<vector<int>>adj(n);
    for(int i=0;i<grid.size();i++){
        int u=grid[i][1];
        int v=grid[i][0];
        adj[u].push_back(v);
        ind[v]++;
    }
    vector<int>ans;
    vector<int>q;
    for(int i=0;i<n;i++){
        if(ind[i]==0) q.push_back(i);
    }
    for(int i=0;i<q.size();i++){
     kahns(adj,q[i],ans,ind);
    }
    return ans.size()==n?ans:vector<int>{};

    }
};