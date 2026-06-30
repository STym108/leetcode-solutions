class Solution {
public:
typedef long long int ll;
    int reversePairs(vector<int>& nums) {
    vector<ll>v;
    ll count=0;
    for(int i=0;i<nums.size();i++){

         //binary search to find the first ele , s.t : ele>2*nums[i]
    if(v.size()>0){ll lo=0;
    ll hi=v.size()-1;
    while(lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(v[mid]>(ll)2*nums[i]) hi=mid-1;
        else lo=mid+1;
    }
    count+=v.size()-lo;}

            //add in v and make array sorted
        if(v.size()==0) v.push_back(nums[i]);
        else{
            ll lo=0;
            ll hi=v.size()-1;
            while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
              if(v[mid]<=nums[i]) lo=mid+1;
              else hi=mid-1;
            }
            if(lo>=v.size()) v.push_back(nums[i]);
            else if(hi<0) v.insert(v.begin()+0,nums[i]);
            else v.insert(v.begin()+lo,nums[i]);

        }

    }
    return count;
   
    }
};
// [-185,-102,-314,252,-4,-315] // if you are stuck at test case 98
// [0]
// [1,2]
// [2147483647,2147483647,2147483647,2147483647,2147483647,2147483647]
// [-5,-5]
// [2147483647,-2147483648]