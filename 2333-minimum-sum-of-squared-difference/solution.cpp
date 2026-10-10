// 15 ms | 121.5 MB
class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int> diff(n);
        int maxDiff=0;
        ll total=0;
        ll k=(ll)k1+k2;
        for(int i=0;i<n;i++) {
            diff[i]=abs(nums1[i]-nums2[i]);
            total+=diff[i];
            maxDiff=max(maxDiff,diff[i]);
        }
        if(total<=k) return 0;
        int l=0,e=maxDiff;
        while(l<e) {
            int mid=l+(e-l)/2;
            ll steps=0;
            for(auto c:diff) {
                steps+=max(c-mid,0);
            }
            if(steps<=k) {
                e=mid;
            }
            else {
                l=mid+1;
            }
        }
        for(int i=0;i<n;i++) {
            k-=max(diff[i]-l,0);
            diff[i]=min(diff[i],l);
        }

        for(int i=0;i<n && k>0;i++) {
            if(diff[i]==l) {
                diff[i]--;
                k--;
            }
        }
        ll ans = 0;

        for(int d:diff) {
            ans+=1LL*d*d;
        }
        return ans;
    }
};