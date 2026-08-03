class Solution {
public:
int getans(vector<int>&prices,int idx,int state, vector<vector<int>>&dp){
    if(idx>=prices.size()) return 0;
    if(dp[idx][state]!=-1) return dp[idx][state];
   //state=1 : can purchase , state =0 :cant purchse ,can only sell
   int take=0;
    if(state==1){
    take=-prices[idx]+getans(prices,idx+1,0,dp);
    }
    else{
        take=prices[idx]+getans(prices,idx+2,1,dp);
    }
    int skip=getans(prices,idx+1,state,dp);


    return dp[idx][state]= max(take,skip);

}

    int maxProfit(vector<int>& prices) {
    vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
    return getans(prices,0,1,dp);
    
    }
};