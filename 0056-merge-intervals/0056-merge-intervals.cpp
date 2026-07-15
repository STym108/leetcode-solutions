class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
    sort(nums.begin(),nums.end(),[](const vector<int>a,const vector<int>b){
    return (a[0]<b[0])||(a[0]==b[0]&&a[1]<b[1]);

    });
    int i=0;
    int prevstart=nums[i][0];
    int prevend=nums[i][1];
    i++;
    vector<vector<int>>ans;
    while(i<nums.size()){
        if(nums[i][0]>prevend){
            ans.push_back({prevstart,prevend});
            prevstart=nums[i][0];
            prevend=nums[i][1];
            i++;
        }
        else if(nums[i][0]<=prevend&&prevend>=nums[i][1])i++;
        else if(nums[i][0]<=prevend){ prevend=nums[i][1];i++;}
    }
    ans.push_back({prevstart,prevend});
    return ans;
    }
};