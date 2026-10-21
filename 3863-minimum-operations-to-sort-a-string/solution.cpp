// 12 ms | 27.6 MB
class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        if(is_sorted(s.begin(),s.end())) return 0;
        if(n==2) return -1;
        char min=*min_element(s.begin(),s.end());
        char max=*max_element(s.begin(),s.end());
        if(s[0]==min || s[n-1]==max) return 1;
        if(s[0]==max && s[n-1]==min 
           && count(s.begin(),s.end(),max)==1
           && count(s.begin(),s.end(),min)==1)
             return 3;
        return 2;
    }
};