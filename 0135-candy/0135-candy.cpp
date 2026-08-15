class Solution {
public:
    int candy(vector<int>& nums) {
      int n=nums.size();
      vector<int>v(n,1);
    for(int i=1;i<n;i++){
    if(nums[i]>nums[i-1]) v[i]=v[i-1]+1;
    }
    for(int i=n-2;i>=0;i--){
        if(nums[i]>nums[i+1]&&v[i]<=v[i+1]) v[i]=v[i+1]+1;
    }
    int sum=0;
    for(int i=0;i<n;i++) sum+=v[i];
    return sum;
    }
};