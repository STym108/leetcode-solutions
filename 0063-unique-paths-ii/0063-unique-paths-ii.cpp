class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();
    vector<vector<int>>dp(r,vector<int>(c,0));
   if(grid[0][0]==0) dp[0][0]=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==0){
                if(i-1>=0){
               if(grid[i-1][j]!=1) { dp[i][j]+=dp[i-1][j];}
                }
                if(j-1>=0){
            if(grid[i][j-1]!=1)  dp[i][j]+=dp[i][j-1];
                }
            }
        }
    }

    return dp[r-1][c-1];

    }
};