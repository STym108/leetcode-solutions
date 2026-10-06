class Solution {
public:
void makeans(string &str){

     int pivot=-1;
     for(int i=str.size()-1;i>=1;i--){
     int curr=str[i]-'0';
     int prev=str[i-1]-'0';
     if(curr>prev){pivot=i-1;break; }
     }
     if(pivot==-1){ reverse(str.begin(),str.end()); return;}
     int pele=str[pivot]-'0';
     int i=str.size()-1;
     while(i>pivot){
    int curr=str[i]-'0';
    if(curr>pele){ swap(str[i],str[pivot]); break; }
    i--;
     }
     reverse(str.begin()+pivot+1,str.end());
     return ;

}
    string getPermutation(int n, int k) {
    string str="";
    for(int i=1;i<=n;i++) str+=i+'0';
    for(int i=1;i<k;i++) makeans(str);
    return str;
    }
};

