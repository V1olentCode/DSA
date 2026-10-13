// 181 ms | 212 MB
class Solution {
public:
    #define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<ll> pq;
        for(auto c:nums) {
            pq.push(abs(c));
        }
        ll n=nums.size();
        ll count,ans=0;
        if(n&1) {
            count=(n+1)/2;
        }
        else {
            count=n/2;
        }
        ll j=0;
        for(int i=0;i<n;i++) {
            ll t=pq.top();
            pq.pop();
            if(j<count) {
                ans+=t*t;
            }
            else{
                ans-=t*t;
            }
            j++;
        }
        return ans;
    }
};