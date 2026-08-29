class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k){
    map<string,int>mp;
    if(s==t) return true;
    if(s!=t&&s.size()%k!=0) return false;
    int l=t.size()/k;
    int i=0;
    while(i<s.size()){
    mp[t.substr(i,l)]++;
    i+=l;
    }
    i=0;
    while(i<s.size()){
        string str=s.substr(i,l);
        if(mp[str]<=0) return false;
        else mp[str]--;
        i+=l;
    }
    return true;
    }
};