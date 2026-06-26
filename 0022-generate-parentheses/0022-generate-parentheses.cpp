class Solution {
public:
void getans(stack<char> st,string str,int stpushed,int n,vector<string>&ans){
    if(stpushed>n) return;
    else if(!st.size()&&stpushed==n&&str.size()==2*n) ans.push_back(str);
    if(st.size()){
        st.push('('); stpushed++;
        str+='(';
        getans(st,str,stpushed,n,ans);
        st.pop();stpushed--; str.pop_back();
        st.pop();
        str+=")";
        getans(st,str,stpushed,n,ans);
    }
    else{
        st.push('(');stpushed++; str+='(';
        getans(st,str,stpushed,n,ans);
        st.pop();stpushed--;
    }
}

    vector<string> generateParenthesis(int n) {
    vector<string>ans;
    string str="";
    int count=0;
    stack<char>st;
    getans(st,str,count,n,ans);
    return ans;
    }
};