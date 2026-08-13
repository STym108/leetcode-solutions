class Solution {
public:
void getans(int idx,int n,int prev,vector<string>&ans,string &temp){
if(idx==n){
    ans.push_back(temp); return;
}
if(prev==1||prev==-1){
    temp+="0";
    getans(idx+1,n,0,ans,temp);
    temp.pop_back();
}
 temp+="1";
    getans(idx+1,n,1,ans,temp);
    temp.pop_back();
}
    vector<string> validStrings(int n) {
    string temp="";
    vector<string>ans;
    getans(0,n,-1,ans,temp);

    return ans;
    }
};