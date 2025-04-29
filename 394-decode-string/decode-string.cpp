class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        int digit=0;
        string ans;
        string result = "";
        for(int i=0;i<s.length();i++){
            if(s[i]!=']'){
                st.push(string(1, s[i]));
            }
            else{
                string sub="";
                while(st.top()!="["){
                    sub+=st.top();
                    st.pop();
                }
                st.pop();
                string num_str="";
                
                while(!st.empty() && isdigit(st.top()[0])){
                    num_str+=st.top();
                     st.pop();

                }
                reverse(num_str.begin(),num_str.end());
                
                int num=stoi(num_str);
                for(int j=0;j<num;j++){
                    st.push(sub);
                }

            }

        }
         while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};