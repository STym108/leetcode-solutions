class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int x=0;
    int countx=0;
    int y=0;
    int county=0;
    
    for(int i=0;i<nums.size();i++){
   if(countx>0&&nums[i]==x){
    countx++;
   }
   else if(county>0&&nums[i]==y){
    county++;
   }
   else if(countx==0){
    x=nums[i]; countx++;
   }
   else if(county==0){
    y=nums[i]; county++;
   }
   else {countx--;county--;}

    }
    countx=0;
    county=0;
    for(int i=0;i<nums.size();i++) if(nums[i]==x) countx++;
    for(int i=0;i<nums.size();i++) if(nums[i]==y) county++;
    int n=nums.size();
    vector<int>ans;
    if(countx>n/3) ans.push_back(x);
    if(x==y) return ans ;
     if(county>n/3){  ans.push_back(y);}
     return ans ;
    }
};