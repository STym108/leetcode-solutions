class Solution {
public:
void getans(vector<int>& nums,int idx,vector<int>&temp,vector<vector<int>>&ans){

    for(int i=idx;i<nums.size();i++){
       if(i>idx&&nums[i]==nums[i-1]) continue;
      else  {temp.push_back(nums[i]);
        getans(nums,i+1,temp,ans);
        temp.pop_back();}
    }
    ans.push_back(temp);
    return ;
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<vector<int>>ans;
   vector<int>temp={};
    getans(nums,0,temp,ans);

    return ans;
    }
};