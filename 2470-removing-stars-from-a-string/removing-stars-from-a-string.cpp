class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        while(!st.empty()){
           ans+=st.top();
           st.pop(); 
        }
        int n=ans.length();
         for (int i = 0; i < n / 2; i++) {
            swap(ans[i], ans[n - i - 1]);
        }
        return ans;
    }
};