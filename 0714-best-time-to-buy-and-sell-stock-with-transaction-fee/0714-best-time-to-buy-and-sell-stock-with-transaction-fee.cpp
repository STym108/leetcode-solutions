class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    vector<int>after(2,0);
    int n=prices.size();
    for(int i=n-1;i>=0;i--){
        vector<int>curr(2,0);
        for(int j=1;j>=0;j--){
          if(j==0){
            curr[j]=max(-prices[i]+after[1],after[j]);
          }
          else{
            curr[j]=max(prices[i]-fee+after[0],after[j]);
          }
        }
        after=curr;
    }
    return after[0];

    }
};