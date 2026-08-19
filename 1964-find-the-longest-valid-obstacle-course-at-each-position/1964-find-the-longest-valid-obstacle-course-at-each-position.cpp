class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
    vector<int>v;
    v.push_back(nums[0]);
    int n=nums.size();
    vector<int>ans(n,0);
    ans[0]=1;
    for(int i=1;i<n;i++){
    int lo=0;
    int hi=v.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]>nums[i]) hi=mid-1;
        else lo=mid+1;
    }
    if(lo==v.size()) v.push_back(nums[i]);
    else{
        v[lo]=nums[i];
    }
    ans[i]=lo+1;
    }
    return ans;
        
    }
};