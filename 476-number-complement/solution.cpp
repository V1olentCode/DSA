// 0 ms | 7.8 MB
class Solution {
public:
    int findComplement(int num) {
        int n = num;
        for(int i=0;i<31 && (1 << i) <= num;i++) {
            n = n ^ (1 << i);
        }
        return n;
    }
};