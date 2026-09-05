class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,INT_MAX));
    
   for(int i=0;i<=coins.size();i++) dp[i][0]=0;

    for(int i=1;i<=coins.size();i++){
        for(int j=1;j<=amount;j++){
        int skip=dp[i-1][j];
        int take=INT_MAX;
        if(j-coins[i-1]>=0) take=dp[i][j-coins[i-1]];
        if(take!=INT_MAX&&take<skip) dp[i][j]=1+min(take,skip);
        else dp[i][j]=skip;

        }
    }
    if(dp[coins.size()][amount]!=INT_MAX) return dp[coins.size()][amount];
    return -1;

    }
};