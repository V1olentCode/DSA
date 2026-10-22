// 6 ms | 141.4 MB
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int k=find(nums.begin(),nums.end(),0)-nums.begin();
        bool check=true;
        for(int i=0;i<n;i++) {
            if(nums[(k+i)%n]!=i) {
                check=false;
                break;
            }
        }
        if(check) {
            ans=min(ans,min(k,(n-k)%n+2));
        }
        check=true;
        k=find(nums.begin(),nums.end(),n-1)-nums.begin();
        for(int i=0;i<n;i++) {
            if (nums[(k+i)%n]!=n-1-i) {
                check=false;
                break; 
            }
        }
        if(check) {
            ans=min(ans,min(k+1,(n-k)%n+1));
        }
        return ans==INT_MAX?-1:ans;
    }
};