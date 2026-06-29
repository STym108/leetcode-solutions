class Solution {
public:
typedef long long int ll;
void getans(string &nums,ll idx,ll currval,string currstring,ll target,vector<string>&ans,int prev){
    if(idx==nums.size()&&currval==target){ ans.push_back(currstring);return ;}
    
    else if(idx>=nums.size()) return;
    ll sofarval=0;
    string sofarstr="";
    for(ll i=idx;i<nums.size();i++){

       sofarval= sofarval*10+(nums[i]-'0');
       sofarstr+=nums[i];
       if(i > idx && nums[idx] == '0') break;
         if (currstring.empty()) {

                getans(nums, i + 1, sofarval, sofarstr,

                       target, ans, sofarval);

                continue;

            }
      //addition
       currval=currval+sofarval;
       string tempstr=currstring;
     if(tempstr.size()>0)  tempstr+="+"; tempstr+=sofarstr;
       getans(nums,i+1,currval,tempstr,target,ans,sofarval);
       currval-=sofarval;
    
       //substraction
      currval=currval-sofarval;
      tempstr=currstring;
    if(tempstr.size()>0) tempstr+="-"; tempstr+=sofarstr;
       getans(nums,i+1,currval,tempstr,target,ans,-sofarval);
       currval+=sofarval;
    //multiplication

 ll x=currval-prev+sofarval*prev;

    tempstr=currstring;
   if(tempstr.size()>0)  tempstr+="*"; tempstr+=sofarstr;
       getans(nums,i+1,x,tempstr,target,ans,prev*sofarval);
    }
}

    vector<string> addOperators(string num, int target) {
     vector<string>ans;
     getans(num,0,0,"",target,ans,0);
 return ans;

    
    }
};

// "num =
// "9999999999"
// target =
// 1409865409

// Use Testcase
// Output
// ["99999*99999"]
// Expected
// []"