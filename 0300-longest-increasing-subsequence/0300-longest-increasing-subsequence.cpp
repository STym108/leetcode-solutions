class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    vector<int>v;
    for(int i=0;i<nums.size();i++){
    int lo=0;
    int hi=v.size()-1;
    bool gotit=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]==nums[i]){ gotit=true; break;}
        if(v[mid]<nums[i]) lo=mid+1;
        else hi=mid-1;
    }
   if(!gotit) {
    if(lo>=v.size()) v.push_back(nums[i]);
    else if(hi<0) v[0]=nums[i];
    else v[lo]=nums[i];
    }
    }
    return v.size();

    }
};