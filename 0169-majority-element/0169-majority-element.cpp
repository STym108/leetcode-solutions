class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int count=0;
    int maj;
     maj=nums[0];
        count=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=maj){
            if(count==0){
                maj=nums[i];
                count=1;
            }
            else count--;
        }
        else count++;
    }
    return maj;

    }
};