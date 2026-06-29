class Solution {
public:
typedef long long int ll;
int getans(string &str,int i,string &t,int j){
    if(j>=t.size()) return 1;
    else if(i>=str.size()) return 0;
    int same=0;
    if(str[i]==t[j]) same=getans(str,i+1,t,j+1);
    int skip=getans(str,i+1,t,j);
    return same+skip;
}
    int numDistinct(string s, string t) {
    // return getans(s,0,t,0);
    int r=s.size();
    int c=t.size();

    vector<ll>prev(c+1,0);
    prev[0]=1;
    for(int i=1;i<r+1;i++){
        vector<ll>curr(c+1,0);
        for(int j=0;j<c+1;j++){
        int x=0;
       if(j!=0) {if(s[i-1]==t[j-1]) x=prev[j-1];}
        curr[j]=prev[j]+x;
        }
        prev=curr;
    }

    return prev[c];

    }
};