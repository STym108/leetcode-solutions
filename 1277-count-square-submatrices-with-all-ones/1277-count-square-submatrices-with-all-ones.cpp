class Solution {
public:


    int countSquares(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();

     vector<int>prev(c+1,0);
     int ans=0;
    for(int i=1;i<=r;i++){
        vector<int>curr(c+1,0);
        for(int j=1;j<=c;j++){
       if(grid[i-1][j-1]==1){
        curr[j]=1+min({prev[j],curr[j-1],prev[j-1]});
        ans+=curr[j];
       }
        }
        prev=curr;
        }
    
    //  int ans=0;
    // for(int i=0;i<=r;i++){
    //     for(int j=0;j<=c;j++) ans+=dp[i][j];
    // }
    return ans;
    }
};