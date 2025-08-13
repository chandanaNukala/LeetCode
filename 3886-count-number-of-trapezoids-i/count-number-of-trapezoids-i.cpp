class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long>map;
        int MOD=1000000007;
        for(auto& p:points){
            map[p[1]]++;
        }

        long long res=0,total_lines=0;
        for(auto& y:map){
            long long lines=y.second*(y.second-1)/2;
            res= (res+total_lines*lines)%MOD;
            total_lines=(total_lines+lines)%MOD;
        }
        return (int)res;

    }
};