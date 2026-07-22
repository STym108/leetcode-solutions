class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
    vector<int>v;
    int i=0;

    while(i<s.size()){
    if(s[i]=='0'){
        int j=i;
        int count=0;
        while(j<s.size()&&s[j]!='1'){count++;j++;}
        v.push_back(count);
        i=j;
    }
    else i++;
    }
    int x=0;
    int maxp=0;
    for(int i=0;i<s.size();i++) if(s[i]=='1') x++;
   if(v.size()>0) {for(int i=0;i<v.size()-1;i++){
    maxp=max(maxp,v[i]+v[i+1]);
    }}
return x+maxp;
    }
};