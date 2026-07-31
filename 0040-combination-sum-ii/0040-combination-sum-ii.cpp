class Solution {
public:
void getans(vector<int>& nums,int idx,int t,vector<int>&temp,vector<vector<int>>&ans){
    if(t==0){
        ans.push_back(temp);
        return ;
    }
    for(int i=idx;i<nums.size();i++){
        if(t-nums[i]<0) return;
        if(i>idx&&nums[i]==nums[i-1]) continue;
        temp.push_back(nums[i]);
        getans(nums,i+1,t-nums[i],temp,ans);
        temp.pop_back();
    }
    return;

}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    vector<int>temp={};
    getans(nums,0,target,temp,ans);
return ans;

    }
};