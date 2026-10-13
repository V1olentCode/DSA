// 0 ms | 9 MB
class Solution {
public:
    #define ll long long
    int myAtoi(string s) {
        int i=0,n=s.length();
        while(i<n && s[i]==' ') {
            i++;
        }
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')) {
            if(s[i]=='-') sign=-1;
            i++;
        }
        ll num=0;
        while(i<n && (s[i]>='0' && s[i]<='9')) {
            int d=s[i]-'0';
            num=num*10+d;
            if(sign==1 && num>(long long)INT_MAX) {
                return INT_MAX;
            }
            if(sign==-1 && -num<(long long)INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return sign*num;
    }
};