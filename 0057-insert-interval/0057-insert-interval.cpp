class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& nums1) {
        nums.push_back(nums1);
        sort(nums.begin(),nums.end());
        // ,[](const vector<int>&a,const vector<int>&b){
        // return (a[1]<b[1]||a[1]==b[1]&&a[0]<b[0]);
        // }
        if(nums.size()==0) return {nums1};
        int prevend=nums[0][1];
        int prevstart=nums[0][0];
        vector<vector<int>>ans;

    for(int i=1;i<nums.size();i++){
        if(nums[i][1]<=prevend) continue;
       else if(nums[i][0]<=prevend) prevend=nums[i][1];
       else{
          ans.push_back({prevstart,prevend});
          prevstart=nums[i][0];
          prevend=nums[i][1];
       }
    }
    ans.push_back({prevstart,prevend});
    return ans;
    }
};