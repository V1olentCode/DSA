// 0 ms | 15.7 MB
class Solution {
public:
    int minInsertions(string s) {
        int value=0;
        int ans=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') {
                if(value%2==1) {
                    ans++;
                    value--;
                }
                value+=2;
            } 
            else if(s[i]==')') 
                value-=1;
            if(value<0) {
                ans++;
                value=1;
            }
        }
        ans+=value;
        return ans;
    }
};