class Solution {
public:
    bool validateStackSequences(vector<int>& ps, vector<int>& pp) {
    stack<int>st;
    int i=0;
 
    
    for(int j=0;j<pp.size();j++){

         if(st.size()&&st.top()!=pp[j]&&i>=ps.size()) return false;

         if(!st.size()||st.top()!=pp[j])  {
             while(i<ps.size()&&pp[j]!=ps[i]){
                st.push(ps[i]);i++;
            }
            if(i>=ps.size()) return false;
            st.push(ps[i]);i++;
            }

            if(st.size()&&st.top()==pp[j]){ st.pop();}
    }
    if(st.size()>0) return false;
    return true;
    }
};
