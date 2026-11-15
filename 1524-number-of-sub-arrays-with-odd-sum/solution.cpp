// 27 ms | 127.4 MB
#define ll long long
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> pref(n,0);
        for(int i=0;i<n;i++) {
            if(i>=1) {
                pref[i]=pref[i-1]+arr[i];
            }
            else {
                pref[i]=arr[i];
            }
            
        }
        vector<int> oddNo(n,0),evenNo(n,0);
        if(pref[0]%2!=0) oddNo[0]=1;
        else evenNo[0]=1;
        for(int i=1;i<n;i++) {
            oddNo[i]=oddNo[i-1];
            evenNo[i]+=evenNo[i-1];
            if(pref[i]%2!=0) oddNo[i]++;
            else evenNo[i]++;
        }
        ll ans=0;
        for(int i=0;i<n;i++) {
            if(pref[i]%2==0) ans+=oddNo[i];
            else ans+=evenNo[i]+1;
        }
        return ans%1000000007;
    }
};