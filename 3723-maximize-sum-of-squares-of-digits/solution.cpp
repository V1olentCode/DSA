// 13 ms | 47.9 MB
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int count_9=0;
        int max_sum=num*9;
        if(sum>max_sum || sum==0) return "";
        while(sum>=9) {
            sum-=9;
            count_9++;
        }
        int i=0;
        string ans(num,'0');
        while(i<count_9) {
            ans[i]='9';
            i++;
        }
        if(sum>0) {
            ans[i]=char(sum + '0');
        }
        return ans;
    }
};