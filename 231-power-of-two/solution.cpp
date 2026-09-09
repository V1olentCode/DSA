// 0 ms | 7.9 MB
class Solution {
public:
    bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
};