// 0 ms | 32 MB
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min=*min_element(nums.begin(),nums.end());

        int ans=0;
        for(auto c:nums) {
            if(c==min) continue;
            ans+=(c-min);
        }
        return ans;
    }
};