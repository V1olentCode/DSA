// 16 ms | 211.9 MB
class Solution {
public:
    #define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        vector<ll> pq;
        for(auto c:nums) {
            pq.push_back(abs((ll)(c)));
        }
        ll n=nums.size();
        int k = (n + 1) / 2;
        ll ans=0;
        nth_element(pq.begin(),pq.begin()+k,pq.end(),greater<ll>());
        for(int i=0;i<n;i++) {
            if(i<k) {
                ans+=pq[i]*pq[i];
            }
            else {
                ans-=pq[i]*pq[i];
            }
        }
        return ans;
    }
};