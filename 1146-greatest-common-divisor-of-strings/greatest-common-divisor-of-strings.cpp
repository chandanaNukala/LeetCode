class Solution {
public:
    bool isValid(string str1, string str2,int k,string base){
        int l1=str1.length();
        int l2=str2.length();
        if(l1%k!=0 || l2%k!=0)return false;
        else{
            int f1=l1/k;
            int f2=l2/k;
            string ans1="";
            string ans2="";
            for(int i=0;i<f1;i++){
                ans1+=base;
            }
            for(int i=0;i<f2;i++){
                ans2+=base;
            }
            return str1==ans1 && str2==ans2;
        }
        return false;
        
    }
    string gcdOfStrings(string str1, string str2) {
        int len1=str1.length();
        int len2=str2.length();
        for(int i=min(len1,len2);i>=1;i--){
            string base=str1.substr(0,i);
            if (isValid(str1,str2,i,base)){
                return base;
            }
        }
        return "";
    }
};