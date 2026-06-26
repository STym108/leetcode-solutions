class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
    int r=s1.size();
    int c=s2.size();
    vector<vector<int>>dp(r+1,vector<int>(c+1,0));
    for(int i=1;i<r+1;i++){
        for(int j=1;j<c+1;j++){
        if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        }
    }
    return dp[r][c];
    }
};