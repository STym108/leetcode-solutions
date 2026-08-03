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
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
vector<int> ahead1(2,0); // dp[i+1]
vector<int> ahead2(2,0); // dp[i+2]

    for(int i=n-1;i>=0;i--){
    vector<int>curr(2,0);
    for(int j=1;j>=0;j--){
        if(j==1){
          curr[j]=max(-prices[i]+ahead1[0],ahead1[j]);
          
        }
        else{
        curr[j]=max(prices[i]+ahead2[1],ahead1[j]);
        }

    }
    ahead2=ahead1;
    ahead1=curr;

    }

   return ahead1[1];
    
    }
};