class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    list<int>lt;

    int r=0;
    while(r<k){
    while(lt.size()&&nums[r]>=nums[lt.back()]){
      lt.pop_back();
    }
    lt.push_back(r);
    r++;
    }
    r--;

    vector<int>ans;
    ans.push_back(nums[lt.front()]);

    while(r<nums.size()){
        r++;
        if(r>=nums.size()) return ans;
        while(r-k>=lt.front()&&lt.size()>0) lt.pop_front();
        while(lt.size()&&nums[lt.back()]<=nums[r]) lt.pop_back();
        lt.push_back(r);
        ans.push_back(nums[lt.front()]);
    }
    return ans;
    }
};