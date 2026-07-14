class Solution {
public:
bool checkit(vector<vector<int>>& adj,int currnode,vector<int>&colour,vector<bool>&visit){
    visit[currnode]=true;
    bool ans=true;
    for(auto child:adj[currnode]){
        if(colour[child]==colour[currnode]) return false;
        if(!visit[child]) ans=ans&&checkit(adj,child,colour,visit);
    }
    return ans;
}
void colournodes(vector<vector<int>>& adj,int n,vector<int>&colour){
   queue<pair<int,int>>q;
    q.push({n,0});
    while(q.size()){
        pair<int,int>pr=q.front();q.pop();
        int parcolour=pr.second;
        int currcolour=0;
        if(parcolour==0) currcolour=1;
        int fnode=pr.first;
        for(auto neighb:adj[fnode]){
            if(colour[neighb]==-1){
                colour[neighb]=currcolour;
                q.push({neighb,currcolour});
            }
        }
    }
}
    bool isBipartite(vector<vector<int>>& adj) {
    int n=adj.size();
    // vector<bool>visit(n,false);
    vector<int>colour(n,-1);
    //0=yellow
    //1=blue
    for(int i=0;i<n;i++){
        if(colour[i]==-1) colournodes(adj,i,colour);
    }
    vector<bool>visit(n,false);
    bool ans=true;
    for(int i=0;i<n;i++){
        if(!visit[i]) ans=ans&&checkit(adj,i,colour,visit);
    }
    return ans;

    }
};