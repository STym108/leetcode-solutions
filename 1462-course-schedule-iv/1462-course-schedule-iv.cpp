class Solution {
public:
void bfs(vector<vector<int>>&adj,int n,vector<int>&inw,vector<int>&sorted){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(inw[i]==0){ q.push(i); sorted.push_back(i);}
    }
    while(q.size()>0){
    int f=q.front(); q.pop();
    for(auto neighb:adj[f]){
        inw[neighb]--;
        if(inw[neighb]==0){
            q.push(neighb);
            sorted.push_back(neighb);
        }
    }
    }

}
int findpar(vector<int>&par,int u){
    if(par[u]==u) return u;
    return par[u]=findpar(par,par[u]);
}

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
    vector<vector<int>>adj(n);
    vector<int>par(n);
    for(int i=0;i<n;i++) par[i]=i;
    vector<int>inw(n,0);
    for(int i=0;i<pre.size();i++){
        int u=pre[i][0];
        int v=pre[i][1];
        int upar=findpar(par,u);
        int vpar=findpar(par,v);
        par[vpar]=upar;
        adj[u].push_back(v);
        inw[pre[i][1]]++;
    }

    vector<int>sorted;
    
    bfs(adj,n,inw,sorted);
    unordered_map<int,int>mp;
    for(int i=0;i<sorted.size();i++){
        mp[sorted[i]]=i;
    }
    
    vector<bool>ans(q.size(),false);
    for(int k=0;k<q.size();k++){
     int i=mp[q[k][0]];
    int j=mp[q[k][1]];
    int ipar=findpar(par,q[k][0]);
    int jpar=findpar(par,q[k][1]);

     if(ipar==jpar){
    if(i<j) ans[k]=true;

    }
    }

    return ans;
    
    }
};