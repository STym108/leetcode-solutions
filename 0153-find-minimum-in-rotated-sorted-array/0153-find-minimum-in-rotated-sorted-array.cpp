class Solution {
public:
    int findMin(vector<int>& nums) {
    int n=nums.size();
    int lo=0;
    int hi=n-1;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(lo==hi) return nums[lo];
        if(nums[mid]<nums[hi])hi=mid;
        else  lo=mid+1;
    }
    return nums[lo];

    }
};