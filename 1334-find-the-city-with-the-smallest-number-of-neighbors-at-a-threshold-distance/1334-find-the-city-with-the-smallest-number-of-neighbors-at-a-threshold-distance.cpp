class Solution {
public:
typedef pair<int,int>pr;
int checkit(vector<vector<pair<int,int>>>& adj,int node,int dt,vector<int>&dis){
priority_queue<pr,vector<pr>,greater<pr>>pq;
pq.push({0,node});
dis[node]=0;

while(pq.size()){
pr f=pq.top();pq.pop();
int sofardis=f.first;
int fnode=f.second;
for(auto neighbpr:adj[fnode]){
    int totaldis=sofardis+neighbpr.second;
    int neighb=neighbpr.first;
    if(totaldis<=dt&&totaldis<dis[neighb]){

    dis[neighb]=totaldis;
    pq.push({totaldis,neighb});
    }
}
}
int count=0;
for(int i=0;i<dis.size();i++){
    if(i!=node&&dis[i]!=INT_MAX) count++;
}
return count;
}
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        vector<int>dis(n,INT_MAX);
        v[i]=checkit(adj,i,dt,dis);
    }
    int maxcities=INT_MAX;
    int maxele=-1;

    for(int i=0;i<n;i++){
       if(v[i]<maxcities){ maxcities=v[i];}
    }
    
   for(int i=0;i<n;i++){
    if(v[i]==maxcities) maxele=max(maxele,i);
    }
return maxele;
        
    }
};