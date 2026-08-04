class Solution {
public:
    int characterReplacement(string s, int k) {
    unordered_map<char,int>mp;
    int l=0;
    int r=0;
    mp[s[0]]++;
    char mfchar=s[0];
    int maxi=1;
    while(l<=r){
    r++;
    if(r>=s.size()) return maxi;
    mp[s[r]]++;
    int x=0;
    for(auto p:mp) if(x<p.second){x=p.second;mfchar=p.first;}
    while(r-l+1-mp[mfchar]>k){
    mp[s[l]]--;
    l++;
    x=0;
    for(auto p:mp) if(x<p.second){x=p.second;mfchar=p.first;}
    }
    maxi=max(r-l+1,maxi);
    }
    return maxi;

    }
};