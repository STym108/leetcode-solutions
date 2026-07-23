class Solution {
public:
int explore(vector<int>&prices,int idx,int state,int limit,vector<vector<vector<int>>>&dp){
    if(idx>=prices.size()||limit<=0) return 0;
    if(dp[idx][state][limit]!=-1) return dp[idx][state][limit];
    int take=0;
    int skip=0;  //not bought state=-1, bought state=1,sold state=0;
    if(state==0){
      take=-prices[idx]+explore(prices,idx+1,1,limit,dp);
    }
    if(state==1){
        take=prices[idx]+explore(prices,idx+1,0,limit-1,dp);
    }
    skip=explore(prices,idx+1,state,limit,dp);
    return dp[idx][state][limit]= max(take,skip);
}
    int maxProfit(vector<int>& prices) {
    // vector<vector<int>>(2,vector<int>(2,-1))
    vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(3,vector<int>(3,-1)));
    return explore(prices,0,0,2,dp);
    }
};