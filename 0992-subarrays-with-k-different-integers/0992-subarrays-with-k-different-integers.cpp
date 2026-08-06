class Solution {
public:
unordered_map<int,int>mp;

int upto(vector<int>& nums, int k){
    if(k==0) return 0;
    int lo=0;
    int hi=0;
    mp.clear();
    int count=0;
    mp[nums[lo]]++;
    if(k>=1) count++;
    while(hi<nums.size()){
        hi++;
        if(hi>=nums.size()) return count;
        mp[nums[hi]]++;
        while(lo<hi&&mp.size()>k){
        mp[nums[lo]]--;
        if(mp[nums[lo]]==0) mp.erase(nums[lo]);
        lo++;
        }
        count+=hi-lo+1;
    }
    return count;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {

    return upto(nums,k)-upto(nums,k-1);
    
    }
};