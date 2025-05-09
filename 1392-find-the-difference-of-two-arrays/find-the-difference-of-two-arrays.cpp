class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>vec;

        unordered_set<int>set1;
        for(int i=0;i<nums1.size();i++){
            set1.insert(nums1[i]);
        }

        for(int i=0;i<nums2.size();i++){
            if(set1.find(nums2[i])!=set1.end()){
                set1.erase(nums2[i]);
            }
        }

        vector<int>ans;
        for(int val:set1){
            ans.push_back(val);
        }
        vec.push_back(ans);

        
        unordered_set<int>set2;
        for(int i=0;i<nums2.size();i++){
            set2.insert(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            if(set2.find(nums1[i])!=set2.end()){
                set2.erase(nums1[i]);
            }
        }

        vector<int>ans1;
        for(int val:set2){
            ans1.push_back(val);
        }
        vec.push_back(ans1);






        // unordered_map<int,int>map1;
        // for(int i=0;i<nums1.size();i++){
        //    map1[nums1[i]]++;
        // }
        // for(int i=0;i<nums2.size();i++){
        //     if(map1.find(nums2[i])!=map1.end()){
        //         map1[nums2[i]]--;
        //     }
        // }
        // vector<int>ans;
        // for(auto it:map1){
        //     if(it.second!=0){
        //         ans.push_back(it.first);
        //     }
        // }
        // sort(ans.begin(),ans.end());
        // vec.push_back(ans);




        //  unordered_map<int,int>map2;
        // for(int i=0;i<nums2.size();i++){
        //    map1[nums2[i]]++;
        // }
        // for(int i=0;i<nums1.size();i++){
        //     if(map2.find(nums1[i])!=map2.end()){
        //         map2[nums1[i]]--;
        //     }
        // }
        // vector<int>ans1;
        // for(auto it:map2){
        //     if(it.second!=0){
        //         ans1.push_back(it.first);
        //     }
        // }
        // vec.push_back(ans1);

        return vec;

    }
};