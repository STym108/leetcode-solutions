class Solution {
public:
bool getans(string &str,int idx,unordered_set<string>&st,vector<int>&dp){
    if(idx>=str.size()) return true;
    if(dp[idx]!=-1) return dp[idx];
    bool final=false;

    string s="";
    for(int i=idx;i<str.size();i++){
    s+=str[i];
    if(st.find(s)!=st.end()){
    final=final||getans(str,i+1,st,dp);
    }

    }
    return dp[idx]= final;
}
    bool wordBreak(string s, vector<string>& dict) {
    unordered_set<string>st;
    for(auto str:dict) st.insert(str);
    vector<int>dp(s.size()+1,-1);
    return getans(s,0,st,dp);
    
    }
};