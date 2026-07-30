class Solution {
public:
    bool search(vector<int>& nums, int t) {
    int lo=0;
    int hi=nums.size()-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]==t) return true;
        if(nums[mid]==nums[lo]&&nums[hi]==nums[mid]){lo++;hi--;}
        else if(nums[mid]>=nums[lo]){
            if(t>=nums[lo]&&t<nums[mid]) hi=mid-1;
            else lo=mid+1;
        }
        else if(nums[mid]<=nums[hi]){
          if(t<=nums[hi]&&t>nums[mid]) lo=mid+1;
          else hi=mid-1;
        }
    }
    return false;
    }
};