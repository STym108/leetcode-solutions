class Solution {
public:
    string reverseWords(string s) {
    reverse(s.begin(),s.end());
    int i=0;
    int l=0;int r=0;
    while(i<s.size()){
        while(i<s.size()&&s[i]!=' ') s[r++]=s[i++];
       if(l<r) {  s[r]=' ';
        //reverse from l to r-1
        // for(int j=l;j<l+x/2;j++) swap(s[j],s[l+x-j-1]);
        reverse(s.begin()+l,s.begin()+r);
        r++;
        l=r;
}
      i++;
    }
    return s.substr(0,r-1);
    }
};