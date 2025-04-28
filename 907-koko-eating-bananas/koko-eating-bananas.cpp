class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*std::max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            long long sum=0;
            for(int p:piles){
                sum+=ceil(static_cast<double>(p)/m);
            }
            if(sum>h){
                l=m+1;
            }
            else {
                ans=m;
                r=m-1;
            }
        }
        return ans;
    }
};