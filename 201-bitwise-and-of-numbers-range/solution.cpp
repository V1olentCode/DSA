// 0 ms | 11.2 MB
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c1=0,c2=0;
        int l=left,r=right;
        while(l>0 || r>0) {
            if(l>0) {
                l>>=1;
                c1++;
            }
            if(r>0) {
                r>>=1;
                c2++;
            }
        }
        //case 1 - no of bits of left and right are different then ans is 0
        if(c1!=c2) {
            return 0;
        }
        //case 2 - no of bits are same then we find common prefix
        else {
            int l2=left,r2=right,c3=0;
            while(l2!=r2) {
                l2>>=1;
                r2>>=1;
                c3++;
            }
            for(int i=0;i<c3;i++) {
                l2<<=1;
            }
            return l2;
        }
    }
};