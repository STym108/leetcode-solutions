class Solution {
public:
int countfun(vector<int>& nums, int t,vector<int>&dp){
if(t==0) return 1;
if(t<0) return 0;
if(dp[t]!=-1) return dp[t];
int take=0;
int skip=0;

for(int i=0;i<nums.size();i++){
 if(t-nums[i]>=0) take+=countfun(nums,t-nums[i],dp);
}

return dp[t]= take;
}
    int combinationSum4(vector<int>& nums, int target) {
    vector<int>dp(target+1,-1);
    return countfun(nums,target,dp);
    
    }
};