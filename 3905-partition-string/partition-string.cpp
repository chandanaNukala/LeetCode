#include <algorithm> 
class Solution {
public:
    vector<string> partitionString(string s) {
        // vector<string>ans;
        // unordered_map<string,int>map;
        // string temp="";
        // for(int i=0;i<s.length();i++){
        //     temp+=s[i];
        //     if(map[temp]==0){
        //         ans.push_back(temp);
        //         map[temp]++;
        //         temp="";
        //     }
        // }
        // return ans;
        vector<string>ans;
        unordered_set<string>set;
        string temp="";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            if(set.find(temp)==set.end()){
                ans.push_back(temp);
                set.insert(temp);
                temp="";
            }
        }
        return ans;
    }
};