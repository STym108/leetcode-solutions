class Solution {
public:
    string removeKdigits(string num, int k) {
    stack<int>st;
    for(int i=0;i<num.size();i++){
    int val=num[i]-'0';
    while(st.size()&&st.top()>val&&k>0){
    st.pop();k--;
    }
    if(st.size()==0&&val==0) continue;
   st.push(val);
    }
    while(k>0&&st.size()){k--;st.pop(); }
    string ans="";

    while(st.size()){
    ans+=to_string(st.top());st.pop();
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()==0) return "0";
return ans;
    }
};