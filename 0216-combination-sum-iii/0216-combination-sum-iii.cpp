class Solution {
public:
void getans(int idx,int n,int k,vector<int>temp,vector<vector<int>>&ans){
    if(n==0&&temp.size()==k){
    ans.push_back(temp); return ;
    }
    for(int i=idx;i<=9;i++){
    if(n-i<0||temp.size()==k) return;
       temp.push_back(i);
        getans(i+1,n-i,k,temp,ans);
        temp.pop_back();}
    
}
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>>ans;
    getans(1,n,k,{},ans);
    return ans;
    }
};