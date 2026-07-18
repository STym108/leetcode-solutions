class Solution {
public:
    string countAndSay(int n) {
    unordered_map<int,string>mpp; 
    int i=2;
    mpp[1]="1";

    while(i<=n){
    unordered_map<char,int>mp;
    string str=mpp[i-1];
    int j=1;
    char ch=str[0];
    mp[ch]++;
    string nstr="";
    while(j<str.size()){
    if(ch!=str[j]){
     nstr+=to_string(mp[ch]);
     nstr+=ch;
     mp.erase(ch);
     ch=str[j];
     mp[ch]++;
    }
    else mp[ch]++;
    j++;
    }
    nstr+=to_string(mp[ch]);
    nstr+=ch;
    mpp[i]=nstr;
    
    mp.erase(ch);
     i++;
    }
    return mpp[n];
    }
};