// 0 ms | 7.9 MB
class Solution {
public:
    bool power(int n,long long cp){
        if(cp==n)
        return true;
        else if(cp>n || cp<=0)
        return false;
        
        return power(n,cp*2);
    }


    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        return power(n,1);
    }
};