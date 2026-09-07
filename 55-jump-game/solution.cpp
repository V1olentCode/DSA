// 935 ms | 53 MB
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[0]=true;
        for(int i{};i<n;i++) {
            int k=1;
            while(k<=nums[i] && i+k<n) {
                dp[i+k]=true&dp[i];
                k++;
            }
        }
        return dp[n-1];
    }
};