// 586 ms | 287.3 MB
class Solution {
public:
    #define ll long long
    //KMP Algorithm
    bool rotated(vector<int>& a,vector<int>& b) {
        int k=a.size();
        vector<int> lps(k,0);
        for(int i=1,len=0;i<k;) {
            if(b[i]==b[len]) {
                lps[i++]=++len;
            }else if(len>0) {
                len=lps[len-1];
            }else {
                lps[i++]=0;
            }
        }
        for(int i=0,j=0;i<2*k-1;) {
            int x=a[i%k];
            if(x==b[j]) {
                i++;
                j++;
                if(j==k) return true;
            }
            else if(j>0) {
                j=lps[j-1];
            }
            else {
                i++;
            }
        }
        return false;
    }

    long long sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> s=nums,a,b;
        sort(s.begin(),s.end());
        ll ans=0;
        for(int k=1;k<=n;k++) {
            if(n%k!=0) continue;
            bool isValid=true;
            for(int i=0;i<n;i+=k) {
                a.assign(nums.begin()+i,nums.begin()+i+k);
                b.assign(s.begin()+i,s.begin()+i+k);
                if(!rotated(a,b)) {
                    isValid=false;
                    break;
                }
            }
            if(isValid) {
                ans+=k;
            }
        }
        return ans;
    }
};