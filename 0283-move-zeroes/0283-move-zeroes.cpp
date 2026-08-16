class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int zcount=0;
    for(auto ele:nums) if(ele==0) zcount++;
    int i=0;
    int x=i;
    int n=nums.size();
    int j=n-zcount;
    while(x<n){
    if(nums[x]!=0){nums[i]=nums[x];x++;i++; }
    else x++;
    }
    while(j<n) nums[j++]=0;
    }
};