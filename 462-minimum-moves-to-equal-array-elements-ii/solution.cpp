// 1 ms | 15.6 MB
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];
        int ans=0;
        for (int x:nums) {
            ans+=abs(x-median);
        }
        return ans;
    }
};