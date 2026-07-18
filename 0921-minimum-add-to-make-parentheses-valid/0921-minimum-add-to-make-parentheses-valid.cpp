class Solution {
public:
    int minAddToMakeValid(string s) {
    stack<char>st;
    int count=0;
    for(int i=0;i<s.size();i++){
    if(s[i]=='(') st.push('(');
    else{
        if(st.size()>0) st.pop();
        else count++;
    }
    }
    return st.size()+count;
    }
};