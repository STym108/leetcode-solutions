class Solution {
public:
int explore(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
    if(i>=grid.size()||i<0||j>=grid[0].size()||j<0||grid[i][j]==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int r=explore(grid,i,j-1,dp);
    int d=explore(grid,i-1,j-1,dp);
    int b=explore(grid,i-1,j,dp);
    return dp[i][j]= 1+min({r,d,b});
}

    int countSquares(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();

    vector<vector<int>>dp(r+1,vector<int>(c+1,0));

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
       if(grid[i-1][j-1]==1){
        dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
       }
        }
        }
    
     int ans=0;
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++) ans+=dp[i][j];
    }
    return ans;
    }
};