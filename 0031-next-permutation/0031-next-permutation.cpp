class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     bool flag=false;
     int pivot=INT_MAX;
     for(int i=nums.size()-1;i>0;i--){
        if(nums[i]>nums[i-1]){pivot=i-1;flag=true; break;}
     }
     if(!flag&&pivot==INT_MAX) return reverse(nums.begin(),nums.end());
     int i=nums.size()-1;
     while(i>pivot){
        if(nums[i]>nums[pivot]){ swap(nums[i],nums[pivot]); break;}
        i--;
     }
     reverse(nums.begin()+pivot+1,nums.end());

    }
};