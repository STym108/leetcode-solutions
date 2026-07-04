class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pele = 0;
        int negele = 0;
        char signflag = 'p';
        vector<int> ans;
        while (negele < nums.size()) {
            if (pele<nums.size()&&signflag == 'p' && nums[pele] > 0) {
                ans.push_back(nums[pele]);
                pele++;
                signflag = 'n';
            } else if (signflag == 'p')
                pele++;
            else if (signflag == 'n' && nums[negele] < 0) {
                ans.push_back(nums[negele]);
                negele++;
                signflag = 'p';
            } else if (signflag == 'n')
                negele++;
            if(ans.size()==nums.size()) return ans;
        }
        return ans;
    }
};