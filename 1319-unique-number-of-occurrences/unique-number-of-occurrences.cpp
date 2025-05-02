class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        unordered_set<int>set;
        for(auto it:map){
            set.insert(it.second);
        }
        return map.size()==set.size();
    }
};