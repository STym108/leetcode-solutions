class Solution {
public:
bool getans(vector<int>& nums,int i,int t,vector<vector<int>>&dp){
    if(t==0) return true;
if(i<0||t<0) return false;
if(dp[i][t]!=-1) return dp[i][t];
bool take=false;
if(t-nums[i]>=0){
    take=getans(nums,i-1,t-nums[i],dp);
}
bool skip=getans(nums,i-1,t,dp);
return dp[i][t]= skip||take;
}
    bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++) sum+=nums[i];
    if(sum%2!=0) return false;
    int t=sum/2;
    vector<vector<int>>dp(nums.size(),vector<int>(t+1,-1));
    return getans(nums,nums.size()-1,t,dp);

    }
};