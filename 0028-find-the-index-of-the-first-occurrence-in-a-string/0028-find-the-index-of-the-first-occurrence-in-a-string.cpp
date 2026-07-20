class Solution {
public:
    int strStr(string str1, string str2) {
        int n=str2.size();
        vector<int>lps(n,0);
    for(int i=1;i<n;i++){
    int len=lps[i-1];
    while(len>0&&str2[len]!=str2[i]) len=lps[len-1];
    if(str2[len]==str2[i]) len++;
    lps[i]=len;
    }
    int j=0;
    int i=0;
    while(i<str1.size()){
    while(i<str1.size()&&j<str2.size()&&str1[i]==str2[j]){i++;j++;}
    if(j==str2.size()) return i-n;
    else if(j>0) j=lps[j-1];
    else if(j==0)i++;
    }
    return -1;
    }
};