class Solution {
public:
    bool validateStackSequences(vector<int>& num1, vector<int>& num2) {
    if(num1.size()!=num2.size()) return false;
    
    stack<int>st;

    int i=0;
    int j=0;
    while(j<num2.size()){
    if(st.size()&&st.top()==num2[j]){ st.pop();j++; }
    else{ while(i<num1.size()&&num1[i]!=num2[j]) st.push(num1[i++]);
    if(i<num1.size()&&num1[i]==num2[j]) st.push(num1[i++]);
    }
        if(st.size()>0&&st.top()!=num2[j]&&i>=num1.size()) return false;

    }

    if(st.size()>0) return false;
    return true;

    }
};