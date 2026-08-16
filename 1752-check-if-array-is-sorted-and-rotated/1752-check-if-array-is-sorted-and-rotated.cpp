class Solution {
public:
    bool check(vector<int>& nums) {
    int n=nums.size();
    int i=0;
    while(i<n){
    if(i+1<n&&nums[i]>nums[i+1]) break;
    i++;
    }

    if(i==n) i--;
    
    int x=i+1;
    int y=i-1;
    while(x+1<n){
        if(nums[x]>nums[x+1])return false;
        x++;
    }
    while(y-1>=0){
    if(nums[y]<nums[y-1]) return false;
    y--;
    }
    if(nums[i]<nums[n-1]) return false;
    if(nums[i]<nums[0]) return false;
    if(i!=n-1&&nums[0]<nums[n-1]) return false;
return true;

    }
};