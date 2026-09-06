class Solution {
public:
int getans(vector<int>&nums,int l,int r,vector<int>&pre,vector<int>&suf,vector<vector<int>>&dp){
    if(r>=nums.size()||l<0||l>r||l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int thismax=0;
    for(int i=l;i<r;i++){
    int lp=l-1;
    int rn=r+1;
    if(lp<0) lp=0;
    else lp=pre[l-1];
    if(rn>=nums.size()) rn=0;
    else rn=suf[r+1]; 
 
    int leftsum=pre[i]-lp;
    int rightsum=suf[i+1]-rn;
    if(leftsum>rightsum) thismax=max(thismax,rightsum+getans(nums,i+1,r,pre,suf,dp));
  else  if(leftsum<rightsum) thismax=max(thismax,leftsum+getans(nums,l,i,pre,suf,dp));
  else{
     thismax=max(thismax,rightsum+getans(nums,i+1,r,pre,suf,dp));
     thismax=max(thismax,leftsum+getans(nums,l,i,pre,suf,dp));
  }
    }

    return dp[l][r]= thismax;
}
    int stoneGameV(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        pre[0]=nums[0];

        suf[n-1]=nums[n-1];
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];
        for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+nums[i];

        return getans(nums,0,nums.size()-1,pre,suf,dp);

    }
};