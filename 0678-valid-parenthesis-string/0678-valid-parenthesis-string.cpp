class Solution {
public:
    bool checkValidString(string s) {
    stack<int>st1;
    stack<int>st2;
    for(int i=0;i<s.size();i++){
    if(s[i]=='(') st1.push(i);
    else if(s[i]=='*') st2.push(i);
    else{
        if(st1.size()>0) st1.pop();
        else if(st2.size()>0) st2.pop();
        else return false;
    }
    }
    if(st1.size()==0) return true;
    while(st2.size()&&st1.size()){
    if(st2.top()>st1.top()){ st1.pop();st2.pop();}
    else return false;
    }
    if(st1.size()>0) return false;
    return true;

    }
};