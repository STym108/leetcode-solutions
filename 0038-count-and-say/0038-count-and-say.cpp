class Solution {
public:
string rle(string str){
    string ans="";
int i=0;int count=0;char s;
while(i<str.size()){
    s=str[i];
    count=0;
    while(i<str.size()&&str[i]==s){
        count++;i++;
    }
ans+=to_string(count);
ans+=s;
}
return ans;
}
    string countAndSay(int n) {
    if(n==1) return "1";
    int i=2;
    string str="1";
    while(i<=n){
      str=rle(str);
       i++;
    }
    return str;
    }
};