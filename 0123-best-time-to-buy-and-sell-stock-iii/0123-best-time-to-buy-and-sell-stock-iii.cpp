class Solution {
public:

    int maxProfit(vector<int>& prices) {
    // vector<vector<int>>(2,vector<int>(2,-1))
    vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
    int n=prices.size();
vector<vector<int>>after(2,vector<int>(3,0));
vector<vector<int>>curr(2,vector<int>(3,0));
    for(int i=n-1;i>=0;i--){
    for(int buy=0;buy<=1;buy++){
    for(int limit=2;limit>=1;limit--){
        if(buy==1){
            curr[buy][limit]= max(-prices[i]+after[0][limit],after[buy][limit]);
        }
        else if(buy==0){
            curr[buy][limit]=max(prices[i]+after[1][limit-1],after[buy][limit]);
        }
    }
    }
    after=curr;
    }
    return curr[1][2];
    }
};