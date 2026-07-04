class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int maj1;
        int maj2;

        for (int i = 0; i < nums.size(); i++) {
               if (count1 == 0&&nums[i]!=maj2) {
                maj1 = nums[i];
                count1++;
            }

            else if (count2 == 0&&nums[i]!=maj1) {
                maj2 = nums[i];
                count2++;
            }
          else  if (maj1 == nums[i])
                count1++;
            else if (maj2 == nums[i])
                count2++;

          else {
                count1--;
                count2--;
            }
        }
        int f1 = 0;
        int f2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maj1)
                f1++;
            if (nums[i] == maj2)
                f2++;
        }
        vector<int> ans;
        if (f1 > (nums.size() / 3))
            ans.push_back(maj1);
        if (f2 > (nums.size() / 3))
            ans.push_back(maj2);
        return ans;
    }
};