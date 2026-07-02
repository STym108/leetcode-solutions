class Solution {
public:
typedef vector<int>pr;
    int swimInWater(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();
    priority_queue<pr,vector<pr>,greater<pr>>pq;
    pq.push({grid[0][0],0,0});
 vector<vector<int>>mint(r,vector<int>(c,INT_MAX));
 mint[0][0]=grid[0][0];
vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
while(pq.size()){
vector<int>temp=pq.top();pq.pop();
int timesofar=temp[0];
int i=temp[1];
int j=temp[2];
for(int k=0;k<4;k++){
    int idx=i+dir[k][0];
    int jdx=j+dir[k][1];
    if(idx>=0&&idx<r&&jdx>=0&&jdx<c){
        int finaltime=max(timesofar,grid[idx][jdx]);
        if(mint[idx][jdx]>finaltime){
            mint[idx][jdx]=finaltime;
            pq.push({finaltime,idx,jdx});
        }
    }
}
}
return mint[r-1][c-1];

    }
};