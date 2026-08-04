class Solution {
public:

int getans(string &s,int i,string&t,int j, vector<vector<int>>&dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int take=0;

    if(s[i]==t[j]) take= getans(s,i-1,t,j-1,dp);
   int skip= getans(s,i-1,t,j,dp);
   return dp[i][j]= take+skip;
}

    int numDistinct(string s, string t) {
    if(s.size()<t.size()) return 0;
    vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
    
    return getans(s,s.size()-1,t,t.size()-1,dp);

    }
};